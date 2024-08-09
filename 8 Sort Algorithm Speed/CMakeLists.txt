cmake_minimum_required(VERSION 3.10)
project(SortAlgorithmSpeed)

set(CMAKE_CXX_STANDARD 23)

add_executable(SortAlgorithmSpeed
        main.cpp
        "Header Files/SortAlgorithm.h"
        "Header Files/Utility.h"
        "Source Files/SortAlgorithm.cpp"
        "Source Files/Utility.cpp"
)
