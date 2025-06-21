#ifndef ORACULO_H
#define ORACULO_H

#include "../Utils/Date.h"

class Oraculo {
private:
    Date data;
    double cotacao;

    double gerarCotacaoAleatoria() const;  

public:
    Oraculo(const Date& data);  // construtor recebe a data e gera a cotação

    Date getData() const;
    double getCotacao() const;

    void setData(const Date& data);
    void setCotacao(double cotacao);
};

#endif // ORACULO_H
