#ifndef CARTEIRA_H
#define CARTEIRA_H

#include <string>

using namespace std;

class Carteira 
{
private:
    int id;
    string nomeTitular;
    string corretora;
    static int cont;

public:
    Carteira(const string& titular, const string& corretora);

    ~Carteira();

    int getId() const;
    string getTitular() const;
    string getCorretora() const;

    void setId(); 
    void setTitular(const string& newTitular);
    void setCorretora(const string& newCorretora);
};

#endif