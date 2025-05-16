#include <iostream>
#include <vector>
#include "Menu.h"

using namespace std;

Menu::Menu(const string& titulo, vector<MenuItem>& items): titulo(titulo), items(items) {}

Menu::~Menu(){
  // por enquanto nada
}

int Menu::getEscolha(){
  // implementar tratamento de excessão
  do
  {
   //todo
  } while (escolhaValida());
  
}

bool Menu::escolhaValida(escolha){
  //arrumar
  return ((escolha < 0) || (escolha > quantItems - 1)); 
}

void Menu::decorarSeparacao(){
  // verificar 
  cout << "========================================" << endl;
}

void Menu::run(){
  // todo
}

// lembrar q tem a opçao sair