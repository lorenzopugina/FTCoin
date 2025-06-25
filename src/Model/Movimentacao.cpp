#include "Movimentacao.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cctype>  //std::toupper

using namespace std;

int Movimentacao::cont = 1;


Movimentacao::Movimentacao(int idCarteira, const Date& dataOperacao, 
                           char tipoOperacao, double quantidade)
{
    // para passar pelas validações
    this->idCarteira = idCarteira; 
    setIdMovimento();
    setDataOperacao(dataOperacao);
    setTipoOperacao(tipoOperacao);
    setQuantidade(quantidade);
}

int Movimentacao::getIdCarteira() const { return idCarteira; }
int Movimentacao::getIdMovimento() const { return idMovimento; }
Date Movimentacao::getDataOperacao() const { return dataOperacao; }
char Movimentacao::getTipoOperacao() const { return tipoOperacao; }
double Movimentacao::getQuantidade() const { return quantidade; }


void Movimentacao::setIdMovimento() {
    this->idMovimento = cont++;
    cout << "\033[2J\033[H"; // limpa a tela
    cout << "\033[1;32m";    // verde brilhante
    cout << "Movimentacao criada com ID: " << idMovimento << endl;
    cout << "\033[0m";       // reset para cor padrão
}

void Movimentacao::setDataOperacao(const Date& data) {
    dataOperacao = data; 
}

void Movimentacao::setTipoOperacao(char tipo) {
    tipo = toupper(tipo);
    if (tipo != 'C' && tipo != 'V') {
        throw invalid_argument("Tipo de operação inválida. Use 'C' ou 'V'");
    }
    tipoOperacao = tipo;
}

void Movimentacao::setQuantidade(double qtd) {
    if (qtd < 0) {
        throw invalid_argument("Quantidade não pode ser negativa");
    }
    quantidade = qtd;
}

