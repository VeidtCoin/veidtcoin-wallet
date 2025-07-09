#ifndef VEIDTCOIN_WALLETCLI_H
#define VEIDTCOIN_WALLETCLI_H

#include <string>

class WalletCLI {
public:
    void start();
    void createWallet();
    void loadWallet(const std::string& seed);
    void showAddress() const;

private:
    std::string currentSeed;
    std::string address;
    bool walletLoaded = false;
};

#endif
