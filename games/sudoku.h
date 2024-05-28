#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H
#include <vector>

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
};

/*
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
 */
#endif //SUDOKU_SUDOKU_H
