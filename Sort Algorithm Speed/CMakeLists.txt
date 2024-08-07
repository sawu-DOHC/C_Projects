cmake_minimum_required(VERSION 3.10)
project(MeasuringSortAlgorithmSpeed)

set(CMAKE_CXX_STANDARD 23)

add_executable(MeasuringSortAlgorithmSpeed
        main.cpp

        "Header Files/SortAlgorithms.h"
        "Header Files/Utility.h"
        "Source Files/SortAlgorithms.cpp"
        "Source Files/Utility.cpp"
)
