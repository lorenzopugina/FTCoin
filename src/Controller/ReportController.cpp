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

double ReportController::calculateWalletBalance(int walletId) {
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

double ReportController::calculateGainLoss(int walletId) {
    auto history = transactionDAO->listByWallet(walletId);

    if (history.empty()) {
        cout << "Wallet has no transactions.\n";
        return 0.0;
    }

    double balance = calculateWalletBalance(walletId);
    if (balance == 0) {
        return 0.0;
    }

    // Get date of last transaction
    Date lastDate = history.front().getOperationDate();
    for (const auto& t : history) {
        if (t.getOperationDate() > lastDate) {
            lastDate = t.getOperationDate();
        }
    }

    Date today;
    double oldQuotation = oracleDAO->findByDate(lastDate);
    double currentQuotation = oracleDAO->findByDate(today);

    // Debug output (can be removed in final version)
    cout << "Is empty: " << history.empty() << endl;
    cout << "Old quotation: " << oldQuotation << endl;
    cout << "Current quotation: " << currentQuotation << endl;

    return (balance * currentQuotation) - (balance * oldQuotation);
}
