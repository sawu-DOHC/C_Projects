#ifndef BUBBLE_SORT_ALGORITHM_H
#define BUBBLE_SORT_ALGORITHM_H

#include "SortAlgorithm.h"
#include <vector>

class BubbleSortAlgorithm : public SortAlgorithm {

public:
    // Constructor
    BubbleSortAlgorithm();

    // Override the sort method
    void sort(const std::vector<int>& data) override;
};

#endif // BUBBLE_SORT_ALGORITHM_H