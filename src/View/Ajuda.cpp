#include "Ajuda.h"
#include <iostream>
#include <fstream>

using namespace std;

Ajuda::Ajuda(const string& caminhoArquivo) : caminho(caminhoArquivo) {}

void Ajuda::exibir() const {
    ifstream arquivo(caminho);

    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo de ajuda: " << caminho << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }

    arquivo.close();
}
