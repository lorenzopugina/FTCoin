#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "../Model/Transaction.h"
#include "../DAO/inMemory/transactionDAOmemory.h"
#include "../DAO/inMemory/OracleDAOMemory.h"
#include "../DAO/inMemory/WalletDAOMemory.h"


class TransactionController {
private:
    std::shared_ptr<TransactionDAO> dao;
    shared_ptr<WalletDAO> walletDAO;
    std::shared_ptr<OracleDAO> oracleDAO;

public:
    TransactionController(std::shared_ptr<TransactionDAO> dao,
                          std::shared_ptr<OracleDAO> oracleDAO,
                          shared_ptr<WalletDAO> walletDAO);

    bool createTransaction(int walletId, const Date& operationDate, char operationType, double quantity);
    std::shared_ptr<Transaction> findTransaction(int transactionId) const;
    std::vector<Transaction> listTransactionsByWallet(int walletId) const;
    bool updateTransaction(int transactionId, const Date& newDate, char newType, double newQuantity);
    bool deleteTransaction(int transactionId);
    double calculateWalletBalance(int walletId);
};

#endif // TRANSACTION_CONTROLLER_H
