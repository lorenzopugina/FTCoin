#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    static void showSuccess(const std::string& text);
    static void showError(const std::string& text);
};

#endif // MESSAGE_H
