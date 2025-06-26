#include "ReportController.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "../Utils/Date.h"

using namespace std;

ReportController::ReportController(shared_ptr<WalletDAO> wDAO,
                                   shared_ptr<TransactionDAO> tDAO,
                                   shared_ptr<OracleDAO> oDAO)
    : walletDAO(wDAO), transactionDAO(tDAO), oracleDAO(oDAO) {}

ReportController::~ReportController() {}

vector<Wallet> ReportController::listWalletsById() {
    auto wallets = walletDAO->listAll();
    sort(wallets.begin(), wallets.end(),
        [](const Wallet& a, const Wallet& b) {
            return a.getId() < b.getId();
        });
    return wallets;
}

vector<Wallet> ReportController::listWalletsByHolder() {
    auto wallets = walletDAO->listAll();
    sort(wallets.begin(), wallets.end(),
        [](const Wallet& a, const Wallet& b) {
            return a.getHolder() < b.getHolder();
        });
    return wallets;
}

double ReportController::calculateWalletBalance(int walletId)
{
    auto transactions = transactionDAO->listByWallet(walletId);
    double balance = 0.0;

    for (const auto& t : transactions) {
        if (t.getOperationType() == 'B') {
            balance += t.getQuantity();
        } else if (t.getOperationType() == 'S') {
            balance -= t.getQuantity();
        }
    }

    return balance;
}

vector<Transaction> ReportController::getWalletHistory(int walletId) {
    return transactionDAO->listByWallet(walletId);
}

double ReportController::calculateRecentGainLoss(int walletId) 
{
    auto history = transactionDAO->listByWallet(walletId);
    double balance = calculateWalletBalance(walletId);

    if (history.empty() || balance == 0) { return 0.0; }

    // Get date of newest transaction
    Date newestTransaction = history.front().getOperationDate();
    for (const auto& t : history) {
        if (t.getOperationDate() > newestTransaction) {
            newestTransaction = t.getOperationDate();
        }
    }

    Date today;
    double oldQuotation = oracleDAO->findByDate(newestTransaction);
    double currentQuotation = oracleDAO->findByDate(today);

    return (balance * currentQuotation) - (balance * oldQuotation);
}


double ReportController::calculateOldGainLoss(int walletId) 
{
    auto history = transactionDAO->listByWallet(walletId);
    double balance = calculateWalletBalance(walletId);

    if (history.empty() || balance == 0) { return 0.0; }

    // Get date of oldest transaction
    Date oldestTransaction = history.front().getOperationDate();
    for (const auto& t : history) {
        if (t.getOperationDate() < oldestTransaction) {
            oldestTransaction = t.getOperationDate();
        }
    }

    Date today;
    double oldQuotation = oracleDAO->findByDate(oldestTransaction);
    double currentQuotation = oracleDAO->findByDate(today);

    return (balance * currentQuotation) - (balance * oldQuotation);
}