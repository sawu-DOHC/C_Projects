#include "../Header Files/Utility.h"
#include "../Header Files/SortAlgorithm.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to load data from a file
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
    while (getline(inputFileStream, line)) {
        istringstream iss(line);
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

// Function to measure the performance of sorting algorithms
void measureSortPerformance(SortAlgorithm& sortAlgorithm, int* array, int arraySize) {
    int* arrayCopy = new int[arraySize];
    std::copy(array, array + arraySize, arrayCopy);

    auto start = high_resolution_clock::now();

    const std::string& algorithmName = sortAlgorithm.getAlgorithmName();
    if (algorithmName == "Selection Sort") {
        sortAlgorithm.selectionSort(arrayCopy, arraySize);
    } else if (algorithmName == "Bubble Sort") {
        sortAlgorithm.bubbleSort(arrayCopy, arraySize);
    } else if (algorithmName == "Quicksort") {
        sortAlgorithm.quicksort(arrayCopy, 0, arraySize - 1);
    } else if (algorithmName == "Iterative Quicksort") {
        sortAlgorithm.quicksortIterative(arrayCopy, 0, arraySize - 1);
    } else if (algorithmName == "Insertion Sort") {
        sortAlgorithm.insertionSort(arrayCopy, 0, arraySize - 1);
    } else if (algorithmName == "Merge Sort") {
        sortAlgorithm.mergeSort(arrayCopy, 0, arraySize - 1);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << sortAlgorithm.getAlgorithmName() << " duration: " << duration.count() << " microseconds" << endl;

    delete[] arrayCopy;
}
