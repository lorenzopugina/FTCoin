#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Menu {
	private:
	
		const string titulo;
		vector<string> &items;

		bool escolhaValida(escolha);
	public:
	
		Menu(const string titulo = "Menu", vector<MenuItem> items);

		~Menu();

		int getEscolha();

		void decorarSeparacao();

  		void run();
		
	};

#endif /* MENU_H_ */
