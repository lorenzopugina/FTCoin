#include "Movimentacao.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cctype>  //std::toupper


Movimentacao::Movimentacao(int idCarteira, int idMovimento, const Date& dataOperacao, 
                           char tipoOperacao, double quantidade)
{
    // para passar pelas validações
    setIdCarteira(idCarteira);
    setIdMovimento(idMovimento);
    setDataOperacao(dataOperacao);
    setTipoOperacao(tipoOperacao);
    setQuantidade(quantidade);
}

int Movimentacao::getIdCarteira() const { return idCarteira; }
int Movimentacao::getIdMovimento() const { return idMovimento; }
Date Movimentacao::getDataOperacao() const { return dataOperacao; }
char Movimentacao::getTipoOperacao() const { return tipoOperacao; }
double Movimentacao::getQuantidade() const { return quantidade; }


void Movimentacao::setIdCarteira(int id) {
    if (id <= 0) throw std::invalid_argument("ID da carteira deve ser positivo");
    idCarteira = id;
}

void Movimentacao::setIdMovimento(int id) {
    if (id <= 0) throw std::invalid_argument("ID do movimento deve ser positivo");
    idMovimento = id;
}

void Movimentacao::setDataOperacao(const Date& data) {
    dataOperacao = data; 
}

void Movimentacao::setTipoOperacao(char tipo) {
    tipo = std::toupper(tipo);
    if (tipo != 'C' && tipo != 'V') {
        throw std::invalid_argument("Tipo de operação inválida. Use 'C' ou 'V'");
    }
    tipoOperacao = tipo;
}

void Movimentacao::setQuantidade(double qtd) {
    if (qtd < 0) {
        throw std::invalid_argument("Quantidade não pode ser negativa");
    }
    quantidade = qtd;
}

