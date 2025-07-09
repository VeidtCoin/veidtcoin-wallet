# 💼 VeidtCoin Wallet

Secure. Private. Yours.  
Designed to interact with the VeidtCoin Core daemon on ShadowNet or Mainnet.

---

## 🧩 Modules

- `cli/` – Terminal interface
- `keys/` – Seed, private/public keys
- `rpc/` – JSON-RPC for communication
- `gui/` – GUI frontend placeholder
- `util/` – Shared wallet utilities

---

## 🔐 Features

- Deterministic wallet generation
- Stealth address support
- Encrypted private key storage
- CLI + RPC interface (GUI later)

---

## 🛠 Build

```bash
git clone https://github.com/VeidtCoin/veidtcoin-wallet.git
cd veidtcoin-wallet
mkdir build && cd build
cmake ..
make -j$(nproc)
