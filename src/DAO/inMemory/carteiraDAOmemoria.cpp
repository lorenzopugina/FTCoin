#include "carteiraDAOmemoria.h" 
#include <memory>

void CarteiraDAOMemoria::criar(const Carteira& carteira) {
    carteirasInMemory.push_back(carteira);
}

std::shared_ptr<Carteira> CarteiraDAOMemoria::buscar(int id) {
    for (const auto& carteiraMemory : carteirasInMemory) {
        if (carteiraMemory.getId() == id) {
            return std::make_shared<Carteira>(carteiraMemory);
        }
    }
    return nullptr;
}

bool CarteiraDAOMemoria::atualizar(const Carteira& carteira) {
    for (auto& carteiraMemory : carteirasInMemory) {
        if (carteiraMemory.getId() == carteira.getId()) {
            carteiraMemory.setTitular(carteira.getTitular());
            carteiraMemory.setCorretora(carteira.getCorretora());
            return true;
        }
    }
    return false;
}

bool CarteiraDAOMemoria::excluir(int id) {
    for (auto it = carteirasInMemory.begin(); it != carteirasInMemory.end(); ++it) {
        if (it->getId() == id) {
            carteirasInMemory.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Carteira> CarteiraDAOMemoria::listarTodas() {
    return carteirasInMemory;
}


