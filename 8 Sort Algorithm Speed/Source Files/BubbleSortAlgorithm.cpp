#include "../Header Files/BubbleSortAlgorithm.h"
#include <algorithm>  // For std::copy
#include <chrono>

// Constructor
BubbleSortAlgorithm::BubbleSortAlgorithm()
        : SortAlgorithm("Bubble Sort") {}

// Override the sort method
void BubbleSortAlgorithm::sort(const std::vector<int>& data) {
    int size = data.size();
    int* array = new int[size];

    // Copy data to a dynamically allocated array
    std::copy(data.begin(), data.end(), array);

    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    for (int step = 0; step < size - 1; ++step) {
        bool swapped = false;
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Reset the array to its original state before the stats run
    std::copy(data.begin(), data.end(), array);

    // Stats run
    for (int step = 0; step < size - 1; ++step) {
        bool swapped = false;  // Track if any swaps were made during this step
        for (int i = 0; i < size - step - 1; ++i) {
            this->iterations++;
            this->arrayAccesses += 2;
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                this->swaps++;
                this->arrayAccesses += 2;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    // Clean up the dynamically allocated array
    delete[] array;
}
