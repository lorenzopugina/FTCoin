#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <stdexcept>
#include "../Utils/Date.h"

class Transaction {
private:
    int walletId;
    int transactionId;
    Date operationDate;
    char operationType;
    double quantity;
    static int counter;

public:
    Transaction(int walletId, const Date& operationDate, char operationType, double quantity);

    int getWalletId() const;
    int getTransactionId() const;
    Date getOperationDate() const;
    char getOperationType() const;
    double getQuantity() const;

    void setTransactionId();
    void setOperationDate(const Date& date);
    void setOperationType(char type);
    void setQuantity(double qty);
};

#endif
