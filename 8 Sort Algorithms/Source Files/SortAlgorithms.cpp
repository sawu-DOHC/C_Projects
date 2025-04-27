#include "SortAlgorithms.h"

// THE SELECTION SORT ALGORITHM
void SortAlgorithm::selectionSort( int array[], int size ) {

    for ( int i = 0; i < size - 1; ++i ) {

        int minIndex = i;

        for ( int j = i + 1; j < size; ++j ) {

            if ( array[j] < array[minIndex] ) {

                minIndex = j;

            }
        }
        // swap
        int temp = array[minIndex];

        array[minIndex] = array[i];

        array[i] = temp;
    }
}

// THE BUBBLE SORT ALGORITHM
void SortAlgorithm::bubbleSort( int array[], int size ) {

    for ( int i = 0; i < size - 1; ++i ) {

        for ( int j = 0; j < size - i - 1; ++j ) {

            if ( array[j] > array[j + 1] ) {

                // swap
                int temp = array[j];

                array[j] = array[j + 1];

                array[j + 1] = temp;

            }
        }
    }
}

// THE INSERTION SORT ALGORITHM
void SortAlgorithm::insertionSort(int array[], int size ) {

    for ( int i = 1; i < size; ++i ) {

        int key = array[i];

        int j = i - 1;

        while ( key < array[j] && j >= 0 ) {

            array[j + 1] = array[j];

            --j;
        }

        array[j + 1] = key;
    }

}
