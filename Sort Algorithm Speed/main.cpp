#include <iostream>
#include <chrono>
#include "Header Files/SortAlgorithms.h"
#include "Header Files/Utility.h"

using namespace std;
using namespace std::chrono;

int main() {
    SortAlgorithms newSortAlgorithm;

    int arraySize;
    int* array = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/Sort Algorithm Speed/Test Data/Sorted.txt", arraySize);

    if (array == nullptr) {
        return 1; // Exit if the data loading failed
    }

    // Measure time taken by quicksort
    int* quicksortArray = new int[arraySize];
    std::copy(array, array + arraySize, quicksortArray);
    auto start = high_resolution_clock::now();
    newSortAlgorithm.quicksort(quicksortArray, 0, arraySize - 1);
    auto end = high_resolution_clock::now();
    auto quicksortDuration = duration_cast<microseconds>(end - start);

    cout << "Quicksort duration: " << quicksortDuration.count() << " microseconds" << endl;

    // Clean up dynamic memory
    delete[] array;
    delete[] quicksortArray;

    return 0;
}
