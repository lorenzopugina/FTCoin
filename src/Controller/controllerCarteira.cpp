#include <string>
#include <stdexcept>
#include "controllerCarteira.h"


CarteiraController::CarteiraController(unique_ptr<CarteiraDAO> dao, Menu& menu) 
    : dao(move(dao)), menu(menu) {} //inicialização

void CarteiraController::mostrarErro(const string& mensagem){
    menu.setMessage("Erro: " + mensagem); //mensagem de erro se alguma tarefa do usuário n for realizada
}

void CarteiraController::mostrarSucesso(const string& mensagem) {
    menu.setMessage("Sucesso: " + mensagem);//mensagem de sucesso se alguma tarefa do usuário for realizada
}

bool CarteiraController::carteiraExiste(int id) const {
    return dao->buscar(id) != nullptr;//p/ ver se uma carteira ja existe, evitando duplicações
}

void CarteiraController::criarCarteira(int id, const string& titular, const string& corretora) {
    try {
        if (carteiraExiste(id)){
            //verifcando se a carteira ja n existe
            mostrarErro("Carteira com ID " + to_string(id) + " já existe!");
            throw runtime_error("Carteira já existe");
        }

        Carteira novaCarteira(id, titular, corretora);
        
        if (!novaCarteira.estaValida()){
            mostrarErro("Dados inválidos para a carteira!");
            throw invalid_argument("Dados inválidos");
        }

        dao->criar(novaCarteira); //criando carteira
        mostrarSucesso("Carteira criada com sucesso!");
    } 

}

unique_ptr<Carteira> CarteiraController::buscarCarteira(int id){
     //busca uma carteira usando o id
    auto carteira = dao->buscar(id);
    if (!carteira){
        mostrarErro("Carteira não encontrada!");
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