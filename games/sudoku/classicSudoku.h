#ifndef SUDOKU_CLASSICSUDOKU_H
#define SUDOKU_CLASSICSUDOKU_H
#include "sudoku.h"

class sudoku;

class classicSudoku {
public:
    classicSudoku();
    classicSudoku(int size);
    ~classicSudoku();
private:
    int size;
    sudoku* sdk;
    int difficulty;
    void play();
    static void solver();
    friend class game;
};


#endif //SUDOKU_CLASSICSUDOKU_H
