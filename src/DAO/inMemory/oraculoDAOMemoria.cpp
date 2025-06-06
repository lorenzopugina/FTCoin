#include "oraculoDAOmemoria.h"

void OraculoDAOMemoria::salvar(const Oraculo& oraculo) {
    oraculos.push_back(oraculo);
}

Oraculo OraculoDAOMemoria::buscarPorData(const Date& data) {
    for (const auto& o : oraculos) {
        if (o.getData() == data) {
            return o;
        }
    }
    //throw std::runtime_error("Oraculo não encontrado para a data informada.");
}

void OraculoDAOMemoria::atualizar(const Oraculo& oraculo) {
    for (auto& o : oraculos) {
        if (o.getData() == oraculo.getData()) {
            o = oraculo; // Atualiza com o novo valor
            return;
        }
    }
    //throw std::runtime_error("Oraculo para a data informada não encontrado para atualização.");
}


void OraculoDAOMemoria::removerPorData(const Date& data) {
    for (auto it = oraculos.begin(); it != oraculos.end(); ++it) {
        if (it->getData() == data) {
            oraculos.erase(it);
            return;
        }
    }
}
