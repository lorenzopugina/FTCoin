#ifndef CONTROLLERRELATORIO_H
#define CONTROLLERRELATORIO_H

#include "../DAO/inMemory/carteiraDAOmemoria.h"
#include "../DAO/inMemory/movimentacaoDAOmemoria.h"
#include "../DAO/inMemory/oraculoDAOmemoria.h"
#include "../Model/Carteira.h"
#include "../Model/Movimentacao.h"
#include "../Model/Oraculo.h"
#include <vector>
#include <memory>

using namespace std;

class RelatorioController {
private:
    shared_ptr<CarteiraDAO> carteiraDAO;
    shared_ptr<MovimentacaoDAO> movimentacaoDAO;
    shared_ptr<OraculoDAO> oraculoDAO;

public:
    RelatorioController(shared_ptr<CarteiraDAO> carteiraDAO, shared_ptr<MovimentacaoDAO> movimentacaoDAO, 
                                                             shared_ptr<OraculoDAO> oraculoDAO);
    ~RelatorioController();

    vector<Carteira> listarCarteirasPorId();
    vector<Carteira> listarCarteirasPorTitular();
    double calcularSaldoCarteira(int idCarteira);
    vector<Movimentacao> obterHistoricoCarteira(int idCarteira);
    
    double calcularGanhoPerda(int idCarteira);
};

#endif
