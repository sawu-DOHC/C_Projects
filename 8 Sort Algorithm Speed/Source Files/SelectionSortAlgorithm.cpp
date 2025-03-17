#include "../Header Files/SelectionSortAlgorithm.h"
#include <chrono>
#include <algorithm>  // For std::swap


SelectionSortAlgorithm::SelectionSortAlgorithm()
        : SortAlgorithm("Selection Sort") {}


void SelectionSortAlgorithm::sort(const std::vector<int>& data) {
    int size = data.size();
    int* array = new int[size];


    std::copy(data.begin(), data.end(), array);


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


    std::copy(data.begin(), data.end(), array);


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


    delete[] array;
}
