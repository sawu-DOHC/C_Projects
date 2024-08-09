cmake_minimum_required(VERSION 3.27)
project(ShoppingCartProgram)

set(CMAKE_CXX_STANDARD 23)

add_executable(ShoppingCartProgram
        main.cpp
        "Source Files/Item.cpp"
        "Source Files/ShoppingCart.cpp"
        "Source Files/Utility.cpp"
)
