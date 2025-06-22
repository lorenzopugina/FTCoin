#include "MenuCarteira.h"
#include "Menu.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menuCarteira(shared_ptr<CarteiraController> carteiraController) {
    vector<string> itens = {
        "Criar Carteira",
        "Buscar Carteira",
        "Atualizar Carteira",
        "Excluir Carteira",
        "Voltar"
    };

    bool executando = true;
    do {
        Menu menu(itens, "Menu Carteira", "Escolha uma opção:");
        int opcao = menu.getChoice();

        switch (opcao) {
            case 0: { // Criar
                string titular, corretora;
                cout << "Titular: ";
                getline(cin, titular);
                cout << "Corretora: ";
                getline(cin, corretora);

                if (carteiraController->criarCarteira(titular, corretora))
                    cout << "Carteira criada com sucesso!\n";
                else
                    cout << "Erro ao criar carteira.\n";
                break;
            }
            case 1: { // Buscar
                int id;
                cout << "ID da carteira: ";
                cin >> id; cin.ignore();

                auto carteira = carteiraController->buscarCarteira(id);
                if (carteira) {
                    cout << "ID: " << carteira->getId() << "\n";
                    cout << "Titular: " << carteira->getTitular() << "\n";
                    cout << "Corretora: " << carteira->getCorretora() << "\n";
                } else {
                    cout << "Carteira não encontrada.\n";
                }
                break;
            }
            case 2: { // Atualizar
                int id;
                string titular, corretora;
                cout << "ID da carteira: ";
                cin >> id; cin.ignore();

                cout << "Novo Titular: ";
                getline(cin, titular);
                cout << "Nova Corretora: ";
                getline(cin, corretora);

                if (carteiraController->atualizarCarteira(id, titular, corretora))
                    cout << "Carteira atualizada!\n";
                else
                    cout << "Carteira não encontrada.\n";
                break;
            }
            case 3: { // Excluir
                int id;
                cout << "ID da carteira: ";
                cin >> id; cin.ignore();

                if (carteiraController->excluirCarteira(id))
                    cout << "Carteira excluída.\n";
                else
                    cout << "Carteira não encontrada.\n";
                break;
            }
            case 4:
                executando = false;
                break;
        }
    } while (executando);
}
