#ifndef IORACULODAO_HPP
#define IORACULODAO_HPP

#include "../Model/Oraculo.h"
#include <vector>

class OraculoDAO {
public:
    virtual ~OraculoDAO() = default;

    virtual void salvar(const Oraculo& oraculo) = 0;
    virtual double buscarPorData(const Date& data) = 0;  
    virtual void atualizar(const Oraculo& oraculo) = 0;
    virtual void removerPorData(const Date& data) = 0;
};

#endif
