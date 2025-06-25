#include "controllerRelatorio.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "../Utils/Date.h"

using namespace std;

RelatorioController::RelatorioController(shared_ptr<CarteiraDAO> cDAO,
                                         shared_ptr<MovimentacaoDAO> mDAO,
                                         shared_ptr<OraculoDAO> oDAO)
    : carteiraDAO(cDAO), movimentacaoDAO(mDAO), oraculoDAO(oDAO) {}

RelatorioController::~RelatorioController() {}

vector<Carteira> RelatorioController::listarCarteirasPorId() {
    auto carteiras = carteiraDAO->listarTodas();
    sort(carteiras.begin(), carteiras.end(),
        [](const Carteira& a, const Carteira& b) {
            return a.getId() < b.getId();
        });
    return carteiras;
}

vector<Carteira> RelatorioController::listarCarteirasPorTitular() {
    auto carteiras = carteiraDAO->listarTodas();
    sort(carteiras.begin(), carteiras.end(),
        [](const Carteira& a, const Carteira& b) {
            return a.getTitular() < b.getTitular();
        });
    return carteiras;
}

double RelatorioController::calcularSaldoCarteira(int idCarteira) {
    auto movimentacoes = movimentacaoDAO->listarPorCarteira(idCarteira);
    double saldo = 0.0;

    for (const auto& mov : movimentacoes) {
        if (mov.getTipoOperacao() == 'C') {
            saldo += mov.getQuantidade();
        } else if (mov.getTipoOperacao() == 'V') {
            saldo -= mov.getQuantidade();
        }
    }

    return saldo;
}

vector<Movimentacao> RelatorioController::obterHistoricoCarteira(int idCarteira) {
    return movimentacaoDAO->listarPorCarteira(idCarteira);
}

double RelatorioController::calcularGanhoPerda(int idCarteira) {
    auto historico = movimentacaoDAO->listarPorCarteira(idCarteira);

    if (historico.empty()) {
        cout << "Carteira sem movimentações.\n";
        return 0.0;
    }

    double saldo = calcularSaldoCarteira(idCarteira);
    if (saldo == 0) {
        return 0.0;
    }

    // Encontrar data da última movimentação
    Date dataUltimaMovimentacao = historico.front().getDataOperacao();
    for (const auto& mov : historico) {
        if (mov.getDataOperacao() > dataUltimaMovimentacao) {
            dataUltimaMovimentacao = mov.getDataOperacao();
        }
    }

    Date hoje;
    double cotacaoAntiga = oraculoDAO->buscarPorData(dataUltimaMovimentacao);
    double cotacaoAtual = oraculoDAO->buscarPorData(hoje);

    //------- altera isso
    std::cout << "tem coisa: " << historico.empty() << std::endl;
    std::cout << "cotação antiga: " << cotacaoAntiga << std::endl;
    std::cout << "cotação atual: " << cotacaoAtual << std::endl;


    // return burro
    return (saldo * cotacaoAtual) - (saldo * cotacaoAntiga);
}
