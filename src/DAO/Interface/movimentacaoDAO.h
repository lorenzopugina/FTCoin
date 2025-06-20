#ifndef MOVIMENTACAODAO_H
#define MOVIMENTACAODAO_H

#include "Movimentacao.h"
#include <vector>

class MovimentacaoDAO {
public:
    virtual ~MovimentacaoDAO() {}

    virtual void salvar(const Movimentacao& movimentacao) = 0;
    virtual Movimentacao* buscarPorId(int idMovimento) = 0;
    virtual std::vector<Movimentacao> listarPorCarteira(int idCarteira) = 0;
    virtual bool atualizar(const Movimentacao& movimentacao) = 0;
    virtual bool remover(int idMovimento) = 0;
};

#endif // MOVIMENTACAODAO_H
