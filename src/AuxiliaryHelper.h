#ifndef AUXILIARYHELPER_H
#define AUXILIARYHELPER_H

#include <string>
#include <vector>

class AuxiliaryHelper {
public:
    static bool welcomeMsg(int&, int&);
    static bool validCell(const std::string&);
    static int string2int(const std::string&);
    static std::vector<std::string> split(const std::string&, const char&);
    static bool Error(const int&);
    static bool Done();
    static void Fail();
};

#endif