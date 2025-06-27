#include "TransactionController.h"
#include "WalletController.h"


using namespace std;

TransactionController::TransactionController(shared_ptr<TransactionDAO> dao,
                                             shared_ptr<OracleDAO> oracleDAO) {
    this->dao = dao;
    this->oracleDAO = oracleDAO;
}

bool TransactionController::createTransaction(int walletId, const Date& operationDate,
                                              char operationType, double quantity) 
{

    if (WalletController::findWallet(walletId))
    {
        /* code */
    }
    
    try {
        Transaction transaction(walletId, operationDate, operationType, quantity);
        dao->save(transaction);

        Oracle oracle(operationDate);
        oracleDAO->save(oracle);

        return true;
    } catch (const invalid_argument&) {
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
