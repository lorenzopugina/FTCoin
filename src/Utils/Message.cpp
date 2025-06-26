#include "Message.h"
#include <iostream>

void Message::showSuccess(const std::string& text) {
    std::cout << "\033[32m" << text << "\033[0m" << std::endl; // Green and rest default color
}

void Message::showError(const std::string& text) {
    std::cout << "\033[31m" << text << "\033[0m" << std::endl; // Red and reset default color
}
