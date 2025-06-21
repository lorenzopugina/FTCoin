#include "controllerRelatorio.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

// Construtor
RelatorioController::RelatorioController(CarteiraDAO* cDAO, MovimentacaoDAO* mDAO, OraculoDAO* oDAO)
    : carteiraDAO(cDAO), movimentacaoDAO(mDAO), oraculoDAO(oDAO) {}

// Lista carteiras ordenadas por ID
vector<Carteira> RelatorioController::listarCarteirasPorId() {
    vector<Carteira> lista;

    // Simula listagem buscando uma a uma
    for (int id = 1;; id++) {
        Carteira* c = carteiraDAO->buscar(id);
        if (c == nullptr) break;
        lista.push_back(*c);
        delete c;
    }

    sort(lista.begin(), lista.end(), [](const Carteira& a, const Carteira& b) {
        return a.getId() < b.getId();
    });

    return lista;
}

// Lista carteiras ordenadas por nome do titular
vector<Carteira> RelatorioController::listarCarteirasPorNome() {
    vector<Carteira> lista;

    for (int id = 1;; id++) {
        Carteira* c = carteiraDAO->buscar(id);
        if (c == nullptr) break;
        lista.push_back(*c);
        delete c;
    }

    sort(lista.begin(), lista.end(), [](const Carteira& a, const Carteira& b) {
        return a.getTitular() < b.getTitular();
    });

    return lista;
}

// Calcula saldo atual da carteira
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

// Retorna histórico de movimentações da carteira
vector<Movimentacao> RelatorioController::obterHistoricoCarteira(int idCarteira) {
    return movimentacaoDAO->listarPorCarteira(idCarteira);
}

// Calcula ganho ou perda da carteira considerando cotações
double RelatorioController::calcularGanhoPerda(int idCarteira) {
    auto movimentacoes = movimentacaoDAO->listarPorCarteira(idCarteira);
    double totalComprado = 0.0;
    double totalVendido = 0.0;

    for (const auto& mov : movimentacoes) {
        double cotacao = oraculoDAO->buscarPorData(mov.getDataOperacao()).getCotacao();

        if (mov.getTipoOperacao() == 'C') {
            totalComprado += mov.getQuantidade() * cotacao;
        } else if (mov.getTipoOperacao() == 'V') {
            totalVendido += mov.getQuantidade() * cotacao;
        }
    }

    return totalVendido - totalComprado;
}
