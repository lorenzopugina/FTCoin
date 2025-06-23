#ifndef MOVIMENTACAODAO_H
#define MOVIMENTACAODAO_H

#include "Movimentacao.h"
#include <vector>
#include <memory>

class MovimentacaoDAO {
public:
    virtual ~MovimentacaoDAO() {}

    virtual void salvar(const Movimentacao& movimentacao) = 0;
    virtual std::shared_ptr<Movimentacao> buscarPorId(int idMovimento) = 0;
    virtual std::vector<Movimentacao> listarPorCarteira(int idCarteira) = 0;
    virtual bool atualizar(const Movimentacao& movimentacao) = 0;
    virtual bool remover(int idMovimento) = 0;
};

#endif // MOVIMENTACAODAO_H
