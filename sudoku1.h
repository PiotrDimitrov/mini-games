#ifndef SUDOKU_SUDOKU1_H
#define SUDOKU_SUDOKU1_H

#include "game.h"

class sudoku1
{
public:
    sudoku1();
    sudoku1(int size);
    sudoku1(const sudoku1& other);
    ~sudoku1();
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
    void solver();
    void play();
};

#endif //SUDOKU_SUDOKU1_H
