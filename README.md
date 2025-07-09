# VeidtCoin Core

**“This chain is not the beginning.  
It is the shadow before the signal.”**  
— *Taro Veidt, First Cipherholder*

VeidtCoin is a privacy-first cryptocurrency built from a custom Monero-like base, with a capped supply and optimized performance.

---

## 🔐 Key Features

- ShadowNet testnet support
- RingCT + stealth transactions
- Capped supply: 21 million VDT
- 45-second block time
- Modular, clean C++ architecture

---

## 🧱 Directory Overview

| Directory | Purpose |
|----------|---------|
| `src/core`    | Blockchain + consensus |
| `src/crypto`  | RingCT, keys, hash |
| `src/network` | P2P & sync logic |
| `src/daemon`  | Main node loop |
| `src/genesis` | Genesis block logic |

---

## 🚀 Build Instructions

```bash
git clone https://github.com/VeidtCoin/veidtcoin-core.git
cd veidtcoin-core
mkdir build && cd build
cmake ..
make -j$(nproc)
