#ifndef ORACULO_H
#define ORACULO_H

#include "../Utils/Date.h"

class Oraculo {
private:
    Date data;
    double cotacao;

public:
    Oraculo(const Date& data);  

    Date getData() const;
    double getCotacao() const;

    void setData(const Date& data);
    void setCotacao(double cotacao);

    double gerarCotacaoAleatoria() const;  
};

#endif // ORACULO_H
