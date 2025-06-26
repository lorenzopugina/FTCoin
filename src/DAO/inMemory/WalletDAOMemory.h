#ifndef WALLET_DAO_MEMORY_H
#define WALLET_DAO_MEMORY_H

#include "../interface/walletDAO.h"
#include <vector>
#include <memory>

class WalletDAOMemory : public WalletDAO {
private:
    std::vector<Wallet> Wallets;

public:
    void create(const Wallet& wallet) override;
    std::shared_ptr<Wallet> find(int id) override;
    bool update(const Wallet& wallet) override;
    bool remove(int id) override;
    std::vector<Wallet> listAll() override;
};

#endif
