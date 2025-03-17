#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>

#include "Header Files/SortAlgorithm.h"
#include "Header Files/BubbleSortAlgorithm.h"
#include "Header Files/InsertionSortAlgorithm.h"
#include "Header Files/QuickSortAlgorithm.h"
#include "Header Files/SelectionSortAlgorithm.h"
#include "Header Files/Utility.h"

using namespace std;

int main() {
    // Instantiate sorting algorithm objects
    BubbleSortAlgorithm bubbleSortAlgorithm;
    InsertionSortAlgorithm insertionSortAlgorithm;
    QuickSortAlgorithm quickSortAlgorithm;
    SelectionSortAlgorithm selectionSortAlgorithm;

    // List of pointers to algorithms to run
    vector<SortAlgorithm *> algorithms = {
            &bubbleSortAlgorithm,
            &insertionSortAlgorithm,
            &quickSortAlgorithm,
            &selectionSortAlgorithm
    };

    // Load datasets
    vector<int> sortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Sorted.txt");
    vector<int> reverseSortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Sorted Reverse.txt");
    vector<int> randomUniqueData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Random Unique.txt");
    vector<int> nearlySortedData = loadData("C:/Users/Sam/OneDrive/Desktop Cloud/C++ Projects/8 Sort Algorithm Speed/Test Data 1/Nearly Sorted.txt");

    // Consolidate datasets into a vector of pairs (data vector, dataset name)
    vector<pair<vector<int>, string>> datasets = {
            {sortedData,        "Sorted"},
            {reverseSortedData, "Reverse Sorted"},
            {randomUniqueData,  "Random Unique"},
            {nearlySortedData,  "Nearly Sorted"}
    };

    // Prepare to collect statistics
    vector<vector<string>> statistics;

    // Run each dataset on all algorithms
    for (const auto& [data, datasetName] : datasets) {
        for (SortAlgorithm* algorithm : algorithms) {
            algorithm->sort(data);  // Calls the appropriate sort method
            statistics.push_back(algorithm->getStatistics(datasetName));
            algorithm->resetStats();
        }
    }

    // Print the statistics table header
    cout << left
         << setw(20) << "Algorithm"
         << setw(20) << "Dataset"
         << setw(15) << "Time (μs)"
         << setw(15) << "Iterations"
         << setw(15) << "Swaps"
         << setw(20) << "Array Accesses"
         << endl;

    cout << "---------------------------------------------------------------------------------------------------------" << endl;

    // Print table contents
    for (const auto& stat : statistics) {
        cout << left << setw(20) << stat[0]  // Algorithm name
             << setw(20) << stat[1]  // Dataset name
             << setw(15) << stat[2]  // Execution time
             << setw(15) << stat[3]  // Iterations
             << setw(15) << stat[4]  // Swaps
             << setw(20) << stat[5]  // Array accesses
             << endl;
    }

    return 0;
}
