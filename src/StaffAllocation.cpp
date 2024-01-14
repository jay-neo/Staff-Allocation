#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <filesystem>
#include <AuxiliaryHelper.h>
#include <StaffAllocation.h>

Staff::Staff(int m = 1) : total(0), recent(0), maxi(m) { Job; }

void Staff::addJob(const std::string& work) {
    if (work == "" || work == "Reserve") {
        recent = 0;
    } else {
        recent = 1;
        total += (1.0 / static_cast<double>(maxi)) * 100.0;
    }
    Job.emplace_back(work);
}

Work::Work(const std::string& _name,const int& _value) : name(_name), value(_value) { }

StaffAllocation::StaffAllocation(std::string inputFilePath, const char* outputFilePath) : inputFileName(inputFilePath), outputFileName(outputFilePath){
    staffType; jobType;
    staffs; currJobs;
    givenFile.open(inputFilePath, std::ios::in);
}

StaffAllocation::~StaffAllocation() {
        givenFile.close();
        outputFile.close();
        staffs.clear();
        currJobs.clear();
    }

void StaffAllocation::shuffle(const std::string& s){
    std::random_device rd;
    std::mt19937 g(rd());
    if (s == "staffs") {
        std::shuffle(staffs.begin(), staffs.end(), g);
    }
    else if (s == "works") {
        std::shuffle(currJobs.begin(), currJobs.end(), g);
    }
}

void StaffAllocation::sortStaff() {
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

bool StaffAllocation::allocateSheet(const std::vector<std::vector<std::string>>& Sheet, int workLoad, const int& reservation, const int& ratio, const int& E) {
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
                int maxi = AuxiliaryHelper::string2int(Sheet[1][i]);
                staffs.emplace_back(Sheet[0][i], Staff(maxi));
                totalWorkload += maxi;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
                return AuxiliaryHelper::Error(1);
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
                    int totalStudent = AuxiliaryHelper::string2int(Sheet[c+1][r]);
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
                    return AuxiliaryHelper::Error(2);
                }
                totalJobs[itr].emplace_back(Work(Sheet[c][r], workLoadEach));

            } else {
                totalJobs[itr].emplace_back(Work(Sheet[c][r], workLoad));
            }
        }

        if ((!jobType && (workLoad * totalJobs[itr].size()) > totalStuffs) || (jobType && requirement > totalStuffs)) {
            return AuxiliaryHelper::Error(3);
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
    return AuxiliaryHelper::Done();
}

void StaffAllocation::neo() {
    int a = 0, b = 0;
    if(AuxiliaryHelper::welcomeMsg(a, b)) {
        if (!std::filesystem::exists(inputFileName)) {
            std::cerr << "\n\nThe prerequisite .csv file is not found!!" << std::endl;
            AuxiliaryHelper::Fail();
        }
    }
    staffType = a, jobType = b;
    if(!givenFile.is_open()){
        std::cerr << "\n\nThe prerequisite .csv file is not opening!!" << std::endl;
        AuxiliaryHelper::Fail();
        return;
    }

    int workLoad = 1;
    if (!jobType) {
        std::string str;
        std::cout << "\nEnter the integer value of stuff requirement for each work ---> ";
        std::cin >> str;
        workLoad = AuxiliaryHelper::string2int(str);
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
        outputFile.open(outputFileName, std::ios::out);
        std::string line;
        while (getline(givenFile, line)){
            std::vector<std::string> row = AuxiliaryHelper::split(line, ',');
            for (size_t i = 0; i < row.size(); ++i) {
                if (i >= Book.size()) {
                    Book.push_back(std::vector<std::string>());
                }
                if (AuxiliaryHelper::validCell(row[i])){
                    Book[i].push_back(row[i]);
                }
            }
        }

        givenFile.close();
        if(!allocateSheet(Book, workLoad, AuxiliaryHelper::string2int(r), AuxiliaryHelper::string2int(ratio), AuxiliaryHelper::string2int(E))) {
            outputFile.close(); std::remove(outputFileName); AuxiliaryHelper::Fail();
        }

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        std::cout << "Type 'exit' to exit from the program ----> ";
        outputFile.close(); std::remove(outputFileName); AuxiliaryHelper::Fail();
    }
}
