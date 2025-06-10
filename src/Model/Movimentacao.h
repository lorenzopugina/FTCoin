#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <stdexcept>

#include "../Utils/Date.h" // usando a classe data

class Movimentacao {
private:
    int idCarteira;         
    int idMovimento;        
    Date  dataOperacao;  // composição, colocar no UML
    char tipoOperacao;      
    double quantidade;      

public:
    Movimentacao(int idCarteira, int idMovimento, const Date& dataOperacao, 
                 char tipoOperacao, double quantidade);

    int getIdCarteira() const;
    int getIdMovimento() const;
    Date getDataOperacao() const;
    char getTipoOperacao() const;
    double getQuantidade() const;

    void setIdCarteira(int id); // esses 2 provavelmente não existem
    void setIdMovimento(int id); // aqui
    void setDataOperacao(const Date& dataOperacao);
    void setTipoOperacao(char tipo);
    void setQuantidade(double qtd);
};

#endif // MOVIMENTACAO_H
