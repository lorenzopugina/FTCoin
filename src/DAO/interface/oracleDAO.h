#ifndef ORACLE_DAO_H
#define ORACLE_DAO_H

#include "../../Model/Oracle.h"
#include <vector>
#include <memory>

class OracleDAO {
public:
    virtual ~OracleDAO() = default;

    virtual void save(const Oracle& oracle) = 0;
    virtual double findByDate(const Date& date) = 0;
    virtual void update(const Oracle& oracle) = 0;
    virtual void removeByDate(const Date& date) = 0;
};

#endif
