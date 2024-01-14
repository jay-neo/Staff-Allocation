cmake_minimum_required(VERSION 3.22)

project (Automated-Job-Allocator)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(Automated-Job-Allocator
    main.cpp
    src/StaffAllocation.cpp
    src/AuxiliaryHelper.cpp
)

target_include_directories(Automated-Job-Allocator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
