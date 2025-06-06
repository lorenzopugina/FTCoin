#ifndef CARTEIRADAO_H
#define CARTEIRADAO_H

#include "../Model/Carteira.h" 

class CarteiraDAO {
public:
    virtual ~CarteiraDAO() {}

    virtual void criar(const Carteira& carteira) = 0;
    virtual Carteira* buscar(int id) = 0;
    virtual bool atualizar(const Carteira& carteira) = 0;
    virtual bool excluir(int id) = 0;
};

#endif
