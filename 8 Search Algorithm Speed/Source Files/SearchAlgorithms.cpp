#include "../Header Files/SearchAlgorithms.h"
#include <iostream>

int* SearchAlgorithms::linearSearch(int* array, int size, int value) {

    int* results = new int[2];

    results[1] = 0;

    for (int i = 0; i < size; ++i) {
        results[1]++;
        if (array[i] == value) {
            results[0] = i;
            return results;
        }
    }
    results[0] = -1;
    return results;
}

int* SearchAlgorithms::binarySearch(int* array, int size, int value) {

    int* results = new int[2];

    results[1] = 0;

    int indexFirst = 0;

    int indexLast = size - 1;

    while (indexFirst <= indexLast) {
        results[1]++;
        int middle = (indexFirst + indexLast) / 2;

        if (value == array[middle]) {
            results[0] = middle;
            return results;
        }
        else if (value > array[middle]) {
            indexFirst = middle + 1;
        }
        else {
            indexLast = middle - 1;
        }
    }

    results[0] = -1;
    return results;
}
