#!/bin/bash
if ! command -v cmake &> /dev/null; then
    echo "    ##################################"
    echo "    #     CMake is not installed.    #"
    echo "    ##################################"
    read -p "    Do you want to install cmake? [Y/n]: " choice
    
    if ! [[ "$choice" =~ ^[Nn]$ ]]; then
        echo "Installing CMake..."
        
        if command -v apt-get &> /dev/null; then
            sudo apt-get update
            sudo apt-get install cmake
        elif command -v yum &> /dev/null; then
            sudo yum install cmake
        elif command -v dnf &> /dev/null; then
            sudo dnf install cmake
        elif command -v pacman &> /dev/null; then
            sudo pacman -Syu cmake
        else
            echo "Unsupported package manager. Please install CMake manually."
            exit 1
        fi
        echo "CMake has been installed."
    else
        echo "Before running this program, make sure CMake is installed on your machine."
	    exit 1
    fi

fi

if [ -d "Build" ]; then
    echo "'Build' repository is already present!"
    read -p "Do you want to delete it? [Y/n]: " choice
    if [[ "$choice" =~ ^[Nn]$ ]]; then
        echo "Deleting existing 'Build' folder..."
        rm -rf Build
    else
        return;
    fi
fi

cmake -B build
cd build
make
cd ..

cp Automated-Job-Allocator.csv bin/
./bin/Automated-Job-Allocator
