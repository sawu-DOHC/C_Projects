#include "../Header Files/SortAlgorithms.h"

void SortAlgorithms::selectionSort(int* array, int size) {
    for (int step = 0; step < size - 1; ++step) {
        int minIndex = step;
        for (int i = step + 1; i < size; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        // Manual swap
        int temp = array[minIndex];
        array[minIndex] = array[step];
        array[step] = temp;
    }
}

void SortAlgorithms::quicksort(int* array, int low, int high) {
    while (low < high) {
        if (high - low <= 10) {
            insertionSort(array, low, high);
            return;
        }
        int pivotIndex = partition(array, low, high);
        if (pivotIndex - low < high - pivotIndex) {
            quicksort(array, low, pivotIndex - 1);
            low = pivotIndex + 1;
        } else {
            quicksort(array, pivotIndex + 1, high);
            high = pivotIndex - 1;
        }
    }
}

void SortAlgorithms::insertionSort(int* array, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int SortAlgorithms::partition(int* array, int low, int high) {
    // Use median-of-three pivot selection
    int mid = low + (high - low) / 2;
    if (array[mid] < array[low]) swap(array[mid], array[low]);
    if (array[high] < array[low]) swap(array[high], array[low]);
    if (array[high] < array[mid]) swap(array[high], array[mid]);

    int pivot = array[mid];
    swap(array[mid], array[high - 1]);  // Move pivot to high - 1
    int i = low;
    int j = high - 1;

    while (true) {
        while (array[++i] < pivot);
        while (array[--j] > pivot);
        if (i >= j) break;
        swap(array[i], array[j]);
    }

    swap(array[i], array[high - 1]);  // Restore pivot
    return i;
}

void SortAlgorithms::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
