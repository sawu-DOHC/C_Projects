#include <iostream>
#include "SortAlgorithms.h"

using namespace std;

int main() {

    int array1[10] = {5, 2, 9, 1, 5, 6, 10, 4, 3, 8};
    int array2[10] = {5, 2, 9, 1, 5, 6, 10, 4, 3, 8};
    int array3[10] = {5, 2, 9, 1, 5, 6, 10, 4, 3, 8};

    SortAlgorithms sortAlgorithm;

    // Selection Sort
    sortAlgorithm.selectionSort(array1, 10);
    cout << "Selection Sort result: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << array1[i] << " ";
    }
    cout << endl;

    // Bubble Sort
    sortAlgorithm.bubbleSort(array2, 10);
    cout << "Bubble Sort result: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << array2[i] << " ";
    }
    cout << endl;

    // Insertion Sort
    sortAlgorithm.insertionSort(array3, 10);
    cout << "Insertion Sort result: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << array3[i] << " ";
    }
    cout << endl;

    return 0;
}
