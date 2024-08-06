cmake_minimum_required(VERSION 3.27)
project(AlgorithmsSearch)

set(CMAKE_CXX_STANDARD 23)

include_directories("Header Files")

add_executable(AlgorithmsSearch
        main.cpp
        "Source Files/SearchAlgorithms.cpp"
        "../Measuring Sort Algorithm Speed/main.cpp"
)
