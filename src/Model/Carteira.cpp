#include "Carteira.h"
#include <stdexcept> 
#include <iostream>

using namespace std;

int Carteira::cont = 1;

Carteira::Carteira(const string& titular, const string& corretora) 
{
    setId();
    setTitular(titular);
    setCorretora(corretora);
}

Carteira::~Carteira() {}

int Carteira::getId() const { return id;}
string Carteira::getTitular() const { return nomeTitular;}
string Carteira::getCorretora() const { return corretora;}


void Carteira::setId() {
    id = cont++; // id automatico

    std::cout << "\033[2J\033[H"; // limpa a tela
    std::cout << "\033[1;32m";    // verde brilhante
    cout << "Carteira criada com ID: " << id << endl;
    std::cout << "\033[0m";       // reset para cor padrão
} 

void Carteira::setTitular(const string& titular) {
   
    if (titular.empty()){
        throw invalid_argument("Nome do titular não pode ser vazio");
    }
    nomeTitular = titular;
}

void Carteira::setCorretora(const string& nomeCorretora) {

    if (nomeCorretora.empty()){
        throw invalid_argument("Corretora não pode ser vazia");
    }
    corretora = nomeCorretora;
}
