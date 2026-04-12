#include "../include/utils/InputHelper.h"
#include <iostream>

int InputHelper::inputInt(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore();
            return value;
        }
        std::cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        std::cin.clear();
        std::cin.ignore();
    }
}

double InputHelper::inputDouble(const std::string& prompt, double minValue, double maxValue) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore();
            return value;
        }
        std::cout << "Gia tri khong hop le. Vui long nhap lai.\n";
        std::cin.clear();
        std::cin.ignore();
    }
}

std::string InputHelper::inputLine(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}