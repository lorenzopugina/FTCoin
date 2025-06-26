#ifndef REPORT_CONTROLLER_H
#define REPORT_CONTROLLER_H

#include "../DAO/inMemory/WalletDAOMemory.h"
#include "../DAO/inMemory/transactionDAOmemory.h"
#include "../DAO/inMemory/OracleDAOMemory.h"
#include "../Model/Wallet.h"
#include "../Model/Transaction.h"
#include "../Model/Oracle.h"
#include <vector>
#include <memory>

using namespace std;

class ReportController {
private:
    shared_ptr<WalletDAO> walletDAO;
    shared_ptr<TransactionDAO> transactionDAO;
    shared_ptr<OracleDAO> oracleDAO;

public:
    ReportController(shared_ptr<WalletDAO> walletDAO,
                     shared_ptr<TransactionDAO> transactionDAO,
                     shared_ptr<OracleDAO> oracleDAO);

    ~ReportController();

    vector<Wallet> listWalletsById();
    vector<Wallet> listWalletsByHolder();
    double calculateWalletBalance(int walletId);
    vector<Transaction> getWalletHistory(int walletId);
    double calculateRecentGainLoss(int walletId);
    double calculateOldGainLoss(int walletId);
};

#endif
