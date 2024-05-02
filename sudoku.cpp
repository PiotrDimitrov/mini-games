#include "sudoku.h"
#include <iostream>

void sudoku::show()
{
    std::cout << "________________________________________\n\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if (j % 3 == 2)
            {
                std::cout << this->table[i][j] << "  |  ";
            } else
            {
                std::cout << this->table[i][j] << "   ";
            }
        std::cout << std::endl;
        if (i % 3 == 2)
        {
            std::cout << "________________________________________\n";
        }

        std::cout << std::endl;
    }
}

sudoku::sudoku()
{
    this->table = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        this->table[i] = new int[9] {0,0,0,0,0,0,0,0,0};
    }
}

sudoku::~sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        delete [] this->table[i];
    }
    delete [] this->table;
}

sudoku::sudoku(const sudoku& other)
{
    this->table = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        this->table[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            this->table[i][j] = other.table[i][j];
        }
    }
}

void sudoku::construct() {
    //initially fill three diagonal sectors
    for (int sec = 0; sec <= 8; sec+=4)
    {
        int* numSet = randomSet();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                table[i + (sec/3) * 3][j + (sec%3) * 3] = numSet[i*3 + j];
            }
        }
        delete [] numSet; numSet = nullptr;
    }

    fillSector(0 , 3);
}

void puzzle()
{
    
}

bool sudoku::fillSector(int i, int j) {
    if (i == 8 && j == 9) {return true;}
    if (j == 9) { j =  0; i++; }
    if (table[i][j] > 0) {return fillSector(i, j+1);}
    int step = rand () % 9 + 1;
    for (int it = 1; it <= 9; it++)
    {
        int num = (step + it) % 9;
        if (num == 0) {num = 9;}
        if (safeCell(num, i, j)) {
            table[i][j] = num;
            if (fillSector(i, j+1)) {return true;}
            table[i][j] = 0;
        }
    }
    return false;
}

int* sudoku::randomSet()
{
    int numSet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* res = new int[9];
    for (int i = 0; i < 9; i++)
    {
        int x = rand() % (9 - i) + 1;
        int counter = -1;
        while(x > 0)
        {
            counter++;
            if (numSet[counter] != 0){ x--; }
        }
        res[i] = numSet[counter];
        numSet[counter] = 0;
    }
    return res;
}

bool sudoku::safeCell(int number, int row, int column) {
    if (table[row][column] != 0) { return false; }
    int sec = 3*(row/3) + (column/3);
    for (int i = 0; i < 9; i++)
    {
        if (table[i][column] == number) { return false; }
        if (table [row][i] == number) { return false; }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(table[i + (sec/3) * 3][j + (sec%3) * 3] == number) {return false;}
        }
    }
    return true;
}



