#include "Header Files/SearchAlgorithms.h"
#include "iostream"

using namespace std;

int main(){

    int array[10] = {1,2,3,4,5,6,7,8,9};

    int resultIndex;

    SearchAlgorithms searchAlgorithm;

    resultIndex = searchAlgorithm.binarySearch( array, 5 );

    cout << "Binary search result: " << resultIndex << endl;

    resultIndex = searchAlgorithm.linearSearch( array, 5 );

    cout << "Linear search result: " << resultIndex << endl;



};