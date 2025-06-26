#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "../Model/Transaction.h"
#include "../DAO/inMemory/TransactionDAOMemory.h"
#include "../DAO/inMemory/OracleDAOMemory.h"

class TransactionController {
private:
    std::shared_ptr<TransactionDAO> dao;
    std::shared_ptr<OracleDAO> oracleDAO;

public:
    TransactionController(std::shared_ptr<TransactionDAO> dao,
                          std::shared_ptr<OracleDAO> oracleDAO);

    bool createTransaction(int walletId, const Date& operationDate, char operationType, double quantity);
    std::shared_ptr<Transaction> findTransaction(int transactionId) const;
    std::vector<Transaction> listTransactionsByWallet(int walletId) const;
    bool updateTransaction(int transactionId, const Date& newDate, char newType, double newQuantity);
    bool deleteTransaction(int transactionId);
};

#endif // TRANSACTION_CONTROLLER_H
