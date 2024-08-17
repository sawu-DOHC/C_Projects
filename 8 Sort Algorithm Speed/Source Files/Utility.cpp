#include "../Header Files/Utility.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to load data from a file

std::vector<int> loadData(const std::string& filePath) {
    std::ifstream inputFileStream(filePath);
    std::string line;
    std::vector<int> data;

    // Read lines from the file and parse
    while (std::getline(inputFileStream, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            data.push_back(number);
        }
    }
    inputFileStream.close();

    return data;  // Return the vector directly
}

