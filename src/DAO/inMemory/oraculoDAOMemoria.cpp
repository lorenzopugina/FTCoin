#include "oraculoDAOmemoria.h"

void OraculoDAOMemoria::salvar(const Oraculo& oraculo) {
    oraculos.push_back(oraculo);
}

double OraculoDAOMemoria::buscarPorData(const Date& data) {
    for (const auto& o : oraculos) {
        if (o.getData() == data) { 
            return o.getCotacao();
        }
    }

    throw std::runtime_error("Cotação não encontrada para a data informada.");
}

void OraculoDAOMemoria::atualizar(const Oraculo& oraculo) {
    for (auto& o : oraculos) {
        if (o.getData() == oraculo.getData()) {
            o = oraculo; 
            return;
        }
    }

    throw std::runtime_error("Não existe cotação para a data informada.");
}

void OraculoDAOMemoria::removerPorData(const Date& data) {
    for (auto it = oraculos.begin(); it != oraculos.end(); ++it) {
        if (it->getData() == data) {
            oraculos.erase(it);
            return;
        }
    }

    throw std::runtime_error("Não existe cotação para a data informada.");
}
