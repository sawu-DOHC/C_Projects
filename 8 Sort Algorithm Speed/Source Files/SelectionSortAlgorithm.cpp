#include "../Header Files/SelectionSortAlgorithm.h"
#include <chrono>
#include <algorithm>  // For std::swap

// Constructor
SelectionSortAlgorithm::SelectionSortAlgorithm()
        : SortAlgorithm("Selection Sort") {}

// Override the sort method
void SelectionSortAlgorithm::sort(const std::vector<int>& data) {
    int size = data.size();
    int* array = new int[size];

    // Copy data to a dynamically allocated array
    std::copy(data.begin(), data.end(), array);

    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    for (int step = 0; step < size - 1; ++step) {
        int minIndex = step;
        for (int i = step + 1; i < size; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        if (minIndex != step) {
            std::swap(array[minIndex], array[step]);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Reset the array to its original state before the stats run
    std::copy(data.begin(), data.end(), array);

    // Stats run
    for (int step = 0; step < size - 1; ++step) {
        int minIndex = step;
        for (int i = step + 1; i < size; ++i) {
            this->iterations++;
            this->arrayAccesses += 2;
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        if (minIndex != step) {
            std::swap(array[minIndex], array[step]);
            this->swaps++;
            this->arrayAccesses += 2;
        }
    }

    // Clean up the dynamically allocated array
    delete[] array;
}
