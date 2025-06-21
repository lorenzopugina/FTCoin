#ifndef CONTROLLER_MOVIMENTACAO_H
#define CONTROLLER_MOVIMENTACAO_H

#include <string>
#include <vector>

// Forward declarations
// class MovimentacaoDAO; // Assuming a DAO for Movimentacao exists
// class Movimentacao;    // Assuming a Movimentacao model exists

class ControllerMovimentacao {
public:
    ControllerMovimentacao();

    void handleRegisterBuy(int idCarteira, const std::string& dataOperacao, double quantidade);
    void handleRegisterSell(int idCarteira, const std::string& dataOperacao, double quantidade);

private:
    // MovimentacaoDAO* movimentacaoDAO;

    void displayMovementDetails(int idCarteira, const std::string& dataOperacao, char tipoOperacao, double quantidade);
    void displayMessage(const std::string& message);
};

#endif // CONTROLLER_MOVIMENTACAO_H
