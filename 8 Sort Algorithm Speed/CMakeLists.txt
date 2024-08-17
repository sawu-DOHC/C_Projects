cmake_minimum_required(VERSION 3.10)
project(SortAlgorithmSpeed)

set(CMAKE_CXX_STANDARD 23)

add_executable(SortAlgorithmSpeed
        main.cpp
        "Header Files/SortAlgorithm.h"
        "Header Files/Utility.h"
        "Source Files/SortAlgorithm.cpp"
        "Source Files/Utility.cpp"
        "Source Files/SelectionSortAlgorithm.cpp"
        "Header Files/SelectionSortAlgorithm.h"
        "Source Files/BubbleSortAlgorithm.cpp"
        "Header Files/BubbleSortAlgorithm.h"
        "Source Files/QuickSortAlgorithm.cpp"
        "Header Files/QuickSortAlgorithm.h"
        "Source Files/InsertionSortAlgorithm.cpp"
        "Header Files/InsertionSortAlgorithm.h"
)
