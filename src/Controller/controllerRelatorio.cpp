#include "controllerRelatorio.h"
#include <algorithm>
#include <stdexcept>
#include "../Utils/Date.h"

using namespace std;

RelatorioController::RelatorioController(shared_ptr<CarteiraDAO> cDAO,
                                         shared_ptr<MovimentacaoDAO> mDAO,
                                         shared_ptr<OraculoDAO> oDAO)
    : carteiraDAO(cDAO), movimentacaoDAO(mDAO), oraculoDAO(oDAO) {}

RelatorioController::~RelatorioController() {}

std::vector<Carteira> RelatorioController::listarCarteirasPorId() {
    auto carteiras = carteiraDAO->listarTodas();
    std::sort(carteiras.begin(), carteiras.end(), 
              [](const Carteira& a, const Carteira& b) {
                  return a.getId() < b.getId();
              });
    return carteiras;
}

std::vector<Carteira> RelatorioController::listarCarteirasPorTitular() {
    auto carteiras = carteiraDAO->listarTodas();
    std::sort(carteiras.begin(), carteiras.end(), 
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

std::vector<Movimentacao> RelatorioController::obterHistoricoCarteira(int idCarteira) {
    return movimentacaoDAO->listarPorCarteira(idCarteira);
}

double RelatorioController::calcularGanhoPerda(int idCarteira) 
{
    double saldo = calcularSaldoCarteira(idCarteira);

    if (saldo == 0) {return 0.0;}

    // Obter histórico
    auto historico = movimentacaoDAO->listarPorCarteira(idCarteira);

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

    return (saldo * cotacaoAtual) - (saldo * cotacaoAntiga);
}

