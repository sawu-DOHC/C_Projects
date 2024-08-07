#include "../Header Files/Utility.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;


int* loadData(const std::string& filePath, int& arraySize) {
    ifstream inputFileStream(filePath);
    string line;
    vector<int> data;

    // Check if the file is open
    if (!inputFileStream.is_open()) {
        cerr << "Unable to open file " << filePath << endl;
        arraySize = 0;
        return nullptr;
    }

    // Read lines from the file and parse
    while ( getline(inputFileStream, line) ) {
        istringstream iss( line );
        int number;
        while (iss >> number) {
            data.push_back(number);
        }
    }

    inputFileStream.close();

    // Allocate the array dynamically on the heap
    arraySize = data.size();
    int* array = new int[arraySize];
    for (size_t i = 0; i < arraySize; ++i) {
        array[i] = data[i];
    }

    return array;
}