#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>

using namespace std;

class Menu final
{
private:
    vector<string>& itens;

    string title;
    string message;

    string symbol;
    int width;
    bool repeatList;
    bool zeroForLastOpt;

    bool isNotAValidChoice(unsigned long choice) const;
    string replicate(string text, int times) const;
    string makeDecorator();

public:
    Menu(vector<string>& itens, string title = "Menu", string message = "Option: ");
    virtual ~Menu();

    int getChoice();
    void setDecorator(const string& decorator, int width);

    const string& getDecorator() const;
    const string& getMessage() const;
    int getLength() const;
    void setMessage(const string& message);
    bool isRepeatList() const;
    void setRepeatList(bool repeatList = false);
    string getSymbol() const;
    void setSymbol(const string& symbol = "-");
    const string& getTitle() const;
    void setTitle(const string& title);
    int getWidth() const;
    void setWidth(int width = 0);
    bool isZeroForLastOpt() const;
    void setZeroForLastOpt(bool zeroForLastOpt = true);
};

#endif /* MENU_H_ */
