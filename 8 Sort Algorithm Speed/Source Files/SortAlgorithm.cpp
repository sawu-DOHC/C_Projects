#include "../Header Files/SortAlgorithm.h"
#include <chrono>
#include <stack>
#include <algorithm>  // For std::swap

SortAlgorithm::SortAlgorithm(AlgorithmName newAlgorithmName)
        : algorithmName(newAlgorithmName), iterations(0), swaps(0), executionTime(0), arrayAccesses(0) {}

std::string SortAlgorithm::getAlgorithmNameAsString() const {
    switch (algorithmName) {
        case SELECTION_SORT: return "Selection Sort";
        case BUBBLE_SORT: return "Bubble Sort";
        case QUICKSORT: return "Quicksort";
        case QUICKSORT_ITERATIVE: return "Iterative Quicksort";
        case INSERTION_SORT: return "Insertion Sort";
        case MERGE_SORT: return "Merge Sort";
        default: return "Unknown";
    }
}

// Selection Sort
void SortAlgorithm::selectionSort(int* array, int size) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    for (int step = 0; step < size - 1; ++step) {
        int minIndex = step;
        for (int i = step + 1; i < size; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        std::swap(array[minIndex], array[step]);
    }

    auto end = std::chrono::high_resolution_clock::now();

    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run
    for (int step = 0; step < size - 1; ++step) {
        int minIndex = step;
        for (int i = step + 1; i < size; ++i) {
            iterations++;
            arrayAccesses += 2;
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        std::swap(array[minIndex], array[step]);
        swaps++;
        arrayAccesses += 2;
    }
}

// Bubble Sort
void SortAlgorithm::bubbleSort(int* array, int size) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            iterations++;
            arrayAccesses += 2;
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swaps++;
                arrayAccesses += 2;
            }
        }
    }
}

// Recursive Quicksort
void SortAlgorithm::quicksort(int* array, int low, int high) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();
    if (low < high) {
        int pivotIndex = partition(array, low, high, false);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run
    if (low < high) {
        int pivotIndex = partition(array, low, high, true);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

// Iterative Quicksort
void SortAlgorithm::quicksortIterative(int* array, int low, int high) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();

    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run

}

// Insertion Sort
void SortAlgorithm::insertionSort(int* array, int low, int high) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = low + 1; i <= high; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run
    for (int i = low + 1; i <= high; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            iterations++;
            arrayAccesses += 2;
        }
        array[j + 1] = key;
        arrayAccesses++;
    }
}

// Merge Sort
void SortAlgorithm::mergeSort(int* array, int low, int high) {
    // Timing run
    auto start = std::chrono::high_resolution_clock::now();
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high, false);
    }

    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Stats run
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high, true);
    }
}
#include "../Header Files/SortAlgorithm.h"

int SortAlgorithm::partition(int* array, int low, int high, bool collectStats) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (collectStats) {
            iterations++;
            arrayAccesses += 2;
        }
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
            if (collectStats) {
                swaps++;
                arrayAccesses += 2;
            }
        }
    }
    std::swap(array[i + 1], array[high]);
    if (collectStats) {
        swaps++;
        arrayAccesses += 2;
    }
    return i + 1;
}

void SortAlgorithm::merge(int* array, int low, int mid, int high, bool collectStats) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; ++i) left[i] = array[low + i];
    for (int j = 0; j < n2; ++j) right[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];
        if (collectStats) {
            arrayAccesses += 2;
        }
    }
    while (i < n1) array[k++] = left[i++];
    while (j < n2) array[k++] = right[j++];

    delete[] left;
    delete[] right;
}

