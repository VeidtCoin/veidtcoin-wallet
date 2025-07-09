#include "walletrpc.h"
#include <curl/curl.h>
#include <sstream>

using json = nlohmann::json;

WalletRPC::WalletRPC(const std::string& nodeURL)
    : endpoint(nodeURL) {}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

json WalletRPC::post(const std::string& method, const json& params) {
    CURL* curl = curl_easy_init();
    if (!curl) return {{"error", "Failed to init CURL"}};

    json req;
    req["jsonrpc"] = "2.0";
    req["id"] = 1;
    req["method"] = method;
    req["params"] = params;

    std::string requestData = req.dump();
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestData.size());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    try {
        return json::parse(response);
    } catch (...) {
        return {{"error", "Failed to parse JSON response"}};
    }
}

json WalletRPC::getBlockHeight() {
    return post("getblockcount", {});
}

json WalletRPC::broadcastTransaction(const std::string& txData) {
    return post("sendrawtransaction", {{"tx", txData}});
}

json WalletRPC::getBalance(const std::string& address) {
    return post("getbalance", {{"address", address}});
}
