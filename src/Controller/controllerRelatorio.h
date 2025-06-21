#ifndef CONTROLLERRELATORIO_H
#define CONTROLLERRELATORIO_H

#include "../DAO/inMemory/carteiraDAOmemoria.h"
#include "../DAO/inMemory/movimentacaoDAOmemoria.h"
#include "../DAO/inMemory/oraculoDAOmemoria.h"
#include "../Model/Carteira.h"
#include "../Model/Movimentacao.h"
#include "../Model/Oraculo.h"
#include <vector>

using namespace std;

class RelatorioController {
private:
    CarteiraDAO* carteiraDAO;
    MovimentacaoDAO* movimentacaoDAO;
    OraculoDAO* oraculoDAO;

public:
    RelatorioController(CarteiraDAO* cDAO, MovimentacaoDAO* mDAO, OraculoDAO* oDAO);

    // Funcionalidades
    vector<Carteira> listarCarteirasPorId();
    vector<Carteira> listarCarteirasPorNome();

    double calcularSaldoCarteira(int idCarteira);

    vector<Movimentacao> obterHistoricoCarteira(int idCarteira);

    double calcularGanhoPerda(int idCarteira);
};

#endif
