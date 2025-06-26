#ifndef ORACLE_H
#define ORACLE_H

#include "../Utils/Date.h"

class Oracle {
private:
    Date date;
    double quotation;

public:
    Oracle(const Date& date);

    Date getDate() const;
    double getQuotation() const;

    void setDate(const Date& date);
    void setQuotation(double quotation);

    double generateRandomQuotation() const;
};

#endif
