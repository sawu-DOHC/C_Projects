cmake_minimum_required(VERSION 3.27)
project(Networking)

set(CMAKE_CXX_STANDARD 23)

# Use vcpkg toolchain (only needed if you run this project standalone)
set(CMAKE_TOOLCHAIN_FILE
        "C:/Users/Sam/OneDrive/Desktop Cloud/C   Projects/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

# Find libcurl via vcpkg
find_package(CURL REQUIRED)

# Include headers
include_directories("Header Files")

# Build executable
add_executable(Networking
        main.cpp
        "Header Files/BruteForce.h"
        "Source Files/BruteForce.cpp"
)

# Link libcurl
target_link_libraries(Networking PRIVATE CURL::libcurl)
