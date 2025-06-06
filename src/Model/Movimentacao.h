#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <stdexcept>

class Movimentacao {
private:
    int idCarteira;         // Chave estrangeira
    int idMovimento;        // Chave primária (única)
    std::string dataOperacao; // Data no formato YYYY-MM-DD
    char tipoOperacao;      // 'C' para compra, 'V' para venda
    double quantidade;      // Não negativo

    // Método auxiliar para validar dados
    void validarDados();

public:
    // Construtor
    Movimentacao(int idCarteira, int idMovimento, const std::string& dataOperacao, 
                 char tipoOperacao, double quantidade);

    // Getters
    int getIdCarteira() const;
    int getIdMovimento() const;
    std::string getDataOperacao() const;
    char getTipoOperacao() const;
    double getQuantidade() const;

    // Setters com validação
    void setIdCarteira(int id);
    void setIdMovimento(int id);
    void setDataOperacao(const std::string& data);
    void setTipoOperacao(char tipo);
    void setQuantidade(double qtd);
};

#endif // MOVIMENTACAO_H
