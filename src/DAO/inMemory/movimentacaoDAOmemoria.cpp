#include "MovimentacaoDAOMemoria.h"
#include <memory>

void MovimentacaoDAOMemoria::salvar(const Movimentacao& movimentacao) {
    banco.push_back(movimentacao);
}

std::shared_ptr<Movimentacao> MovimentacaoDAOMemoria::buscarPorId(int idMovimento) {
    for (const auto& mov : banco) {
        if (mov.getIdMovimento() == idMovimento) {
            return std::make_shared<Movimentacao>(mov);
        }
    }
    return nullptr;
}

std::vector<Movimentacao> MovimentacaoDAOMemoria::listarPorCarteira(int idCarteira) {
    std::vector<Movimentacao> lista;
    for (const auto& mov : banco) {
        if (mov.getIdCarteira() == idCarteira) {
            lista.push_back(mov);
        }
    }
    return lista;
}

bool MovimentacaoDAOMemoria::atualizar(const Movimentacao& movimentacao) {
    for (auto& mov : banco) {
        if (mov.getIdMovimento() == movimentacao.getIdMovimento()) {
            mov.setDataOperacao(movimentacao.getDataOperacao());
            mov.setTipoOperacao(movimentacao.getTipoOperacao());
            mov.setQuantidade(movimentacao.getQuantidade());
            return true;
        }
    }
    return false;
}

bool MovimentacaoDAOMemoria::remover(int idMovimento) {
    for (auto it = banco.begin(); it != banco.end(); ++it) {
        if (it->getIdMovimento() == idMovimento) {
            banco.erase(it);
            return true;
        }
    }
    return false;
}
