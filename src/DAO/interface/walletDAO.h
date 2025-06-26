#ifndef WALLET_DAO_H
#define WALLET_DAO_H

#include "../../Model/Wallet.h"
#include <memory>
#include <vector>

class WalletDAO {
public:
    virtual ~WalletDAO() {}

    virtual void create(const Wallet& wallet) = 0;
    virtual std::shared_ptr<Wallet> find(int id) = 0;
    virtual bool update(const Wallet& wallet) = 0;
    virtual bool remove(int id) = 0;
    virtual std::vector<Wallet> listAll() = 0;
};

#endif
