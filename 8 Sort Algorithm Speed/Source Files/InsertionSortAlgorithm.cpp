#include "../Header Files/InsertionSortAlgorithm.h"
#include <algorithm>
#include <chrono>

// Constructor
InsertionSortAlgorithm::InsertionSortAlgorithm()
        : SortAlgorithm("Insertion Sort") {}

// Override the sort method
void InsertionSortAlgorithm::sort(const std::vector<int>& data) {
    int size = data.size();
    int* array = new int[size];

    // Copy data to a dynamically allocated array
    std::copy(data.begin(), data.end(), array);

    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Reset the array to its original state before the stats run
    std::copy(data.begin(), data.end(), array);

    // Stats run
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            this->iterations++;
            this->arrayAccesses += 2;

            array[j + 1] = array[j];
            j = j - 1;

            this->arrayAccesses++;
        }
        array[j + 1] = key;

        this->arrayAccesses++;
    }

    delete[] array;
}
