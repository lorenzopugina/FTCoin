#include "controllerCarteira.h"

using namespace std;


CarteiraController::CarteiraController(shared_ptr<CarteiraDAO> dao) {
    this->dao = dao;
}

CarteiraController::~CarteiraController() {}

bool CarteiraController::criarCarteira(const string& titular, const string& corretora) {
    try {
        Carteira carteira(titular, corretora);
        dao->criar(carteira);
        return true;
    } catch (const invalid_argument&) {
        return false;
    }
}

shared_ptr<Carteira> CarteiraController::buscarCarteira(int id) {
    return dao->buscar(id);
}

bool CarteiraController::atualizarCarteira(int id, const string& novoTitular, const string& novaCorretora) {
    auto carteira = dao->buscar(id);
    if (carteira != nullptr) {
        carteira->setTitular(novoTitular);
        carteira->setCorretora(novaCorretora);
        return dao->atualizar(*carteira);
    }
    return false;
}

bool CarteiraController::excluirCarteira(int id) {
    return dao->excluir(id);
}