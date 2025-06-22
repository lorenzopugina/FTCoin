#include <string>
#include <stdexcept>
#include <memory>
#include "controllerCarteira.h"


CarteiraController::CarteiraController(unique_ptr<CarteiraDAO> dao, Menu& menu) : dao(move(dao)), menu(menu){} 

void CarteiraController::mostrarMensagem(const string& mensagem){
    menu.setMessage(mensagem); 
}

void CarteiraController::criarCarteira(const string& titular, const string& corretora) {
    try {
        Carteira novaCarteira(titular, corretora);

        dao->criar(novaCarteira); //criando carteira
        mostrarMensagem("Carteira criada com sucesso!");
    } 
    catch(const std::exception& e){
        mostrarMensagem(string("Erro ao criar carteira: ") + e.what());
    }
}

unique_ptr<Carteira> CarteiraController::buscarCarteira(int id){

    auto carteira = dao->buscar(id);
    if (!carteira){
        mostrarMensagem("Carteira não encontrada!");
        return nullptr;
    }
    return carteira; 
}

void CarteiraController::atualizarCarteira(int id, const string& novoTitular, const string& novaCorretora){
    try {
        auto carteira = buscarCarteira(id);
        if (!carteira) {
            mostrarErro("Carteira não encontrada para atualização!");
            return;
        }

        carteira->setTitular(novoTitular);
        carteira->setCorretora(novaCorretora);

        if (!carteira->estaValida()) {
            mostrarErro("Dados atualizados são inválidos!");
            throw invalid_argument("Dados inválidos");
        }

        dao->atualizar(*carteira);
        mostrarSucesso("Carteira atualizada com sucesso!");
    }
    // falta o catch 
}

void CarteiraController::excluirCarteira(int id) {
    if (!carteiraExiste(id)) {
        mostrarErro("Carteira não encontrada para exclusão!");
        return;
    }

    if (dao->excluir(id)) {
        mostrarSucesso("Carteira excluída com sucesso!");
    } else {
        mostrarErro("Falha ao excluir carteira!");
    }
}