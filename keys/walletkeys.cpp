#include "walletkeys.h"
#include "../util/hasher.h"
#include "../crypto/crypto.h"

WalletKeys::WalletKeys() {
    seed = generateSeed();
    auto keys = generateKeyPairFromSeed(seed);
    privateKey = keys.first;
    publicKey = keys.second;
}

std::string WalletKeys::generateSeed() {
    return sha256("VDTSEED::" + generate_private_key());
}

std::pair<std::string, std::string> WalletKeys::generateKeyPairFromSeed(const std::string& s) {
    std::string priv = sha256("PRIV::" + s);
    std::string pub = derive_public_key(priv);
    return {priv, pub};
}

void WalletKeys::setFromSeed(const std::string& s) {
    seed = s;
    auto keys = generateKeyPairFromSeed(seed);
    privateKey = keys.first;
    publicKey = keys.second;
}

std::string WalletKeys::getPublicAddress() const {
    return "VDT" + sha256(publicKey).substr(0, 32); // pseudo-stealth address
}
