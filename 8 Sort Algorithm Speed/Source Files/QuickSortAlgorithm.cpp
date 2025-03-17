#include "../Header Files/QuickSortAlgorithm.h"
#include <chrono>
#include <algorithm>

// Constructor
QuickSortAlgorithm::QuickSortAlgorithm()
        : SortAlgorithm("Quicksort") {}

// Override the sort method
void QuickSortAlgorithm::sort(const std::vector<int>& data) {
    int size = data.size();
    int* array = new int[size];

    // Copy data to a dynamically allocated array
    std::copy(data.begin(), data.end(), array);

    // Timing run
    auto start = std::chrono::high_resolution_clock::now();
    quicksortHelper(array, 0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Reset the array to its original state before the stats run
    std::copy(data.begin(), data.end(), array);

    // Stats run
    quicksortHelper(array, 0, size - 1);

    delete[] array;
}

// Helper method for quicksort
void QuickSortAlgorithm::quicksortHelper(int* array, int low, int high) {
    if (low < high) {
        this->iterations++;
        int pivotIndex = partition(array, low, high);
        quicksortHelper(array, low, pivotIndex - 1);
        quicksortHelper(array, pivotIndex + 1, high);
    }
}
// Partition method for quicksort
int QuickSortAlgorithm::partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            if (i != j) {  // Only swap and count if the elements are different
                std::swap(array[i], array[j]);
                this->swaps++;
                this->arrayAccesses += 2;
            }
        }
    }

    if (i + 1 != high) {  // Swap pivot into place if necessary
        std::swap(array[i + 1], array[high]);
        this->swaps++;
        this->arrayAccesses += 2;
    }

    return i + 1;
}
