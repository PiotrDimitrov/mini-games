#ifndef SUDOKU_SUDOKUTABLE_H
#define SUDOKU_SUDOKUTABLE_H

#include "game.h"

class sudokuTable
{
public:
    sudokuTable();
    ~sudokuTable();
    void show();
public: //CHANGE TO PRIVATE LATER!
    int** table;
    void construct();
    int randomSeed;
    int* randomSet();
};


#endif //SUDOKU_SUDOKUTABLE_H
