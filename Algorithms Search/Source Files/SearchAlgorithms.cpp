#include "../Header Files/SearchAlgorithms.h"



int SearchAlgorithms::linearSearch( int (&array)[10], int value ) {

    for ( int i = 0; i < 10; i++) {

        if (array[i] == value) {
            return i;
        }

    }

    return -1;

}

int SearchAlgorithms::binarySearch( int (&array)[10], int value ){

    int indexFirst = 0;

    int indexLast = 9;


    while (indexFirst <= indexLast ){

        int middle = (indexFirst + indexLast ) / 2;

        if ( value == array[middle] ){

            return middle;
        }
        else if ( value > array[middle] ){
            indexFirst = middle + 1;
        }
        else {
            indexLast = middle - 1;
        }
    }

    return -1;

}