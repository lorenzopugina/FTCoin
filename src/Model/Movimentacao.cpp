#include "Movimentacao.h"
#include <stdexcept>  // Para std::invalid_argument

// Inicialização do contador estático
int Movimentacao::proximoId = 1;

// Construtor
Movimentacao::Movimentacao(int idCarteira, const Data& dataMov, char tipoMovimento, double quantMov) 
    : id(proximoId++), 
      idCarteira(idCarteira), 
      dataMov(dataMov), 
      tipoMovimento(tipoMovimento), 
      quantMov(quantMov) {

    // Validações
    if (idCarteira <= 0) {
        throw std::invalid_argument("ID da carteira deve ser positivo.");
    }
    if (tipoMovimento != 'C' && tipoMovimento != 'V') {
        throw std::invalid_argument("Tipo de movimento inválido. Use 'C' (Compra) ou 'V' (Venda).");
    }
    if (quantMov <= 0) {
        throw std::invalid_argument("Quantidade deve ser positiva.");
    }
}

// Destrutor
Movimentacao::~Movimentacao() {
    // Nada a fazer aqui (por enquanto)
}

// --- Getters ---
int Movimentacao::getId() const { 
    return id; 
}

int Movimentacao::getIdCarteira() const { 
    return idCarteira; 
}

Data Movimentacao::getDataMov() const { 
    return dataMov; 
}

char Movimentacao::getTipoMovimento() const { 
    return tipoMovimento; 
}

double Movimentacao::getQuantMov() const { 
    return quantMov; 
}

// --- Setters ---
void Movimentacao::setIdCarteira(int idCarteira) {
    if (idCarteira <= 0) {
        throw std::invalid_argument("ID da carteira deve ser positivo.");
    }
    this->idCarteira = idCarteira;
}

void Movimentacao::setDataMov(const Data& dataMov) {
    this->dataMov = dataMov;
}

void Movimentacao::setTipoMovimento(char tipoMovimento) {
    if (tipoMovimento != 'C' && tipoMovimento != 'V') {
        throw std::invalid_argument("Tipo de movimento inválido. Use 'C' (Compra) ou 'V' (Venda).");
    }
    this->tipoMovimento = tipoMovimento;
}

void Movimentacao::setQuantMov(double quantMov) {
    if (quantMov <= 0) {
        throw std::invalid_argument("Quantidade deve ser positiva.");
    }
    this->quantMov = quantMov;
}

// --- Métodos de Registro ---
void Movimentacao::registrarCompra() {
    tipoMovimento = 'C';
    // Adicione lógica adicional aqui (ex: registrar em um log ou banco de dados)
}

void Movimentacao::registrarVenda() {
    tipoMovimento = 'V';
    // Adicione lógica adicional aqui
}
