cmake_minimum_required(VERSION 3.27)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        sudoku main.cpp
        game.h
        sudoku1.h
        sudoku1.cpp
        game.cpp
        record.cpp
        header.h
        games/sudoku/sudoku.h
        games/sudoku/sudoku.cpp
        games/sudoku/classicSudoku.h
        games/sudoku/classicSudoku.cpp)
