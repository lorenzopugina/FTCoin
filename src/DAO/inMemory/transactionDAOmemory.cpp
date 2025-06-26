#include "TransactionDAOMemory.h"
#include <memory>

void TransactionDAOMemory::save(const Transaction& transaction) {
    transactions.push_back(transaction);
}

std::shared_ptr<Transaction> TransactionDAOMemory::findById(int transactionId) {
    for (const auto& t : transactions) {
        if (t.getTransactionId() == transactionId) {
            return std::make_shared<Transaction>(t);
        }
    }
    return nullptr;
}

std::vector<Transaction> TransactionDAOMemory::listByWallet(int walletId) {
    std::vector<Transaction> list;
    for (const auto& t : transactions) {
        if (t.getWalletId() == walletId) {
            list.push_back(t);
        }
    }
    return list;
}

bool TransactionDAOMemory::update(const Transaction& transaction) {
    for (auto& t : transactions) {
        if (t.getTransactionId() == transaction.getTransactionId()) {
            t.setOperationDate(transaction.getOperationDate());
            t.setOperationType(transaction.getOperationType());
            t.setQuantity(transaction.getQuantity());
            return true;
        }
    }
    return false;
}

bool TransactionDAOMemory::remove(int transactionId) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->getTransactionId() == transactionId) {
            transactions.erase(it);
            return true;
        }
    }
    return false;
}
