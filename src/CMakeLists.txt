cmake_minimum_required(VERSION 3.20)
project(CoffeeMachine)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(CoffeeMachine
        main.cpp
        coffee_machine.cpp
)