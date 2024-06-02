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
private:
public:
    int number;
    std::vector<sudoku> tables;
    void play();
    void puzzle();
    friend class game;
    void setCell(int i, int j, int value, int num);
    void puzzleCell(int i, int j, int num);
    sudoku first;
    sudoku second;
    sudoku third;
};


#endif //SUDOKU_MULTIDOKU_H
