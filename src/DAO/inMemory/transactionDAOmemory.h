#ifndef TRANSACTION_DAO_MEMORY_H
#define TRANSACTION_DAO_MEMORY_H

#include "../interface/transactionDAO.h"
#include <vector>
#include <memory>

class TransactionDAOMemory : public TransactionDAO {
private:
    std::vector<Transaction> transactions;

public:
    void save(const Transaction& transaction) override;
    std::shared_ptr<Transaction> findById(int transactionId) override;
    std::vector<Transaction> listByWallet(int walletId) override;
    bool update(const Transaction& transaction) override;
    bool remove(int transactionId) override;
};

#endif // TRANSACTIONDAOMEMORY_H
