#include "Carteira.h"
#include <stdexcept> 

using namespace std;

Carteira::Carteira() : id(0), nomeTitular(""), corretora("") {} // ?

Carteira::Carteira(int id, const string& titular, const string& corretora) 
    : id(id), nomeTitular(titular), corretora(corretora) 
{
    if (!estaValida()) 
    {//verifica se há um nome para titular e nome para corretora, ou sej, a se estão vazios ou nao
        throw invalid_argument("Dados inválidos para criação da carteira");
    }
}

Carteira::~Carteira() {}

int Carteira::getId() const { return id;}
string Carteira::getTitular() const { return nomeTitular;}
string Carteira::getCorretora() const { return corretora;}


void Carteira::setId(int id) {  
    this->id = id;
}

void Carteira::setTitular(const string& newTitular) {
    if (newTitular.empty()){
        //se n houver um nome do titular, esta errado
        throw invalid_argument("Nome do titular não pode ser vazio");
    }
    nomeTitular = newTitular;
}

void Carteira::setCorretora(const string& newCorretora) {
    if (newCorretora.empty()){
        //se n houver um nome da corretora, esta errado
        throw invalid_argument("Corretora não pode ser vazia");
    }
    corretora = newCorretora;
}

// Validação do model
bool Carteira::estaValida() const {
    return (id > 0 && !nomeTitular.empty() && !corretora.empty());
}