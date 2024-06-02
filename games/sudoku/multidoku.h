#ifndef SUDOKU_MULTIDOKU_H
#define SUDOKU_MULTIDOKU_H
#include <vector>
#include "sudoku.h"

class sudoku;

class multidoku {
public:
    multidoku();
    multidoku(int number);
    ~multidoku();
    void show();
    void print();

private:
public:
    int number;
    std::vector<sudoku> tables;
    void play();
    void puzzle();
    friend class game;
    void setCell(int i, int j, int value, int num);
    void puzzleCell(int i, int j, int num, int& emp);
    sudoku first;
    sudoku second;
    sudoku third;
    void printTwo();
    void printThree();
};


#endif //SUDOKU_MULTIDOKU_H
