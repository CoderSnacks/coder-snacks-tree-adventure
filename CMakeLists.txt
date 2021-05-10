cmake_minimum_required(VERSION 3.16)
project(Day3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day3 Main.cpp Player.cpp Player.h DecisionNode.cpp DecisionNode.h GameManagementSystem.h GameManagementSystem.cpp)