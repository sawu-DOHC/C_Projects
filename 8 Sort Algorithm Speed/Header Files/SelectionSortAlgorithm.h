//
// Created by Sam on 8/16/2024.
//

#ifndef CPROJECTS_SELECTIONSORTALGORITHM_H
#define CPROJECTS_SELECTIONSORTALGORITHM_H

#include "SortAlgorithm.h"
#include <vector>

class SelectionSortAlgorithm : public SortAlgorithm {
public:
    // Constructor
    SelectionSortAlgorithm();

    // Override the sort method
    void sort(const std::vector<int>& data) override;
};

#endif //CPROJECTS_SELECTIONSORTALGORITHM_H
