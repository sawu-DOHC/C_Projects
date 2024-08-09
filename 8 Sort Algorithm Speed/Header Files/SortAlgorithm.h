#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <string>

class SortAlgorithm {

private:
    std::string algorithmName;
    int iterations;
    int swaps;
    long long executionTime;
    int arrayAccesses;

    int partition(int* array, int low, int high);
    void merge(int* array, int low, int mid, int high);
    void swap(int& a, int& b);
    void resetStatistics();

public:
    enum AlgorithmType {
        SELECTION_SORT,
        BUBBLE_SORT,
        QUICKSORT,
        QUICKSORT_ITERATIVE,
        INSERTION_SORT,
        MERGE_SORT,
        UNKNOWN
    };

    SortAlgorithm(const std::string& name);  // Constructor to initialize member variables with name

    void selectionSort(int* array, int size);
    void quicksort(int* array, int low, int high);
    void quicksortIterative(int* array, int low, int high);
    void insertionSort(int* array, int low, int high);
    void bubbleSort(int* array, int size);
    void mergeSort(int* array, int low, int high);

    int getIterations() const;
    int getSwaps() const;
    long long getExecutionTime() const;
    std::string getAlgorithmName() const;
    int getArrayAccesses() const;

    void setAlgorithmName(const std::string& name);
    AlgorithmType getAlgorithmType() const;
};

#endif // SORT_ALGORITHMS_H
