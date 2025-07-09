# VeidtCoin Wallet GUI

> “We do not bank. We cipher.”  
> — Taro Veidt

This is the official desktop wallet for VeidtCoin — a privacy-first cryptocurrency built on silent consensus. The wallet features a sleek, low-distraction GUI in Quantum Purple, designed to keep your identity unseen and your assets sovereign.

---

## 🧭 Features

- 🟣 Quantum Purple UI Theme
- 🕯 Genesis splash screen with quote
- 💼 Create, load, and view wallets
- 🧊 Cold-storage ready
- 🔐 Placeholder privacy engine (to be upgraded)

---

## 📦 Build Instructions

```bash
git clone https://github.com/VeidtCoin/veidtcoin-wallet.git
cd veidtcoin-wallet
mkdir build && cd build
cmake ..
make -j$(nproc)
