#include "controllerMovimentacao.h"

using namespace std;

ControllerMovimentacao::ControllerMovimentacao(shared_ptr<MovimentacaoDAO> dao) {
    this->dao = dao;
}

bool ControllerMovimentacao::criarMovimentacao(int idCarteira, const Date& dataOperacao, 
                                               char tipoOperacao, double quantidade)
{
    try {
        Movimentacao movimentacao(idCarteira, dataOperacao, tipoOperacao, quantidade);
        dao->salvar(movimentacao);
        return true;
    } catch (const invalid_argument&) {
        return false;
    }
}

shared_ptr<Movimentacao> ControllerMovimentacao::buscarMovimentacao(int idMovimento) const {
    return dao->buscarPorId(idMovimento);
}

vector<Movimentacao> ControllerMovimentacao::listarMovimentacoesPorCarteira(int idCarteira) const {
    return dao->listarPorCarteira(idCarteira);
}

bool ControllerMovimentacao::atualizarMovimentacao(int idMovimento, const Date& novaData,
                                                   char novoTipo, double novaQuantidade) 
{
    auto movimentacao = dao->buscarPorId(idMovimento);
    if (movimentacao != nullptr) {
        movimentacao->setDataOperacao(novaData);
        movimentacao->setTipoOperacao(novoTipo);
        movimentacao->setQuantidade(novaQuantidade);
        return dao->atualizar(*movimentacao);
    }
    return false;
}

bool ControllerMovimentacao::excluirMovimentacao(int idMovimento) {
    return dao->remover(idMovimento);
}
