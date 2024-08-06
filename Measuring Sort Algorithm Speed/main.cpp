#include <iostream>
#include "Source Files/SortAlgorithms.cpp"
#include "Source Files/Utility.cpp"
#include <chrono>


int main() {

    SortAlgorithms newSortAlgorithm;


    int arraySize;
    int* array = loadData( "C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/Measuring Search Algorithm Speed/Test Data/searchAlgorithmData.txt", arraySize );

    if (array == nullptr) {
        return 1; // Exit if the data loading failed
    }

    int searchValue = 999999;

}