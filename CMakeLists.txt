cmake_minimum_required(VERSION 3.27)
project(CProjects)


set(CMAKE_TOOLCHAIN_FILE
        "C:/Users/Sam/OneDrive/Desktop Cloud/C   Projects/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")


add_subdirectory("1 Data Types")
add_subdirectory("3 Functions")
add_subdirectory("4 Shopping Cart Program")
add_subdirectory("7 Replicating the Vector Class")
add_subdirectory("7 School Registration Program")
add_subdirectory("7 Object Oriented Programming")
add_subdirectory ("8 Prime Number Detection" )
add_subdirectory("8 Search Algorithms")
add_subdirectory("8 Sort Algorithms")
add_subdirectory("8 Search Algorithm Speed")
add_subdirectory("8 Sort Algorithm Speed")
add_subdirectory("11 Networking")





