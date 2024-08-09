#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "SortAlgorithm.h"

// Function to load data from a file
int* loadData(const std::string& filePath, int& arraySize);

// Function to measure the performance of sorting algorithms
void measureSortPerformance(SortAlgorithm& sortAlgorithm, int* array, int arraySize);

#endif // UTILITY_H
