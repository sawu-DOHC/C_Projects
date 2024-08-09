cmake_minimum_required(VERSION 3.27)
project(SchoolRegistrationProgram)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        SchoolRegistrationProgram
        main.cpp
        "Source Files/Course.cpp"
        "Source Files/Student.cpp"
        "Source Files/Utils.cpp"
        "Source Files/School.cpp"
        "Header Files/Course.h"
        "Header Files/Student.h"
        "Header Files/Utils.h"
        "Header Files/School.h"
)
