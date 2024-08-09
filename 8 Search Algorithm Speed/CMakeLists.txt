cmake_minimum_required(VERSION 3.27)
project(SearchAlgorithmSpeed)

set(CMAKE_CXX_STANDARD 23)

add_executable(SearchAlgorithmSpeed
        main.cpp
        "Header Files/SearchAlgorithms.h"
        "Header Files/Utility.h"
        "Source Files/Utility.cpp"
        "Source Files/SearchAlgorithms.cpp"

)