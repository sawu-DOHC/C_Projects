#include <iostream>
#include <chrono>
#include "Header Files/SortAlgorithm.h"
#include "Header Files/Utility.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Instantiate sorting algorithm objects using the enum
    SortAlgorithm selectionSortAlgorithm(SortAlgorithm::SELECTION_SORT);
    SortAlgorithm bubbleSortAlgorithm(SortAlgorithm::BUBBLE_SORT);
    SortAlgorithm quicksortAlgorithm(SortAlgorithm::QUICKSORT);
    SortAlgorithm quicksortIterativeAlgorithm(SortAlgorithm::QUICKSORT_ITERATIVE);
    SortAlgorithm insertionSortAlgorithm(SortAlgorithm::INSERTION_SORT);
    SortAlgorithm mergeSortAlgorithm(SortAlgorithm::MERGE_SORT);

    // Load datasets
    int* sortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Sorted.txt");
    int* reverseSortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Reverse Sorted.txt");
    int* randomUniqueData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Random Unique.txt");
    int* nearlySortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Nearly Sorted.txt");

    // Measure performance and print data for each algorithm and dataset
    measurePerformance(selectionSortAlgorithm, sortedData, 1000000);
    printData(selectionSortAlgorithm);
    measurePerformance(selectionSortAlgorithm, reverseSortedData, 1000000);
    printData(selectionSortAlgorithm);
    measurePerformance(selectionSortAlgorithm, randomUniqueData, 1000000);
    printData(selectionSortAlgorithm);
    measurePerformance(selectionSortAlgorithm, nearlySortedData, 1000000);
    printData(selectionSortAlgorithm);

    measurePerformance(bubbleSortAlgorithm, sortedData, 1000000);
    printData(bubbleSortAlgorithm);
    measurePerformance(bubbleSortAlgorithm, reverseSortedData, 1000000);
    printData(bubbleSortAlgorithm);
    measurePerformance(bubbleSortAlgorithm, randomUniqueData, 1000000);
    printData(bubbleSortAlgorithm);
    measurePerformance(bubbleSortAlgorithm, nearlySortedData, 1000000);
    printData(bubbleSortAlgorithm);

    //measurePerformance(quicksortAlgorithm, sortedData, 1000000);
    //printData(quicksortAlgorithm);
    //measurePerformance(quicksortAlgorithm, reverseSortedData, 1000000);
    //printData(quicksortAlgorithm);
    //measurePerformance(quicksortAlgorithm, randomUniqueData, 1000000);
    //printData(quicksortAlgorithm);
    //measurePerformance(quicksortAlgorithm, nearlySortedData, 1000000);
    //printData(quicksortAlgorithm);

    //measurePerformance(quicksortIterativeAlgorithm, sortedData, 1000000);
    //printData(quicksortIterativeAlgorithm);
    //measurePerformance(quicksortIterativeAlgorithm, reverseSortedData, 1000000);
    //printData(quicksortIterativeAlgorithm);
    //measurePerformance(quicksortIterativeAlgorithm, randomUniqueData, 1000000);
    //printData(quicksortIterativeAlgorithm);
    //measurePerformance(quicksortIterativeAlgorithm, nearlySortedData, 1000000);
    //printData(quicksortIterativeAlgorithm);

    //measurePerformance(insertionSortAlgorithm, sortedData, 1000000);
    //printData(insertionSortAlgorithm);
    //measurePerformance(insertionSortAlgorithm, reverseSortedData, 1000000);
    //printData(insertionSortAlgorithm);
    //measurePerformance(insertionSortAlgorithm, randomUniqueData, 1000000);
    //printData(insertionSortAlgorithm);
    //measurePerformance(insertionSortAlgorithm, nearlySortedData, 1000000);
    //printData(insertionSortAlgorithm);

    //measurePerformance(mergeSortAlgorithm, sortedData, 1000000);
    //printData(mergeSortAlgorithm);
    //measurePerformance(mergeSortAlgorithm, reverseSortedData, 1000000);
    //printData(mergeSortAlgorithm);
    //measurePerformance(mergeSortAlgorithm, randomUniqueData, 1000000);
    //printData(mergeSortAlgorithm);
    //measurePerformance(mergeSortAlgorithm, nearlySortedData, 1000000);
    //printData(mergeSortAlgorithm);

    // Clean up dynamic memory
    delete[] sortedData;
    delete[] reverseSortedData;
    delete[] randomUniqueData;
    delete[] nearlySortedData;

    return 0;
}
