#ifndef HELP_H
#define HELP_H

#include <string>

class Help {
public:
    Help(const std::string& filePath);
    void display() const;

private:
    std::string path;
};

#endif // HELP_H
