#include <iostream>
#include <chrono>
#include "Header Files/SearchAlgorithms.h"
#include "Header Files/Utility.h"

using namespace std;
using namespace std::chrono;

int main() {

    SearchAlgorithms newSearchAlgorithm;


    int arraySize;
    int* array = loadData( "C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/Search Algorithm Speed/Test Data/searchAlgorithmData.txt", arraySize );

    if (array == nullptr) {
        return 1; // Exit if the data loading failed
    }

    int searchValue = 999999;

    // Measure time taken by linear search and count iterations
    auto start = high_resolution_clock::now();
    int* linearResult = newSearchAlgorithm.linearSearch(array, arraySize, searchValue);
    auto end = high_resolution_clock::now();
    auto linearDuration = duration_cast<microseconds>(end - start);

    // Measure time taken by binary search and count iterations
    start = high_resolution_clock::now();
    int* binaryResult = newSearchAlgorithm.binarySearch(array, arraySize, searchValue);
    end = high_resolution_clock::now();
    auto binaryDuration = duration_cast<microseconds>(end - start);

    cout << "Linear search result: Index=" << linearResult[0] << ", Iterations=" << linearResult[1] << " (Time taken: " << linearDuration.count() << " microseconds)" << endl;
    cout << "Binary search result: Index=" << binaryResult[0] << ", Iterations=" << binaryResult[1] << " (Time taken: " << binaryDuration.count() << " microseconds)" << endl;

    // Clean up dynamic memory
    delete[] array;
    delete[] linearResult;
    delete[] binaryResult;

    return 0;
}
