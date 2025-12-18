#pragma once
#include <iostream>
#include <limits>

template<typename T>
void getValidatedInput(T& value, const char* prompt = "Enter a number: ") {
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
