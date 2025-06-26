#include "Help.h"
#include <iostream>
#include <fstream>

using namespace std;

Help::Help(const string& filePath) : path(filePath) {}

void Help::display() const {
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Error: Could not open help file: " << path << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}
