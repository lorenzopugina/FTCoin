#include "Oraculo.h"
#include <random>  // para geração de números aleatórios


Oraculo::Oraculo(const Date& data)
    : data(data), cotacao(gerarCotacaoAleatoria()) {}


Date Oraculo::getData() const { return data;}
double Oraculo::getCotacao() const { return cotacao;}

void Oraculo::setData(const Date& data){ this->data = data;}
void Oraculo::setCotacao(double cotacao){ this->cotacao = cotacao;}

// Geração de cotação aleatória entre 0.8 e 2.4
double Oraculo::gerarCotacaoAleatoria() const {
    static std::mt19937 gen(std::random_device{}()); // inicializa só na 1ª vez
    std::uniform_real_distribution<> distrib(0.8, 2.4);
    return distrib(gen);
}

