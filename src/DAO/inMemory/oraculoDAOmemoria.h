#ifndef ORACULODAOMEMORIA_H
#define ORACULODAOMEMORIA_H

#include "../interface/oraculoDAO.h"
#include <vector>
#include <memory>

class OraculoDAOMemoria : public OraculoDAO {
private:
    std::vector<Oraculo> oraculos;

public:
    void salvar(const Oraculo& oraculo) override;
    double buscarPorData(const Date& data) override;
    void atualizar(const Oraculo& oraculo) override;
    void removerPorData(const Date& data) override;
};

#endif
