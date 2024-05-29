#ifndef SUDOKU_CLASSICSUDOKU_H
#define SUDOKU_CLASSICSUDOKU_H
#include "sudoku.h"

class classicSudoku {
public:
    classicSudoku();
    classicSudoku(int x);
    ~classicSudoku();
private:
    int size;
    sudoku* sdk;
    int difficulty;
    void play();
    static void solver();
    //time_t start, end;
    //double solveTime;
};


#endif //SUDOKU_CLASSICSUDOKU_H
