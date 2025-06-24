#include "MenuRelatorio.h"
#include "Menu.h"

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void menuRelatorio(shared_ptr<RelatorioController> relatorioController) {
    vector<string> itens = {
        "Listar Carteiras por ID",
        "Listar Carteiras por Titular",
        "Ver Saldo de uma Carteira",
        "Ver Histórico de uma Carteira",
        "Ver Ganho/Perda de uma Carteira",
        "Voltar"
    };

    bool executando = true;
    do {
        Menu menu(itens, "Menu Relatório", "Escolha uma opção:");
        int opcao = menu.getChoice();

        switch (opcao) {
            case 0: { // Listar por ID
                auto lista = relatorioController->listarCarteirasPorId();
                if (lista.empty()) {
                    cout << "Nenhuma carteira encontrada.\n";
                } else {
                    for (const auto& c : lista) {
                        cout << "ID: " << c.getId()
                             << " | Titular: " << c.getTitular()
                             << " | Corretora: " << c.getCorretora() << "\n";
                    }
                }
                break;
            }
            case 1: { // Listar por Titular
                auto lista = relatorioController->listarCarteirasPorTitular();
                if (lista.empty()) {
                    cout << "Nenhuma carteira encontrada.\n";
                } else {
                    for (const auto& c : lista) {
                        cout << "ID: " << c.getId()
                             << " | Titular: " << c.getTitular()
                             << " | Corretora: " << c.getCorretora() << "\n";
                    }
                }
                break;
            }
            case 2: { // Ver Saldo
                int id;
                cout << "ID da carteira: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida.\n";
                    break;
                }
                cin.ignore();
                double saldo = relatorioController->calcularSaldoCarteira(id);
                cout << "Saldo atual: " << saldo << "\n";
                break;
            }
            case 3: { // Histórico
                int id;
                cout << "ID da carteira: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida.\n";
                    break;
                }
                cin.ignore();
                auto historico = relatorioController->obterHistoricoCarteira(id);
                if (historico.empty()) {
                    cout << "Nenhuma movimentação encontrada.\n";
                } else {
                    for (const auto& mov : historico) {
                        cout << "ID Movimentação: " << mov.getIdMovimento()
                             << " | Data: " << mov.getDataOperacao()
                             << " | Tipo: " << mov.getTipoOperacao()
                             << " | Quantidade: " << mov.getQuantidade() << "\n";
                    }
                }
                break;
            }
            case 4: { // Ganho/Perda
                int id;
                cout << "ID da carteira: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida.\n";
                    break;
                }
                cin.ignore();
                double ganho = relatorioController->calcularGanhoPerda(id);
                cout << "Ganho/Perda atual: " << ganho << "\n";
                break;
            }
            case 5:
                executando = false;
                break;
        }
    } while (executando);
}
