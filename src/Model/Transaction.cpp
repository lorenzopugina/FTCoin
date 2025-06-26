#include "Transaction.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cctype>  // std::toupper
#include <iostream>

using namespace std;

int Transaction::counter = 1;

Transaction::Transaction(int walletId, const Date& operationDate, 
                         char operationType, double quantity) {
    this->walletId = walletId;
    setTransactionId();
    setOperationDate(operationDate);
    setOperationType(operationType);
    setQuantity(quantity);
}

int Transaction::getWalletId() const { return walletId; }
int Transaction::getTransactionId() const { return transactionId; }
Date Transaction::getOperationDate() const { return operationDate; }
char Transaction::getOperationType() const { return operationType; }
double Transaction::getQuantity() const { return quantity; }

void Transaction::setTransactionId() {
    transactionId = counter++;

    cout << "Transaction created with ID: " << transactionId << endl;
}

void Transaction::setOperationDate(const Date& date) {
    operationDate = date;
}

void Transaction::setOperationType(char type) {
    type = toupper(type);
    if (type != 'B' && type != 'S') {
        throw invalid_argument("Invalid operation type. Use 'B' or 'S'");
    }
    operationType = type;
}

void Transaction::setQuantity(double qty) {
    if (qty < 0) {
        throw invalid_argument("Quantity cannot be negative");
    }
    quantity = qty;
}
