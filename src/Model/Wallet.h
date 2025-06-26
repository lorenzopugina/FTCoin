#ifndef WALLET_H
#define WALLET_H

#include <string>
using namespace std;

class Wallet 
{
    private:
        int id;
        string holderName;
        string brokerage;
        static int counter;

    public:
        Wallet(const string& holder, const string& brokerage);
        ~Wallet();

        int getId() const;
        string getHolder() const;
        string getBrokerage() const;

        void setId(); 
        void setHolder(const string& newHolder);
        void setBrokerage(const string& newBrokerage);
};

#endif
