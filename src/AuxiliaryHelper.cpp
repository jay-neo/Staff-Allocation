#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <AuxiliaryHelper.h>


bool AuxiliaryHelper::welcomeMsg(int &a, int &b){
    std::string msg = "0";
    std::cout << std::endl;
    std::cout << "      #################################################" << std::endl;
    std::cout << "      #      Enter the submitted staff's type         #" << std::endl;
    std::cout << "      #      Type 1 : Staffs with unlimited worklife  #" << std::endl;
    std::cout << "      #      Type 2 : Staffs with limited worklife    #" << std::endl;
    std::cout << "      #      Type 0 : Exit from the program           #" << std::endl;
    std::cout << "      #################################################" << std::endl;
    std::cout << "      Enter your choice ---------> ";
    while (msg != "1" || msg != "2") {
        std::cin >> msg;
        if (msg == "1") {
            a = 0; break;
        }
        else if (msg == "2") {
            a = 1; break;
        }
        else if (msg == "0") {
            return false;
        }
        std::cout << "Enter your valid choice as integer value ---> ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "      ########################################################" << std::endl;
    std::cout << "      #      Enter the submitted job's type                  #" << std::endl;
    std::cout << "      #      Type 1 : Each job with equal requirement        #" << std::endl;
    std::cout << "      #      Type 2 : Each job with different requirement    #" << std::endl;
    std::cout << "      #      Type 0 : Exit from the program                  #" << std::endl;
    std::cout << "      ########################################################" << std::endl;
    std::cout << "      Enter your choice ---------> ";
    while (msg != "1" || msg != "2") {
        std::cin >> msg;
        if (msg == "1") {
            b = 0; break;
        }
        else if (msg == "2") {
            b = 1; break;
        }
        else if (msg == "0") {
            return false;
        }
        std::cout << "Enter your valid choice as integer value ---> ";
    }
    std::cout << std::endl << std::endl;

    int j = 0;
    std::cout << "Prerequisites:" << std::endl << std::endl;
    std::cout << "1. CSV UTF-8 Comma delimited(.csv) file should be formatted like this:\n" << std::endl;
    std::cout << "###############";
    if (a) {
        std::cout << "###############";
    }
    for (int j = 1; j <= 3; ++j) {
        std::cout << "###############";
        if (b) {
            std::cout << "###############";
        }
    }
    std::cout << std::endl;
    std::cout << "#   Staff Name  #";
    if (a) {
        std::cout << "  WorkLoad   #";
    }
    for (int j = 1; j <= 3 ; ++j) {
        std::cout << "     Day " << j << "   #";
        if (b) {
            std::cout << " Requirement  #";
        }
    }
    std::cout << std::endl;
    int itr = 1;
    for (int i = 0; i <= 14; ++i) {
        if (i % 2 == 0) {
            std::cout << "###############";
            if (a) {
                std::cout << "###############";
            }
            for (int j = 1; j <= 3; ++j) {
                std::cout << "###############";
                if (b) {
                    std::cout << "###############";
                }
            }
        }
        else {
            std::cout << "#   Person " << itr << "    #";
            if (a) {
                std::cout << "  Integer " << itr << "  #";
            }
            for (int j = 1; j <= 3; ++j) {
                std::cout << "     Job " << itr << "   #";
                if (b) {
                    std::cout << " Integer " << itr << "    #";
                }
            }
            ++itr;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "2. The CSV file name should be same name as the execution file(.exe)" << std::endl << std::endl;

    while (msg != "jay-neo") {
        std::cout << "If you understand the prerequisites and continue the program then type password" << std::endl;
        std::cout << "else if you consider to exit then type 'exit' -------> ";
        std::cin >> msg;
        std::transform(msg.begin(), msg.end(), msg.begin(), [](unsigned char c) {return std::tolower(c); });
        if (msg == "exit") {
            return false;
        }
    }
    return true;
}

bool AuxiliaryHelper::validCell(const std::string& str) {
    for (const char& ch : str) {
        if (!std::isspace(ch)) {
            return true;
        }
    }
    return false;
}

int AuxiliaryHelper::string2int(const std::string& strOriginal) {
    std::string str = strOriginal;
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }), str.end());
    int res;
    std::istringstream(str) >> res;
    return res;
}

std::vector<std::string> AuxiliaryHelper::split(const std::string& s,const char& delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool AuxiliaryHelper::Error(const int& l){
    std::cout << std::endl;
    std::cout << "Error-" << l;
    std::cerr << ": May be number of staffs is less than the required number" << std::endl;
    return false;
}

bool AuxiliaryHelper::Done() {
    std::cout << std::endl << std::endl;
    std::cout << "               ####     ####   #    #  ####### " << std::endl;
    std::cout << "               #   #   #    #  ##   #  #       " << std::endl;
    std::cout << "               #    #  #    #  # #  #  #####   " << std::endl;
    std::cout << "               #    #  #    #  #  # #  #       " << std::endl;
    std::cout << "               #   #   #    #  #   ##  #       " << std::endl;
    std::cout << "               ####     ####   #    #  ######  " << std::endl;
    std::cout << std::endl << std::endl;
    std::string msg;
    std::cout << "Type 'exit' to exit from the program ----> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> msg;
    return true;
}

void AuxiliaryHelper::Fail() {
    std::cout << std::endl << std::endl;
    std::cout << "               ########   ####     #   #        " << std::endl;
    std::cout << "               ##        #    #    #   #        " << std::endl;
    std::cout << "               ######   ########   #   #        " << std::endl;
    std::cout << "               #        ###    #   #   #        " << std::endl;
    std::cout << "               #        #      #   #   #        " << std::endl;
    std::cout << "               #        #      #   #   ######## " << std::endl;
    std::cout << std::endl << std::endl;
    std::string msg;
    std::cout << "Type 'exit' to exit from the program ----> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> msg;
}

