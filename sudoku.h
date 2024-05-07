#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include "game.h"

class sudoku
{
public:
    sudoku();
    sudoku(const sudoku& other);
    ~sudoku();
    void show();
    void show1();
private:
    int** table;
    void construct();
    int puzzle(int difficulty);
    int* randomSet();
    bool safeCell(int number, int row, int column);
    bool fillSector(int i, int j);
    friend class game;
};



#endif //SUDOKU_SUDOKU_H
