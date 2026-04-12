#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>

class InputHelper {
public:
    static int inputInt(const std::string& prompt, int minValue = -2147483647, int maxValue = 2147483647);
    static double inputDouble(const std::string& prompt, double minValue = -1e18, double maxValue = 1e18);
    static std::string inputLine(const std::string& prompt);
};

#endif