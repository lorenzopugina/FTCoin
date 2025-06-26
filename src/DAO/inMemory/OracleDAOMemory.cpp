#include "OracleDAOMemory.h"

void OracleDAOMemory::save(const Oracle& oracle) {
    oracles.push_back(oracle);
}

double OracleDAOMemory::findByDate(const Date& date) {
    for (const auto& o : oracles) {
        if (o.getDate() == date) {
            return o.getQuotation();
        }
    }

    throw std::runtime_error("Quotation not found for the given date.");
}

void OracleDAOMemory::update(const Oracle& oracle) {
    for (auto& o : oracles) {
        if (o.getDate() == oracle.getDate()) {
            o = oracle;
            return;
        }
    }

    throw std::runtime_error("No quotation exists for the given date.");
}

void OracleDAOMemory::removeByDate(const Date& date) {
    for (auto it = oracles.begin(); it != oracles.end(); ++it) {
        if (it->getDate() == date) {
            oracles.erase(it);
            return;
        }
    }

    throw std::runtime_error("No quotation exists for the given date.");
}
