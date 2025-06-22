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
        shared_ptr<CarteiraDAO> dao;

    public:
        CarteiraController(shared_ptr<CarteiraDAO> dao);
        ~CarteiraController();
        
        bool criarCarteira(const string& titular, const string& corretora);
        shared_ptr<Carteira> buscarCarteira(int id);
        bool atualizarCarteira(int id, const string& novoTitular, const string& novaCorretora);
        bool excluirCarteira(int id);
};

#endif