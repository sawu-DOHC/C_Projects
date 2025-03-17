cmake_minimum_required(VERSION 3.27)
project(Functions)

set(CMAKE_CXX_STANDARD 23)

include_directories("Header Files")

add_executable(Functions
        main.cpp
        "Header Files/isPrime.h"
        "Source Files/isPrime.cpp"
)
