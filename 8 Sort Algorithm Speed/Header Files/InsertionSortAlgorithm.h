#ifndef CPROJECTS_INSERTIONSORTALGORITHM_H
#define CPROJECTS_INSERTIONSORTALGORITHM_H

#include "SortAlgorithm.h"
#include <vector>

class InsertionSortAlgorithm : public SortAlgorithm {
public:
    // Constructor
    InsertionSortAlgorithm();

    // Override the sort method
    void sort(const std::vector<int>& data) override;
};

#endif //CPROJECTS_INSERTIONSORTALGORITHM_H
