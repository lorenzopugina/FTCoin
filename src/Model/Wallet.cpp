#include "Wallet.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int Wallet::counter = 1;

Wallet::Wallet(const string& holder, const string& brokerage) {
    setId();
    setHolder(holder);
    setBrokerage(brokerage);
}

Wallet::~Wallet() {}

int Wallet::getId() const { return id; }
string Wallet::getHolder() const { return holderName; }
string Wallet::getBrokerage() const { return brokerage; }

void Wallet::setId() {
    id = counter++;

    cout << "\033[2J\033[H"; // clear screen
    cout << "Wallet status with id: " << id << endl;
}

void Wallet::setHolder(const string& holder) {
    if (holder.empty()) {
        throw invalid_argument("Holder name cannot be empty");
    }
    holderName = holder;
}

void Wallet::setBrokerage(const string& brokerageName) {
    if (brokerageName.empty()) {
        throw invalid_argument("Brokerage cannot be empty");
    }
    brokerage = brokerageName;
}
