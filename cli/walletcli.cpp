#include "walletcli.h"
#include "../keys/walletkeys.h"
#include "../util/logger.h"
#include <iostream>

void WalletCLI::start() {
    Logger::info("Welcome to VeidtCoin CLI Wallet");
    Logger::divider();

    std::string command;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, command);

        if (command == "create") {
            createWallet();
        } else if (command.rfind("load ", 0) == 0) {
            loadWallet(command.substr(5));
        } else if (command == "address") {
            showAddress();
        } else if (command == "exit") {
            Logger::info("Goodbye.");
            break;
        } else {
            Logger::warn("Unknown command. Use: create | load <seed> | address | exit");
        }
    }
}

void WalletCLI::createWallet() {
    WalletKeys wallet;
    currentSeed = wallet.generateSeed();
    wallet.setFromSeed(currentSeed);
    address = wallet.getPublicAddress();
    walletLoaded = true;

    Logger::info("✅ New wallet created.");
    Logger::info("🧬 Seed: " + currentSeed);
    Logger::info("📮 Address: " + address);
}

void WalletCLI::loadWallet(const std::string& seed) {
    WalletKeys wallet;
    wallet.setFromSeed(seed);
    currentSeed = seed;
    address = wallet.getPublicAddress();
    walletLoaded = true;

    Logger::info("🔑 Wallet loaded from seed.");
    Logger::info("📮 Address: " + address);
}

void WalletCLI::showAddress() const {
    if (!walletLoaded) {
        Logger::warn("⚠️ No wallet loaded.");
        return;
    }
    Logger::info("📮 Address: " + address);
}
