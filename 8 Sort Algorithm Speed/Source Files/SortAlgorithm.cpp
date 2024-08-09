#include "Header Files/SortAlgorithms.h"
#include <stack>
#include <iostream>
#include <chrono>

// Constructor to initialize member variables
SortAlgorithm::SortAlgorithm(const std::string& name)
        : algorithmName(name), iterations(0), swaps(0), executionTime(0), arrayAccesses(0) {
    if (name == "Selection Sort") {
        algorithmType = SELECTION_SORT;
    }
    else if (name == "Bubble Sort") {
        algorithmType = BUBBLE_SORT;
    }
    else if (name == "Quicksort") {
        algorithmType = QUICKSORT;
    }
    else if (name == "Iterative Quicksort") {
        algorithmType = QUICKSORT_ITERATIVE;
    }
    else if (name == "Insertion Sort") {
        algorithmType = INSERTION_SORT;
    }
    else if (name == "Merge Sort") {
        algorithmType = MERGE_SORT;
    }
    else {
        algorithmType = UNKNOWN;
    }
}

// Getter for iterations
int SortAlgorithms::getIterations() const {
    return iterations;
}

// Getter for swaps
int SortAlgorithms::getSwaps() const {
    return swaps;
}

// Getter for execution time
long long SortAlgorithms::getExecutionTime() const {
    return executionTime;
}

// Getter for algorithm name
std::string SortAlgorithms::getAlgorithmName() const {
    return algorithmName;
}

// Getter for array accesses
int SortAlgorithms::getArrayAccesses() const {
    return arrayAccesses;
}

// Getter for algorithm type
SortAlgorithms::AlgorithmType SortAlgorithms::getAlgorithmType() const {
    return algorithmType;
}

// Reset statistics
void SortAlgorithms::resetStatistics() {
    iterations = 0;
    swaps = 0;
    executionTime = 0;
    arrayAccesses = 0;
}

// Selection Sort
void SortAlgorithms::selectionSort(int* array, int size) {
    setAlgorithmName("Selection Sort");
    resetStatistics();
    auto start = std::chrono::high_resolution_clock::now();
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
    }
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Recursive Quicksort
void SortAlgorithms::quicksort(int* array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

// Iterative Quicksort
void SortAlgorithms::quicksortIterative(int* array, int low, int high) {
    std::stack<int> stack;
    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top(); stack.pop();
        low = stack.top(); stack.pop();

        if (low < high) {
            int pivotIndex = partition(array, low, high);

            if (pivotIndex - 1 > low) {
                stack.push(low);
                stack.push(pivotIndex - 1);
            }
            if (pivotIndex + 1 < high) {
                stack.push(pivotIndex + 1);
                stack.push(high);
            }
        }
    }
}

// Insertion Sort
void SortAlgorithms::insertionSort(int* array, int low, int high) {
    setAlgorithmName("Insertion Sort");
    resetStatistics();
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Bubble Sort
void SortAlgorithms::bubbleSort(int* array, int size) {
    setAlgorithmName("Bubble Sort");
    resetStatistics();
    auto start = std::chrono::high_resolution_clock::now();
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
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Merge Sort
void SortAlgorithms::mergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

// Partition function for Quicksort
int SortAlgorithms::partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        iterations++;
        arrayAccesses += 2;
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
            swaps++;
            arrayAccesses += 2;
        }
    }
    std::swap(array[i + 1], array[high]);
    swaps++;
    arrayAccesses += 2;
    return i + 1;
}

// Merge function for Merge Sort
void SortAlgorithms::merge(int* array, int low, int mid, int high) {
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
    }
    while (i < n1) array[k++] = left[i++];
    while (j < n2) array[k++] = right[j++];

    delete[] left;
    delete[] right;
}

// Swap function
void SortAlgorithms::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
