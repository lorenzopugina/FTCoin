#ifndef CONTROLLER_MOVIMENTACAO_H
#define CONTROLLER_MOVIMENTACAO_H

#include <string>
#include <vector>
#include <memory>

#include "../Model/Movimentacao.h"
#include "../DAO/inMemory/movimentacaoDAOmemoria.h"
#include "../DAO/inMemory/oraculoDAOmemoria.h"


class ControllerMovimentacao {
private:
    std::shared_ptr<MovimentacaoDAO> dao;
    std::shared_ptr<OraculoDAO> oraculoDAO;

public:
    ControllerMovimentacao(std::shared_ptr<MovimentacaoDAO> dao,
                           std::shared_ptr<OraculoDAO> oraculoDAO);

    bool criarMovimentacao(int idCarteira, const Date& dataOperacao, char tipoOperacao, double quantidade);
    std::shared_ptr<Movimentacao> buscarMovimentacao(int idMovimento) const;
    std::vector<Movimentacao> listarMovimentacoesPorCarteira(int idCarteira) const;
    bool atualizarMovimentacao(int idMovimento, const Date& novaData, char novoTipo, double novaQuantidade);
    bool excluirMovimentacao(int idMovimento);
};

#endif // CONTROLLER_MOVIMENTACAO_H
