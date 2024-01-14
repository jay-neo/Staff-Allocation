#ifndef STAFFALLOCATION_H
#define STAFFALLOCATION_H

#include <fstream>
#include <vector>
#include <string>

struct Staff {
    std::vector<std::string> Job;
    double total;
    int recent;
    int maxi;
    Staff(int);
    void addJob(const std::string&);
};

struct Work{
    std::string name;
    int value;
    Work(const std::string&, const int&);
};


class StaffAllocation {
    int staffType;
    int jobType;
    std::fstream  givenFile;
    std::fstream  outputFile;
    std::string inputFileName;
    const char* outputFileName;
    std::vector<std::pair<std::string, struct Staff>> staffs;
    std::vector<struct Work> currJobs;

public:
    StaffAllocation(std::string, const char*);
    ~StaffAllocation();
    void shuffle(const std::string&);
    void sortStaff();
    bool allocateSheet(const std::vector<std::vector<std::string>>&, int, const int&, const int&, const int&);
    void neo();

};

#endif