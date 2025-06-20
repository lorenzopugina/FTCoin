#include "Oracle.h"
#include <stdexcept>

void Oracle::addExchangeRate(const Date& date, double rate) {
    if (rate < 0) {
        throw std::invalid_argument("Exchange rate cannot be negative");
    }
    exchangeRates[date] = rate;
}

double Oracle::getExchangeRate(const Date& date) const {
    auto it = exchangeRates.find(date);
    if (it == exchangeRates.end()) {
        throw std::out_of_range("No exchange rate found for " + date.toString());
    }
    return it->second;
}

bool Oracle::hasExchangeRate(const Date& date) const {
    return exchangeRates.find(date) != exchangeRates.end();
}

bool Oracle::removeExchangeRate(const Date& date) {
    return exchangeRates.erase(date) > 0;
}

void Oracle::clearAllRates() {
    exchangeRates.clear();
}

size_t Oracle::getRateCount() const {
    return exchangeRates.size();
}
