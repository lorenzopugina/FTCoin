#ifndef CARTEIRADAOMEMORIA_H
#define CARTEIRADAOMEMORIA_H

#include "../interface/carteiraDAO.h"
#include <vector>

class CarteiraDAOMemoria : public CarteiraDAO {
private:
    std::vector<Carteira> bancoInMemory;

public:
    void criar(const Carteira& carteira) override;
    std::shared_ptr<Carteira> buscar(int id) override;
    bool atualizar(const Carteira& carteira) override;
    bool excluir(int id) override;
};

#endif
