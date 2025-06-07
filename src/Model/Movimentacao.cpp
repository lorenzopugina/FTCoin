#include "Movimentacao.h"
#include <ctime>
#include <sstream>
#include <iomanip>

Movimentacao::Movimentacao(int idCarteira, int idMovimento, const std::string& dataOperacao, 
                           char tipoOperacao, double quantidade) 
    : idCarteira(idCarteira), idMovimento(idMovimento), dataOperacao(dataOperacao),
      tipoOperacao(tipoOperacao), quantidade(quantidade) {
    validarDados();
}

void Movimentacao::validarDados() {
    if (idCarteira <= 0) {
        throw std::invalid_argument("ID da carteira deve ser positivo");
    }
    
    if (idMovimento <= 0) {
        throw std::invalid_argument("ID do movimento deve ser positivo");
    }
    
    // Validação simples da data (formato YYYY-MM-DD)
    if (dataOperacao.length() != 10 || 
        dataOperacao[4] != '-' || dataOperacao[7] != '-') {
        throw std::invalid_argument("Formato de data inválido. Use YYYY-MM-DD");
    }
    
    if (tipoOperacao != 'C' && tipoOperacao != 'V') {
        throw std::invalid_argument("Tipo de operação inválido. Use 'C' ou 'V'");
    }
    
    if (quantidade < 0) {
        throw std::invalid_argument("Quantidade não pode ser negativa");
    }
}

// Getters
int Movimentacao::getIdCarteira() const { return idCarteira; }
int Movimentacao::getIdMovimento() const { return idMovimento; }
std::string Movimentacao::getDataOperacao() const { return dataOperacao; }
char Movimentacao::getTipoOperacao() const { return tipoOperacao; }
double Movimentacao::getQuantidade() const { return quantidade; }

// Setters
void Movimentacao::setIdCarteira(int id) { 
    if (id <= 0) throw std::invalid_argument("ID da carteira deve ser positivo");
    idCarteira = id; 
}

void Movimentacao::setIdMovimento(int id) { 
    if (id <= 0) throw std::invalid_argument("ID do movimento deve ser positivo");
    idMovimento = id; 
}

void Movimentacao::setDataOperacao(const std::string& data) { 
    // Validação simples do formato
    if (data.length() != 10 || data[4] != '-' || data[7] != '-') {
        throw std::invalid_argument("Formato de data inválido. Use YYYY-MM-DD");
    }
    dataOperacao = data; 
}

void Movimentacao::setTipoOperacao(char tipo) { 
    tipo = toupper(tipo);
    if (tipo != 'C' && tipo != 'V') {
        throw std::invalid_argument("Tipo de operação inválido. Use 'C' ou 'V'");
    }
    tipoOperacao = tipo; 
}

void Movimentacao::setQuantidade(double qtd) { 
    if (qtd < 0) {
        throw std::invalid_argument("Quantidade não pode ser negativa");
    }
    quantidade = qtd; 
}
