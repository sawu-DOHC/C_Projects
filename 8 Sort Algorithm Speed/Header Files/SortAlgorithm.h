#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include <string>

class SortAlgorithm {

public:
    // Enum for the algorithm names
    enum AlgorithmName {
        SELECTION_SORT,
        BUBBLE_SORT,
        QUICKSORT,
        QUICKSORT_ITERATIVE,
        INSERTION_SORT,
        MERGE_SORT
    };

    // Public member variables for statistics
    AlgorithmName algorithmName;
    int iterations;
    int swaps;
    long long executionTime;
    int arrayAccesses;

    // Constructor to initialize member variables with the algorithm name
    SortAlgorithm(AlgorithmName newAlgorithmName);

    // Method to get the algorithm name as a string
    std::string getAlgorithmNameAsString() const;

    // Sorting algorithms
    void selectionSort(int* array, int size);
    void quicksort(int* array, int low, int high);
    void quicksortIterative(int* array, int low, int high);
    void insertionSort(int* array, int low, int high);
    void bubbleSort(int* array, int size);
    void mergeSort(int* array, int low, int high);


private:
    // Partition and merge methods with optional statistics collection
    int partition(int* array, int low, int high, bool collectStats);
    void merge(int* array, int low, int mid, int high, bool collectStats);
};

#endif // SORT_ALGORITHM_H
