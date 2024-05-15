#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include "game.h"

class sudoku
{
public:
    sudoku();
    sudoku(int size);
    sudoku(const sudoku& other);
    ~sudoku();
    void show();
private:
    int** table;
    int secSize;
    int fullSize;
    void construct(bool diagonals = true);
    int puzzle(int difficulty);
    int* randomSet();
    bool safeCell(int number, int row, int column);
    bool safeCell(int row, int column);
    bool fillSector(int i, int j);
    static char defineSymbol(int x);
    friend class game;
};

#endif //SUDOKU_SUDOKU_H
