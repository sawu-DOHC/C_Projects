#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include <string>
#include <vector>
#include <iostream>

class SortAlgorithm {

public:
    // Public member variables for algorithm name and statistics
    std::string algorithmName;
    unsigned long long iterations = 0;
    unsigned long long swaps = 0;
    unsigned long long executionTime = 0;
    unsigned long long arrayAccesses = 0;

    // Constructor
    SortAlgorithm(const std::string& name);

    // Virtual destructor for proper cleanup of derived classes
    virtual ~SortAlgorithm();

    // Pure virtual method that derived classes must implement
    virtual void sort(const std::vector<int>& data) = 0;

    // Method to reset statistics
    void resetStats();

    // Method to print the statistics to the console
    void printData() const;

    // Method to get all statistics as a vector of strings
    std::vector<std::string> getStatistics(const std::string& datasetName) const;
};

#endif // SORT_ALGORITHM_H
