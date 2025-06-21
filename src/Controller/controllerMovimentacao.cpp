#include "controllerMovimentacao.h"
#include <iostream>

// Assuming these exist for now
// #include "MovimentacaoDAO.h"
// #include "Movimentacao.h"

ControllerMovimentacao::ControllerMovimentacao() {
    // Initialize DAO here
}

void ControllerMovimentacao::handleRegisterBuy(int idCarteira, const std::string& dataOperacao, double quantidade) {
    displayMessage("Registering buy for wallet ID " + std::to_string(idCarteira) + ": " + std::to_string(quantidade) + " on " + dataOperacao);
    // Example: movimentacaoDAO->create(Movimentacao(idCarteira, dataOperacao, 'C', quantidade));
}

void ControllerMovimentacao::handleRegisterSell(int idCarteira, const std::string& dataOperacao, double quantidade) {
    displayMessage("Registering sell for wallet ID " + std::to_string(idCarteira) + ": " + std::to_string(quantidade) + " on " + dataOperacao);
    // Example: movimentacaoDAO->create(Movimentacao(idCarteira, dataOperacao, 'V', quantidade));
}

void ControllerMovimentacao::displayMovementDetails(int idCarteira, const std::string& dataOperacao, char tipoOperacao, double quantidade) {
    std::cout << "Wallet ID: " << idCarteira << ", Date: " << dataOperacao << ", Type: " << tipoOperacao << ", Quantity: " << quantidade << std::endl;
}

void ControllerMovimentacao::displayMessage(const std::string& message) {
    std::cout << "ControllerMovimentacao: " << message << std::endl;
}

