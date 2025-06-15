#ifndef CARTEIRACONTROLLER_HPP
#define CARTEIRACONTROLLER_HPP

#include <string> 
#include <memory> //p smat pointers
#include "../Model/Carteira.hpp"
#include "../DAO/CarteiraDAO.hpp"
#include "../View/Menu.hpp"

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

private:
    bool carteiraExiste(int id) const; //p/ verificar se uma carteira já existe p/ n ter duplicações
    void mostrarErro(const string& mensagem); //p/ mostrar mensagem de erro
    void mostrarSucesso(const string& mensagem); //p/ mostrar mensagem de sucesso em alguma tarefa q o usuário solicitou
};

#endif
