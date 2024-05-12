#include "sudoku.h"
#include "game.h"
#include <iostream>

void sudoku::show()
{
    char nextSymbol;
    for (int i = 0; i < 4*fullSize+4; i++){std::cout << "_";}
    std::cout << std::endl;
    for (int i = 0; i < fullSize; i++)
    {
        for (int j = 0; j < fullSize; j++) {
            //if (table[i][j] <= 0) { nextSymbol = ' '; }
            //else { nextSymbol = char(table[i][j] + 48); }
            nextSymbol = defineSymbol(table[i][j]);
            if (j % secSize == secSize-1) {
                std::cout << nextSymbol << "  |  ";
            } else {
                std::cout << nextSymbol << "   ";
            }
        }
            std::cout << std::endl;
            if (i % secSize == secSize-1) {
                for (int i = 0; i < 4*fullSize+4; i++){std::cout << "_";}
                std::cout << std::endl;
            }
        std::cout << std::endl;
    }
}

sudoku::sudoku()
{
    secSize = 3; fullSize = secSize * secSize;
    this->table = new int*[fullSize];
    for (int i = 0; i < fullSize; i++)
    {
        this->table[i] = new int[fullSize];
        for (int j = 0; j < fullSize; j++){
            table[i][j] = 0;
        }
    }
}

sudoku::sudoku(int size)
{
    secSize = size; fullSize = secSize * secSize;
    this->table = new int*[fullSize];
    for (int i = 0; i < fullSize; i++)
    {
        this->table[i] = new int[fullSize];
        for (int j = 0; j < fullSize; j++){
            table[i][j] = 0;
        }
    }
}

sudoku::~sudoku()
{
    for (int i = 0; i < fullSize; i++)
    {
        delete [] this->table[i];
    }
    delete [] this->table;
}

sudoku::sudoku(const sudoku& other)
{
    secSize = other.secSize; fullSize = other.fullSize;
    this->table = new int*[fullSize];
    for (int i = 0; i < fullSize; i++)
    {
        this->table[i] = new int[fullSize];
        for (int j = 0; j < fullSize; j++)
        {
            this->table[i][j] = other.table[i][j];
        }
    }
}

void sudoku::construct(bool diagonals) {
    //initially fill three diagonal sectors
    if (diagonals) {
        for (int sec = 0; sec <= fullSize-1; sec+=(secSize+1))
        {
            int* numSet = randomSet();

            for (int i = 0; i < secSize; i++)
            {
                for (int j = 0; j < secSize; j++)
                {
                    table[i + (sec/secSize) * secSize][j + (sec%secSize) * secSize] = numSet[i*secSize + j];
                }
            }
            delete [] numSet; numSet = nullptr;
        }
    }

    fillSector(0 , 0);
}

int sudoku::puzzle(int difficulty) {
    int empty = 0;
    int counterRows[fullSize];
    int counterColumns[fullSize];
    for (int i = 0 ; i < fullSize; i++) {
        counterRows[i] = 0;
        counterColumns[i] = 0;
    }
    int stop = 0;
    int maxEmpRow = fullSize - 3; int maxEmpCol = fullSize - 3;
    if (difficulty >= 52) {maxEmpRow += (rand() % 2); maxEmpCol += (rand() % 2);}
    if (fullSize == 16) {difficulty *= 2;} //TO DO
    while (difficulty > 0 && stop < 250000)
    {
        stop++;
        int i = rand() % fullSize;
        int j = rand() % fullSize;
        if (table[i][j] < 0) {continue;}
        if (counterRows[i] >= maxEmpRow) {continue;}
        if (counterColumns[j] >= maxEmpCol) {continue;}
        counterRows[i] += 1;
        counterColumns[j] += 1;
        difficulty--;
        table[i][j] *= (-1);
        empty++;
    }
    return empty;
}

bool sudoku::fillSector(int i, int j) {
    if (i == fullSize-1 && j == fullSize) {return true;}
    if (j == fullSize) { j =  0; i++; }
    if (table[i][j] > 0) {return fillSector(i, j+1);}
    int step = rand () % fullSize + 1;
    for (int it = 1; it <= fullSize; it++)
    {
        int num = (step + it) % fullSize;
        if (num == 0) {num = fullSize;}
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
    int numSet[fullSize];
    for (int i = 0; i < fullSize; i++)
    {
        numSet[i] = i+1;
    }
    int* res = new int[fullSize];
    for (int i = 0; i < fullSize; i++)
    {
        int x = rand() % (fullSize - i) + 1;
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
    int sec = secSize*(row/secSize) + (column/secSize);
    for (int i = 0; i < fullSize; i++)
    {
        if (table[i][column] == number) { return false; }
        if (table [row][i] == number) { return false; }
    }
    for (int i = 0; i < secSize; i++){
        for (int j = 0; j < secSize; j++){
            if(table[i + (sec/secSize) * secSize][j + (sec%secSize) * secSize] == number) {return false;}
        }
    }
    return true;
}

char sudoku::defineSymbol(int x) {
    if (x <= 0) {return ' ';}
    if (x <= 9) {return char('0' + x);}
    switch (x) {
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        case 16:
            return 'G';
    }
    return '?';
}