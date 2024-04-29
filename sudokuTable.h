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
    struct candidate;
    void construct();
    int randomSeed;
    int* randomSet();
    bool safeCell(int number, int row, int column);
    candidate* checkCell(int row, int column, int sector);
    
};

struct sudokuTable::candidate
{
    int size;
    int set[9];
    int randCand();
    int unique();
};


#endif //SUDOKU_SUDOKUTABLE_H
