#ifndef MOVIMENTACAODAOMEMORIA_H
#define MOVIMENTACAODAOMEMORIA_H

#include "../Interface/movimentacaoDAO.h"
#include <vector>
#include <memory>

class MovimentacaoDAOMemoria : public MovimentacaoDAO {
private:
    std::vector<Movimentacao> banco;

public:
    void salvar(const Movimentacao& movimentacao) override;
    std::shared_ptr<Movimentacao> buscarPorId(int idMovimento) override;
    std::vector<Movimentacao> listarPorCarteira(int idCarteira) override;
    bool atualizar(const Movimentacao& movimentacao) override;
    bool remover(int idMovimento) override;
};

#endif // MOVIMENTACAODAOMEMORIA_H
