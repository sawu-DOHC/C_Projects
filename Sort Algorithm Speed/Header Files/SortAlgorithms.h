#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

class SortAlgorithms {
public:
    void selectionSort(int* array, int size);
    void quicksort(int* array, int low, int high);
    void insertionSort(int* array, int low, int high);
private:
    int partition(int* array, int low, int high);
    void swap(int& a, int& b);
};

#endif // SORT_ALGORITHMS_H
