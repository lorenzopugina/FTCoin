#ifndef ORACLE_DAO_MEMORY_H
#define ORACLE_DAO_MEMORY_H

#include "../interface/oracleDAO.h"
#include <vector>
#include <memory>

class OracleDAOMemory : public OracleDAO {
private:
    std::vector<Oracle> oracles;

public:
    void save(const Oracle& oracle) override;
    double findByDate(const Date& date) override;
    void update(const Oracle& oracle) override;
    void removeByDate(const Date& date) override;
};

#endif
