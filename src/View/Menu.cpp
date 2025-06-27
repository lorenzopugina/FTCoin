#include <math.h>
#include "Menu.h"

using namespace std;

Menu::Menu(vector<string>& itens, string title, string message) :
    itens(itens), title(title), message(message)
{
    this->setWidth();
    this->setSymbol();
    this->setZeroForLastOpt();
    this->setRepeatList();
}

void Menu::setDecorator(const string& symbol, int width)
{
    this->symbol = symbol;
    this->width = width;
}

int Menu::getChoice()
{
    unsigned long choice;
    bool firstTime = true;
    string decorator = makeDecorator();

    do {
        if (repeatList || firstTime) {
            unsigned long index = 0;

            cout << decorator << endl;
            cout << "\033[33m" << title << endl << "\033[0m";  // yellow and default color
            cout << decorator << endl;

            for (index = 0; index < (itens.size() - (zeroForLastOpt ? 1 : 0)); index++) {
                cout << (index + 1) << " - " << itens.at(index) << endl;
            }
            cout << decorator << endl;

            if (zeroForLastOpt) {
                cout << 0 << " - " << itens.at(index) << endl;
                cout << decorator << endl;
            }

            firstTime = false;
        }
        cout << message << endl;
        cin >> choice;

    } while (isNotAValidChoice(choice));
    cin.ignore();

    if (zeroForLastOpt && choice == 0) {
        return itens.size() - 1; // Retorna o índice do último item, que é o "Sair"
    } else {
        return choice - 1; // As outras opções são mapeadas normalmente (1 → 0, 2 → 1, etc.)
    }
}

string Menu::makeDecorator()
{
    if (!width)
    {
        width = max(title.length(), message.length());

        for (string item : itens) {
            width = ((unsigned long int)width >= item.length()) ? width : item.length();
        }
        width += 4 + (log10(itens.size()));
        width = (width / symbol.length()) + ((width % symbol.length()) ? 1 : 0);
    }
    return (replicate(symbol, width));
}

bool Menu::isNotAValidChoice(unsigned long choice) const
{
    if (zeroForLastOpt) {
        bool validation = (choice > itens.size() - 1);
        if (validation == 0) {
            cout << "\033c"; // clears the screen to display the next menu
        }

        return validation;
    } else {
        bool validation = (choice < 1 || choice > itens.size());
        if (validation == 0) {
            cout << "\033c"; // clears the screen to display the next menu
        }
        return validation;
    }
}

string Menu::replicate(string text, int times) const
{
    string buffer;
    for (int count = 0; count < times; count++) {
        buffer += text;
    }
    return (buffer);
}

int Menu::getLength() const { return (itens.size()); }
const string& Menu::getMessage() const { return message; }
string Menu::getSymbol() const { return symbol; }
const string& Menu::getTitle() const { return title; }
int Menu::getWidth() const { return width; }

void Menu::setMessage(const string& message) { this->message = message; }
void Menu::setSymbol(const string& symbol) { this->symbol = symbol; }
void Menu::setTitle(const string& title) { this->title = title; }
void Menu::setWidth(int width) { this->width = width; }

bool Menu::isRepeatList() const { return repeatList; }
void Menu::setRepeatList(bool repeatList) { this->repeatList = repeatList; }

bool Menu::isZeroForLastOpt() const { return zeroForLastOpt; }
void Menu::setZeroForLastOpt(bool zeroForLastOpt) { this->zeroForLastOpt = zeroForLastOpt; }

Menu::~Menu() {}
