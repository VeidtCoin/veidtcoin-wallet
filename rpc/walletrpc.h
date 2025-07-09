#ifndef VEIDTCOIN_WALLETRPC_H
#define VEIDTCOIN_WALLETRPC_H

#include <string>
#include <nlohmann/json.hpp>

class WalletRPC {
public:
    explicit WalletRPC(const std::string& nodeURL);
    
    nlohmann::json getBlockHeight();
    nlohmann::json broadcastTransaction(const std::string& txData);
    nlohmann::json getBalance(const std::string& address);

private:
    std::string endpoint;

    nlohmann::json post(const std::string& method, const nlohmann::json& params);
};

#endif
