#include <iostream>
#include <filesystem>
#include <StaffAllocation.h>

int main(int argc, char const* argv[]) {
    std::string exePath = std::filesystem::path(argv[0]).parent_path().string();
    std::string givenFilePath = exePath + "/" + std::filesystem::path(argv[0]).stem().string() + ".csv";

    StaffAllocation jay(givenFilePath, "Output_File.csv");
    jay.neo();

    return 0;
}

// code by jay-neo