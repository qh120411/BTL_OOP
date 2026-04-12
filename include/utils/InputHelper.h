#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>

class InputHelper {
public:
    static int inputInt(const std::string&, int, int);
    static double inputDouble(const std::string&, double, double);
    static std::string inputLine(const std::string&);
    static std::string inputDate(const std::string&);
};

#endif