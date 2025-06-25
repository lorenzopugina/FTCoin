#include <iostream>
#include <memory>
#include <vector>

#include "./DAO/inMemory/CarteiraDAOMemoria.h"
#include "./DAO/inMemory/MovimentacaoDAOMemoria.h"
#include "./DAO/inMemory/OraculoDAOMemoria.h"

#include "./Controller/controllerCarteira.h"
#include "./Controller/controllerMovimentacao.h"
#include "./Controller/controllerRelatorio.h"

#include "./View/Ajuda.h"
#include "./View/MenuCarteira.h"
#include "./View/MenuMovimentacao.h"
#include "./View/MenuRelatorio.h"
#include "./View/Menu.h"


using namespace std;

int main() {
    //Instanciar os DAOs (Banco em memória)
    auto carteiraDAO = make_shared<CarteiraDAOMemoria>();
    auto movimentacaoDAO = make_shared<MovimentacaoDAOMemoria>();
    auto oraculoDAO = make_shared<OraculoDAOMemoria>();

    //Instanciar os Controllers
    auto carteiraController = make_shared<CarteiraController>(carteiraDAO);
    auto movimentacaoController = make_shared<ControllerMovimentacao>(movimentacaoDAO, oraculoDAO); // ta invertido o nome arrumar no ingles
    auto relatorioController = make_shared<RelatorioController>(carteiraDAO, movimentacaoDAO, oraculoDAO);

    // Menu Principal
    vector<string> opcoesMenu = {
        "Carteira",
        "Movimentacao",
        "Relatorios",
        "Ajuda",
        "Sair"
    };

    bool executando = true;
    do {
        Menu menu(opcoesMenu, "Menu Principal", "Escolha uma opcao:");

        int escolha = menu.getChoice();

        switch (escolha) {
            case 0: // Menu Carteira
                menuCarteira(carteiraController);
                break;
            case 1: // Menu Movimentação
                menuMovimentacao(movimentacaoController);
                break;
            case 2: // Menu Relatórios
                menuRelatorio(relatorioController);
                break;
            case 3: { // Ajuda
                Ajuda ajuda("ajuda.txt");
                ajuda.exibir();
                break;
            }
            case 4: // Sair
                executando = false;
                cout << "Saindo do sistema...\n";
                break;
        }
    } while (executando);

    return 0;
}
