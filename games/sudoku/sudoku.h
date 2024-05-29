#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H
#include <vector>
#include "classicSudoku.h"

class sudoku {
public:
    sudoku();
    sudoku(int size);
    sudoku(const sudoku& other);
    sudoku(const sudoku& other, std::vector<int> vec);
    ~sudoku();
    void show();
private:
public:
    int** table;
    int secSize;
    int fullSize;
    int puzzle(int difficulty);
    void construct();
    void diagonals();
    bool fill(int i, int j);
    bool fill(int i, int j, bool (*func)(int i, int j));
    bool fill(int i, int j, bool (*func)(int number, int i, int j));
    bool safeCell(int number, int row, int column);
    bool safeCell(int row, int column);
    int* randomSet();
    static char defineSymbol(int x);
    void clear();
};

#endif //SUDOKU_SUDOKU_H
