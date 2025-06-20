#ifndef CARTEIRACONTROLLER_HPP
#define CARTEIRACONTROLLER_HPP

#include <string> 
#include <memory> //p smart pointers
#include "../Model/Carteira.h"
#include "../DAO/CarteiraDAO.h"
#include "../View/Menu.h"

using namespace std;

class CarteiraController 
{
private:
    unique_ptr<CarteiraDAO> dao;
    Menu& menu;

public:
//construtor
    CarteiraController(unique_ptr<CarteiraDAO> dao, Menu& menu);
    
    void criarCarteira(int id, const string& titular, const string& corretora);
    unique_ptr<Carteira> buscarCarteira(int id);
    void atualizarCarteira(int id, const string& novoTitular, const string& novaCorretora);
    void excluirCarteira(int id);

private: // ficou feio
    bool carteiraExiste(int id) const; //p/ verificar se uma carteira já existe p/ n ter duplicações
    void mostrarErro(const string& mensagem); //p/ mostrar mensagem de erro
    void mostrarSucesso(const string& mensagem); //p/ mostrar mensagem de sucesso em alguma tarefa q o usuário solicitou
};

#endif