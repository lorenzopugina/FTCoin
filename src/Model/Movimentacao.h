#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <stdexcept>

#include "../Utils/Date.h" 

class Movimentacao {
private:
    int idCarteira;         
    int idMovimento;        
    Date  dataOperacao;  
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

    void setIdCarteira(int id); 
    void setIdMovimento(int id);
    void setDataOperacao(const Date& dataOperacao);
    void setTipoOperacao(char tipo);
    void setQuantidade(double qtd);
};

#endif // MOVIMENTACAO_H
