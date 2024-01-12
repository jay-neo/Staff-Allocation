#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <filesystem>

bool validCell(const std::string& str) {
    for (const char& ch : str) {
        if (!std::isspace(ch)) {
            return true;
        }
    }
    return false;
}

int string2int(const std::string& strOriginal) {
    std::string str = strOriginal;
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }), str.end());
    int res;
    std::istringstream(str) >> res;
    return res;
}

std::vector<std::string> split(const std::string& s,const char& delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool Done() {
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

void Fail() {
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

bool Error(const int& l) {
    std::cout << std::endl;
    std::cout << "Error-" << l;
    std::cerr << ": May be number of staffs is less than the required number" << std::endl;
    return false;
}

bool welcomeMsg(int &a, int &b) {
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





struct Staff {
    std::vector<std::string> Job;
    double total;
    int recent;
    int maxi;
    Staff(int m = 1) {
        total = 0;
        recent = 0;
        maxi = m;
    }
    void addJob(std::string work) {
        if (work == "" || work == "Reserve") {
            recent = 0;
        } else {
            recent = 1;
            total += (1.0 / static_cast<double>(maxi)) * 100.0;
        }
        Job.emplace_back(work);
    }
};

struct Work {
    std::string name;
    int value;
    Work(std::string _name, int _value) {
        name = _name;
        value = _value;
    }
};


class StaffAllocation {
    int staffType = 0;
    int jobType = 0;
    std::fstream  givenFile;
    std::fstream  outputFile;
    std::string inputFileName;
    const char* outputFileName;
    std::vector<std::pair<std::string, struct Staff>> staffs;
    std::vector<struct Work> currJobs;

public:
    StaffAllocation(std::string inputFilePath, const char* outputFilePath) : inputFileName(inputFilePath), outputFileName(outputFilePath){
        givenFile.open(inputFilePath, std::ios::in);
        outputFile.open(outputFileName, std::ios::out);
    }

    ~StaffAllocation() {
        givenFile.close();
        outputFile.close();
        staffs.clear();
        currJobs.clear();
    }

    void shuffle(const std::string& s) {
        std::random_device rd;
        std::mt19937 g(rd());
        if (s == "staffs") {
            std::shuffle(staffs.begin(), staffs.end(), g);
        }
        else if (s == "works") {
            std::shuffle(currJobs.begin(), currJobs.end(), g);
        }
    }

    void sortStaff() {
        std::sort(staffs.begin(), staffs.end(), [](const auto& lhs, const auto& rhs) {
            int left = lhs.second.total + (1.0 / static_cast<double>(lhs.second.maxi)) * 100.0;
            int right = rhs.second.total + (1.0 / static_cast<double>(rhs.second.maxi)) * 100.0;
            if (left != right)  {
                return left < right;
            }
            else {
                return lhs.second.recent < rhs.second.recent;
            }
        });
    }

    bool allocateSheet(const std::vector<std::vector<std::string>>& Sheet, int workLoad, const int& reservation, const int& ratio, const int& E) {
        int itr = 0;
        int totalStuffs = 0;
        int totalWorkload = 0;

        // Write Operation for Heading
        outputFile << Sheet[0][0] << ",";
        for(size_t i = 1 + staffType; i < Sheet.size(); i += (jobType + 1)) {
            outputFile << Sheet[i][0] << ",";
        }
        outputFile << std::endl;


        // Storing staffs name into staffs vector
        for(size_t i = 1; i < Sheet[0].size(); ++i) {
            if(staffType) {
                try {
                    int maxi = string2int(Sheet[1][i]);
                    staffs.emplace_back(Sheet[0][i], Staff(maxi));
                    totalWorkload += maxi;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument: " << e.what() << std::endl;
                    return Error(1);
                }

            } else {
                staffs.emplace_back(Sheet[0][i], Staff());
            }

            ++totalStuffs;
        }

        int day = (Sheet.size() - staffType - 1)/(jobType + 1);
        int totalRequirement = 0;
        std::vector<std::vector<struct Work>> totalJobs(day);


        // Storing jobs into totalJobs vector
        for (size_t c = 1 + staffType; c < Sheet.size(); c += (jobType + 1)) {
            int requirement = 0;
            for (size_t r = 1; r < Sheet[c].size(); ++r) {
                if(jobType) {
                    int workLoadEach = 1;
                    try {
                        int totalStudent = string2int(Sheet[c+1][r]);
                        double R = totalStudent / static_cast<double>(ratio);
                        if(R > 0) {
                            workLoadEach = static_cast<int>(R);
                            if(((R - workLoadEach) * 100) > E) {
                                workLoadEach += 1;
                            }
                        }
                        requirement += workLoadEach;

                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid argument: " << e.what() << std::endl;
                        return Error(2);
                    }
                    totalJobs[itr].emplace_back(Work(Sheet[c][r], workLoadEach));

                } else {
                    totalJobs[itr].emplace_back(Work(Sheet[c][r], workLoad));
                }
            }

            if ((!jobType && (workLoad * totalJobs[itr].size()) > totalStuffs) || (jobType && requirement > totalStuffs)) {
                return Error(3);
            }
            ++itr;
        }

        if ((staffType && jobType) && totalRequirement > totalWorkload) {
            std::cerr << "WARNING: Total requirement is larger than total workload of all stuffs.\n";
        }
       
        this->shuffle("staffs");
        day = 0;


        // Doing allocation here
        for (int j = 0; j < totalJobs.size(); ++j) {

            if (j > 0) {
                this->sortStaff();
            }

            currJobs = totalJobs[day];

            this->shuffle("works");

            itr = 0;
            for (int r = 0; r < currJobs.size(); ++r) {
                for (int i = 0; i < currJobs[r].value; ++i) {
                    if ((staffs[itr].second.total + (1.0 / static_cast<double>(staffs[itr].second.maxi)) * 100.0) > 100 && staffType) {
                        std::cout << ": Extra Job Alert: "  << staffs[itr].first << std::endl;
                        staffs[itr].second.addJob(currJobs[r].name + "*");
                    } else {
                        staffs[itr].second.addJob(currJobs[r].name);
                    }
                    ++itr;
                }
            }
            for (int i = 0; itr < staffs.size() && i < reservation; ++i) {
                staffs[itr].second.addJob("Reserve " + std::to_string(i+1));
                ++itr;
            }

            while (itr < staffs.size()) {
                staffs[itr++].second.addJob("");
            }

            currJobs.clear();
            ++day;
        }

        std::sort(staffs.begin(), staffs.end(), [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });


        // Final Write operation on Ouput Sheet
        for (itr = 0; itr < totalStuffs; ++itr) {
            outputFile << staffs[itr].first << ",";
            for (int i = 0; i < totalJobs.size(); ++i) {
                outputFile << staffs[itr].second.Job[i] << ",";

            }
            outputFile << std::endl;
        }

        outputFile << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        outputFile << ",This file is system generated! Designed by jay-neo (https://github.com/jay-neo)";

        totalJobs.clear();

        std::cout << std::endl;
        std::cout << ": The ratio of student per staff is " << ratio << " ± " << static_cast<int>((ratio * E) / 100.0) << std::endl;
        std::cout << ": The number of resarvation is " << reservation << std::endl;
        std::cout << ": Staff Allocation Complete." << std::endl;
        return Done();
    }

    void neo() {
        int a = 0, b = 0;
        if(welcomeMsg(a, b)) {
            if (!std::filesystem::exists(inputFileName)) {
                std::cerr << "\n\nThe prerequisite .csv file not found!!" << std::endl;
                Fail();
            }
        }
        staffType = a, jobType = b;
        if(!givenFile.is_open()){
            std::cerr << "Input CSV File(.csv) not found !!" << std::endl;
            std::cout << "Press any key to exit...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Fail();
            return;
        }

        int workLoad = 1;
        if (!jobType) {
            std::string str;
            std::cout << "\nEnter the integer value of stuff requirement for each work ---> ";
            std::cin >> str;
            workLoad = string2int(str);
        }

        std::string r;
        std::cout << "\nEnter the integer value of number of Reservation ---> ";
        std::cin >> r;

        std::string ratio;
        std::cout << "\nEnter the integer value of the number of students per staff ---> ";
        std::cin >> ratio;

        std::string E;
        std::cout << "\nEnter the integer value of manageable percentage per staff (in %) ---> ";
        std::cin >> E;

        std::cout << "\n\n\n###################################### Result ######################################\n";

        std::vector<std::vector<std::string>> Book;
        try {
            std::string line;
            while (getline(givenFile, line)){
                std::vector<std::string> row = split(line, ',');
                for (size_t i = 0; i < row.size(); ++i) {
                    if (i >= Book.size()) {
                        Book.push_back(std::vector<std::string>());
                    }
                    if (validCell(row[i])){
                        Book[i].push_back(row[i]);
                    }
                }
            }

            givenFile.close();
            if(!allocateSheet(Book, workLoad, string2int(r), string2int(ratio), string2int(E))) {
                outputFile.close();
                std::remove(outputFileName);
                Fail();
            }

        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            std::cout << "Type 'exit' to exit from the program ----> ";
            outputFile.close();
            std::remove(outputFileName);
            Fail();
        }
    }
};




int main(int argc, char const* argv[]) {

    std::string exePath = std::filesystem::path(argv[0]).parent_path().string();
    std::string givenFilePath = exePath + "/" + std::filesystem::path(argv[0]).stem().string() + ".csv";

    StaffAllocation jay(givenFilePath, "Output_File.csv");
    jay.neo();

    return 0;
}


// code by jay-neo