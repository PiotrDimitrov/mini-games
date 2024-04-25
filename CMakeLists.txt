cmake_minimum_required(VERSION 3.27)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku main.cpp
        game.h
        sudokuTable.h
        sudokuTable.cpp
        game.cpp)
