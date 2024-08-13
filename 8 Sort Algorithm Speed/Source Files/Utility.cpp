#include "../Header Files/Utility.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to load data from a file
int* loadData(const std::string& filePath) {
    ifstream inputFileStream(filePath);
    string line;
    vector<int> data;

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
    int arraySize = data.size();
    int* array = new int[arraySize];

    for (size_t i = 0; i < arraySize; ++i) {
        array[i] = data[i];
    }

    return array;
}


void measurePerformance( SortAlgorithm& sortAlgorithm, int* array, int arraySize ) {

    int* arrayCopy = new int[arraySize];

    std::copy(array, array + arraySize, arrayCopy);

    auto start = std::chrono::high_resolution_clock::now();

    // Get the enum value directly
    SortAlgorithm::AlgorithmName algorithmName = algorithmName;

    // Use a switch statement to select the algorithm
    switch ( algorithmName ) {

        case SortAlgorithm::SELECTION_SORT:
            sortAlgorithm.selectionSort(arrayCopy, arraySize);
            break;

        case SortAlgorithm::BUBBLE_SORT:
            sortAlgorithm.bubbleSort(arrayCopy, arraySize);
            break;

        case SortAlgorithm::QUICKSORT:
            sortAlgorithm.quicksort(arrayCopy, 0, arraySize - 1);
            break;

        case SortAlgorithm::QUICKSORT_ITERATIVE:
            sortAlgorithm.quicksortIterative(arrayCopy, 0, arraySize - 1);
            break;

        case SortAlgorithm::INSERTION_SORT:
            sortAlgorithm.insertionSort(arrayCopy, 0, arraySize - 1);
            break;

        case SortAlgorithm::MERGE_SORT:
            sortAlgorithm.mergeSort(arrayCopy, 0, arraySize - 1);
            break;

    }

    delete[] arrayCopy;
}

void printData(const SortAlgorithm& sortAlgorithm) {
    std::cout << "Algorithm: " << sortAlgorithm.getAlgorithmNameAsString() << std::endl;
    std::cout << "Execution Time: " << sortAlgorithm.executionTime << " microseconds" << std::endl;
    std::cout << "Iterations: " << sortAlgorithm.iterations << std::endl;
    std::cout << "Swaps: " << sortAlgorithm.swaps << std::endl;
    std::cout << "Array Accesses: " << sortAlgorithm.arrayAccesses << std::endl;
    std::cout << "-------------------------------" << std::endl;
}