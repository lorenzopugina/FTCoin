#ifndef CARTEIRADAOMEMORIA_H
#define CARTEIRADAOMEMORIA_H

#include "../interface/carteiraDAO.h"
#include <vector>
#include <memory>

class CarteiraDAOMemoria : public CarteiraDAO {
private:
    std::vector<Carteira> carteirasInMemory;

public:
    void criar(const Carteira& carteira) override;
    std::shared_ptr<Carteira> buscar(int id) override;
    bool atualizar(const Carteira& carteira) override;
    bool excluir(int id) override;
    vector<Carteira> listarTodas() override;
};

#endif
