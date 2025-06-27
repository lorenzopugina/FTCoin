#include "TransactionController.h"
#include "../Utils/Message.h"


using namespace std;

TransactionController::TransactionController(shared_ptr<TransactionDAO> dao,
                                             shared_ptr<OracleDAO> oracleDAO,
                                             shared_ptr<WalletDAO> walletDAO) {
    this->dao = dao;
    this->oracleDAO = oracleDAO;
    this->walletDAO = walletDAO;
}

bool TransactionController::createTransaction(int walletId, const Date& operationDate,
                                              char operationType, double quantity) 
{
    // verify if wallet exists
    auto wallet = walletDAO->find(walletId);
    if (!wallet) {
        Message::showError("wallet with this ID does not exist.");
        return false;
    }
    
    try {
        Transaction transaction(walletId, operationDate, operationType, quantity);

        // validates if the sale is greater than the balance 
        if (toupper(operationType) == 'V') {
            double currentBalance = calculateWalletBalance(walletId); 
            if (currentBalance < quantity) {
                Message::showError("Insufficient balance to complete the sale.");
                return false;
            }
        }
        dao->save(transaction);

        // creates a quote for the day 
        Oracle oracle(operationDate);
        oracleDAO->save(oracle);

        return true;

    } catch (const std::invalid_argument&) {
        Message::showError("Invalid transaction data.");
        return false;
    }
}

shared_ptr<Transaction> TransactionController::findTransaction(int transactionId) const {
    return dao->findById(transactionId);
}

vector<Transaction> TransactionController::listTransactionsByWallet(int walletId) const {
    return dao->listByWallet(walletId);
}

bool TransactionController::updateTransaction(int transactionId, const Date& newDate,
                                              char newType, double newQuantity) {
    auto transaction = dao->findById(transactionId);
    if (transaction != nullptr) {
        transaction->setOperationDate(newDate);
        transaction->setOperationType(newType);
        transaction->setQuantity(newQuantity);
        return dao->update(*transaction);
    }
    return false;
}

bool TransactionController::deleteTransaction(int transactionId) {
    return dao->remove(transactionId);
}

double TransactionController::calculateWalletBalance(int walletId) {
    double total = 0.0;
    auto transactions = dao->listByWallet(walletId);

    for (const auto& t : transactions) {
        if (toupper(t.getOperationType()) == 'C')
            total += t.getQuantity();
        else if (toupper(t.getOperationType()) == 'V')
            total -= t.getQuantity();
    }
    return total;
}
