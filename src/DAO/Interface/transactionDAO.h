#ifndef TRANSACTION_DAO_H
#define TRANSACTION_DAO_H

#include "Transaction.h"
#include <vector>
#include <memory>

class TransactionDAO {
public:
    virtual ~TransactionDAO() {}

    virtual void save(const Transaction& transaction) = 0;
    virtual std::shared_ptr<Transaction> findById(int transactionId) = 0;
    virtual std::vector<Transaction> listByWallet(int walletId) = 0;
    virtual bool update(const Transaction& transaction) = 0;
    virtual bool remove(int transactionId) = 0;
};

#endif // TRANSACTION_DAO_H
