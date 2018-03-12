cmake_minimum_required(VERSION 3.9)
project(minesweeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(minesweeper "source files/main.cpp" "source files/boxClass.cpp" "header files/boxClass.h")