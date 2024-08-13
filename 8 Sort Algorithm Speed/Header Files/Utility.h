#ifndef UTILITY_H
#define UTILITY_H

#include "SortAlgorithm.h"
#include <string>

int* loadData(const std::string& filePath);
void measurePerformance(SortAlgorithm& sortAlgorithm, int* array, int arraySize);
void printData(const SortAlgorithm& sortAlgorithm);

#endif // UTILITY_H
