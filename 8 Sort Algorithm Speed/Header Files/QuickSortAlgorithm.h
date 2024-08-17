//
// Created by Sam on 8/16/2024.
//

#ifndef CPROJECTS_QUICKSORTALGORITHM_H
#define CPROJECTS_QUICKSORTALGORITHM_H

#include "SortAlgorithm.h"
#include <vector>

class QuickSortAlgorithm : public SortAlgorithm {
public:
    // Constructor
    QuickSortAlgorithm();

    // Override the sort method
    void sort(const std::vector<int>& data) override;

private:
    // Helper methods for quicksort
    void quicksortHelper(int* array, int low, int high);
    int partition(int* array, int low, int high);
};

#endif //CPROJECTS_QUICKSORTALGORITHM_H
