#ifndef MOVIMENTACAO_H_
#define MOVIMENTACAO_H_

#include "Data.h"  // Inclui a classe Data

class Movimentacao {
private:
    int id;
    int idCarteira;
    Data dataMov;
    char tipoMovimento;  // 'C' (Compra) ou 'V' (Venda)
    double quantMov;

    static int proximoId;  // Contador estático para gerar IDs automaticamente

public:
    // Construtor e Destrutor
    Movimentacao(int idCarteira, const Data& dataMov, char tipoMovimento, double quantMov);
    ~Movimentacao();

    // Getters (métodos const)
    int getId() const;
    int getIdCarteira() const;
    Data getDataMov() const;
    char getTipoMovimento() const;
    double getQuantMov() const;

    // Setters (com validação implícita no .cpp)
    void setIdCarteira(int idCarteira);
    void setDataMov(const Data& dataMov);
    void setTipoMovimento(char tipoMovimento);
    void setQuantMov(double quantMov);

    // Métodos de registro
    void registrarCompra();
    void registrarVenda();
};

#endif  // MOVIMENTACAO_H_
