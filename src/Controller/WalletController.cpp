#include "WalletController.h"

using namespace std;

WalletController::WalletController(shared_ptr<WalletDAO> dao) {
    this->dao = dao;
}

WalletController::~WalletController() {}

bool WalletController::createWallet(const string& holder, const string& brokerage) {
    try {
        Wallet wallet(holder, brokerage);
        dao->create(wallet);
        return true;
    } catch (const invalid_argument&) {
        return false;
    }
}

shared_ptr<Wallet> WalletController::findWallet(int id) {
    return dao->find(id);
}

bool WalletController::updateWallet(int id, const string& newHolder, const string& newBrokerage) {
    auto wallet = dao->find(id);
    if (wallet != nullptr) {
        wallet->setHolder(newHolder);
        wallet->setBrokerage(newBrokerage);
        return dao->update(*wallet);
    }
    return false;
}

bool WalletController::deleteWallet(int id) {
    return dao->remove(id);
}
