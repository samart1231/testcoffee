cmake_minimum_required(VERSION 3.20)
project(CoffeeMachine)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(CoffeeMachine
        src/main.cpp
        src/coffee_machine.cpp
        src/coffee_machine.h
)