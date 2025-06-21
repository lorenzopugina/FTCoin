#ifndef CONTROLLER_RELATORIO_H
#define CONTROLLER_RELATORIO_H

#include <string>
#include <vector>

// Forward declarations
// class RelatorioDAO; // Assuming a DAO for Relatorio exists

class ControllerRelatorio {
public:
    ControllerRelatorio();

    void handleListWalletsSortedById();
    void handleListWalletsSortedByHolderName();
    void handleDisplayWalletBalance(int idCarteira);
    void handleDisplayWalletMovementHistory(int idCarteira);
    void handleDisplayWalletGainLoss(int idCarteira);

private:
    // RelatorioDAO* relatorioDAO;

    void displayReportMessage(const std::string& message);
};

#endif // CONTROLLER_RELATORIO_H
