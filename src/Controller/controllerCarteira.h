#ifndef CARTEIRACONTROLLER_H
#define CARTEIRACONTROLLER_H

#include <string> 
#include <memory>
#include "../Model/Carteira.h"
#include "../DAO/inMemory/CarteiraDAOmemoria.h" 
#include "../View/Menu.h"

using namespace std;

class CarteiraController 
{
    private:
        unique_ptr<CarteiraDAO> dao;
        Menu& menu;

        void mostrarMensagem(const string& mensagem); 

    public:
        CarteiraController(unique_ptr<CarteiraDAO> dao, Menu& menu);
        
        void criarCarteira(const string& titular, const string& corretora);
        unique_ptr<Carteira> buscarCarteira(int id);
        void atualizarCarteira(int id, const string& novoTitular, const string& novaCorretora);
        void excluirCarteira(int id);
};

#endif