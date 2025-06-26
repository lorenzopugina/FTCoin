#ifndef WALLET_CONTROLLER_H
#define WALLET_CONTROLLER_H

#include <string>
#include <memory>
#include "../Model/Wallet.h"
#include "../DAO/inMemory/WalletDAOMemory.h"
#include "../View/Menu.h"

using namespace std;

class WalletController {
private:
    shared_ptr<WalletDAO> dao;

public:
    WalletController(shared_ptr<WalletDAO> dao);
    ~WalletController();

    bool createWallet(const string& holder, const string& brokerage);
    shared_ptr<Wallet> findWallet(int id);
    bool updateWallet(int id, const string& newHolder, const string& newBrokerage);
    bool deleteWallet(int id);
};

#endif
