#ifndef CARTEIRA_HPP
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
    //construtores
    Carteira();
    Carteira(int id, const string& titular, const string& corretora);
    
    //destrutor
    ~Carteira();

//getters
int getId() const;
string getNomeTitular() const;
string getCorretora() const;

//setters
void setId(int id);
void setNomeTitular(const string& newtitular);
void setCorretora(const string& newcorretora);

 // Validação do model
bool estaValida() const;
};

#endif
