#include "../carteiraDAO.h" // deu prob

void CarteiraDAOMemoria::criar(const Carteira& carteira) {
    bancoInMemory.push_back(carteira);
}

Carteira* CarteiraDAOMemoria::buscar(int id) {
    for (const auto& carteiraInMemory : bancoInMemory) {
        if (carteiraInMemory.getId() == id) {
            return new Carteira(carteiraInMemory); // lembrar delete 
        }
    }
    return nullptr;
}

bool CarteiraDAOMemoria::atualizar(const Carteira& carteira) {
    for (auto& carteiraInMemory : bancoInMemory) {
        if (carteiraInMemory.getId() == carteira.getId()) {
            carteiraInMemory.setTitular(carteira.getTitular());
            carteiraInMemory.setCorretora(carteira.getCorretora());
            return true;
        }
    }
    return false;
}

bool CarteiraDAOMemoria::excluir(int id) {
    for (auto it = bancoInMemory.begin(); it != bancoInMemory.end(); ++it) {
        if (it->getId() == id) {
            bancoInMemory.erase(it);
            return true;
        }
    }
    return false;
}
