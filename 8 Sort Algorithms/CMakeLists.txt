cmake_minimum_required(VERSION 3.27)
project(AlgorithmsSort)

set(CMAKE_CXX_STANDARD 23)

include_directories("Header Files")

add_executable(AlgorithmsSort
        main.cpp
        "Source Files/SortAlgorithms.cpp"
)
