#ifndef VEIDTCOIN_WALLETKEYS_H
#define VEIDTCOIN_WALLETKEYS_H

#include <string>
#include <utility>

class WalletKeys {
public:
    WalletKeys();

    std::string generateSeed();
    std::pair<std::string, std::string> generateKeyPairFromSeed(const std::string& seed);
    std::string getPublicAddress() const;
    void setFromSeed(const std::string& seed);

private:
    std::string privateKey;
    std::string publicKey;
    std::string seed;
};

#endif
