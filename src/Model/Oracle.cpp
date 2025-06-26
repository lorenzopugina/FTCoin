#include "Oracle.h"
#include <random>  // for random number generation

Oracle::Oracle(const Date& date) : date(date), quotation(generateRandomQuotation()) {}

Date Oracle::getDate() const { return date; }
double Oracle::getQuotation() const { return quotation; }

void Oracle::setDate(const Date& date) { this->date = date; }
void Oracle::setQuotation(double quotation) { this->quotation = quotation; }

// Generate random quotation between 0.8 and 2.4
double Oracle::generateRandomQuotation() const {
    static std::mt19937 gen(std::random_device{}()); // initialize only once
    std::uniform_real_distribution<> distrib(0.8, 2.4);
    return distrib(gen);
}
