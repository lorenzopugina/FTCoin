#include "WalletDAOMemory.h"
#include <memory>

void WalletDAOMemory::create(const Wallet& wallet) {
    Wallets.push_back(wallet);
}

std::shared_ptr<Wallet> WalletDAOMemory::find(int id) {
    for (const auto& wallet : Wallets) {
        if (wallet.getId() == id) {
            return std::make_shared<Wallet>(wallet);
        }
    }
    return nullptr;
}

bool WalletDAOMemory::update(const Wallet& wallet) {
    for (auto& walletMem : Wallets) {
        if (walletMem.getId() == wallet.getId()) {
            walletMem.setHolder(wallet.getHolder());
            walletMem.setBrokerage(wallet.getBrokerage());
            return true;
        }
    }
    return false;
}

bool WalletDAOMemory::remove(int id) {
    for (auto it = Wallets.begin(); it != Wallets.end(); ++it) {
        if (it->getId() == id) {
            Wallets.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Wallet> WalletDAOMemory::listAll() {
    return Wallets;
}
