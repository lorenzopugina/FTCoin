#include "Oraculo.h"
#include <random>  // para geração de números aleatórios

// Construtor
Oraculo::Oraculo(const Date& data)
    : data(data), cotacao(gerarCotacaoAleatoria()) {}


Date Oraculo::getData() const { return data;}
double Oraculo::getCotacao() const { return cotacao;}

void Oraculo::setData(const Date& data){ this->data = data;}
void Oraculo::setCotacao(double cotacao){ this->cotacao = cotacao;}

// Geração de cotação aleatória entre 0.8 e 2.4
double Oraculo::gerarCotacaoAleatoria() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0.8, 2.4);
    return distrib(gen);
}
