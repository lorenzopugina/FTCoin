#include "MenuMovimentacao.h"
#include "Menu.h"
#include "../Utils/Date.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menuMovimentacao(shared_ptr<ControllerMovimentacao> ControllerMovimentacao) {
    vector<string> itens = {
        "Criar Movimentação",
        "Buscar Movimentação",
        "Atualizar Movimentação",
        "Excluir Movimentação",
        "Voltar"
    };

    bool executando = true;
    do {
        Menu menu(itens, "Menu Movimentação", "Escolha uma opção:");
        int opcao = menu.getChoice();

        switch (opcao) {
            case 0: { // Criar
                int idCarteira;
                int dia;
                int mes;
                int ano;
                char escolha;
                char tipo;
                double quantidade;
                Date data;

                cout << "ID da carteira: ";
                cin >> idCarteira; 

                cout << "Criar Movimentação na data de hoje? S/N";
                cin >> escolha;

                if (escolha == 'N'){
                    cout << "Digite a data separado por espaços (dia mes ano): ";
                    cin >> dia >> mes >> ano;
                    data.setDate(dia,mes,ano);
                }

                cout << "Tipo (C - Compra, V - Venda): ";
                cin >> tipo; 
                cout << "Quantidade: ";
                cin >> quantidade; 

                if (ControllerMovimentacao->criarMovimentacao(idCarteira, data, tipo, quantidade))
                    cout << "Movimentação criada!\n";
                else
                    cout << "Erro ao criar movimentação.\n";
                break;
            }
            case 1: { // Buscar
                int id;
                cout << "ID da movimentação: ";
                cin >> id; cin.ignore();

                auto mov = ControllerMovimentacao->buscarMovimentacao(id);
                if (mov) {
                    cout << "ID Movimentação: " << mov->getIdMovimento() << "\n";
                    cout << "ID Carteira: " << mov->getIdCarteira() << "\n";
                    cout << "Data: " << mov->getDataOperacao() << "\n";
                    cout << "Tipo: " << mov->getTipoOperacao() << "\n";
                    cout << "Quantidade: " << mov->getQuantidade() << "\n";
                } else {
                    cout << "Movimentação não encontrada.\n";
                }
                break;
            }
            case 2: { // Atualizar
                int id;
                int dia;
                int mes;
                int ano;
                char tipo;
                double quantidade;

                cout << "ID da movimentação: ";
                cin >> id;

                cout << "Digite a data separado por espaços (dia mes ano): ";
                cin >> dia >> mes >> ano;

                cout << "Novo Tipo (C/V): ";
                cin >> tipo;

                cout << "Nova Quantidade: ";
                cin >> quantidade;

                Date data(dia, mes, ano);

                if (ControllerMovimentacao->atualizarMovimentacao(id, data, tipo, quantidade))
                    cout << "Movimentação atualizada!\n";
                else
                    cout << "Movimentação não encontrada.\n";

                break;
            }

            case 3: { // Excluir
                int id;
                cout << "ID da movimentação: ";
                cin >> id; cin.ignore();

                if (ControllerMovimentacao->excluirMovimentacao(id))
                    cout << "Movimentação excluída.\n";
                else
                    cout << "Movimentação não encontrada.\n";
                break;
            }
            case 4:
                executando = false;
                break;
        }
    } while (executando);
}
