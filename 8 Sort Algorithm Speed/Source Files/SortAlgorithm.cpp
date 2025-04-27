#include "../Header Files/SortAlgorithm.h"

// Constructor
SortAlgorithm::SortAlgorithm(const std::string& name) : algorithmName(name), iterations(0), swaps(0), executionTime(0), arrayAccesses(0) {

}

// Virtual destructor
SortAlgorithm::~SortAlgorithm() {

}

// Method to reset statistics
void SortAlgorithm::resetStats() {

    unsigned long long iterations = 0;
    unsigned long long swaps = 0;
    unsigned long long arrayAccesses = 0;
    unsigned long long executionTime = 0;

}

// Method to print the statistics to the console
void SortAlgorithm::printData() const {
    std::cout << "Algorithm: " << algorithmName << std::endl;
    std::cout << "Execution Time: " << executionTime << " microseconds" << std::endl;
    std::cout << "Iterations: " << iterations << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Array Accesses: " << arrayAccesses << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

// Method to get all statistics as a vector of strings
std::vector<std::string> SortAlgorithm::getStatistics(const std::string& datasetName) const {
    std::vector<std::string> stats;
    stats.push_back(algorithmName);
    stats.push_back(datasetName);

    stats.push_back(std::to_string(executionTime));
    stats.push_back(std::to_string(iterations));
    stats.push_back(std::to_string(swaps));
    stats.push_back(std::to_string(arrayAccesses));

    return stats;
}


