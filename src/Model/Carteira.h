#ifndef CARTEIRA_HPP // revisar se é somente H
#define CARTEIRA_HPP

#include <string>

using namespace std;

class Carteira 
{
private:
    int id;
    string nomeTitular;
    string corretora;

public:
    Carteira(); // ?
    Carteira(int id, const string& titular, const string& corretora);
    
    ~Carteira();

    int getId() const;
    string getTitular() const;
    string getCorretora() const;

    void setId(int id); // ?
    void setTitular(const string& newTitular);
    void setCorretora(const string& newCorretora);

    // Validação do model
    bool estaValida() const;
};

#endif