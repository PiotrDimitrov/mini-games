#include "sudokuTable.h"
#include <iostream>
#include <ctime>


void sudokuTable::show()
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

sudokuTable::sudokuTable()
{
    srand(time(0));
    this->table = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        this->table[i] = new int[9] {0,0,0,0,0,0,0,0,0};
    }
    this->randomSeed = time(0) % 1000;
}

sudokuTable::~sudokuTable()
{
    for (int i = 0; i < 9; i++)
    {
        delete [] this->table[i];
    }
    delete [] this->table;

}

void sudokuTable::construct() {
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

    //fill non-corner sectors
    for (int sec = 1; sec <= 7; sec+=2)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){

                //check for candidate size = 1
                for (int i2 = 0; i2 < 3; i2++){
                    for(int j2 = 0; j2 < 3; j2++){
                        candidate* cand = checkCell(i + (sec/3) * 3, j + (sec%3) * 3, sec);
                           if (cand->size == 1) { }
                        delete cand;
                    }
                }
            }

        }
    }

}

int* sudokuTable::randomSet()
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

bool sudokuTable::safeCell(int number, int row, int column) {
    if (table[row][column] != 0) { return false; }
    for (int i = 0; i < 9; i++)
    {
        if (table[i][column] == number) { return false; }
        if (table [row][i] == number) { return false; }
    }
    return true;
}

sudokuTable::candidate* sudokuTable::checkCell(int row, int column, int sector) {
    candidate* result = new candidate;
    result->size = 9;
    for (int i = 0; i < 9; i++) { result->set[i] = i+1; }
    for (int i = 0; i < 9; i++)
    {
        if (table[i][column] > 0 && result->set[table[i][column] - 1] != 0)
        { (--result->size); result->set[table[i][column] - 1] = 0; }
        if (table[row][i] > 0 && result->set[table [row][i] - 1] != 0)
        { (--result->size); result->set[table [row][i] - 1] = 0; }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(table[i + (sector/3) * 3][j + (sector%3) * 3] > 0 && result->set[table[i + (sector/3) * 3][j + (sector%3) * 3] - 1] != 0)
            { (--result->size); result->set[table[i + (sector/3) * 3][j + (sector%3) * 3] - 1] = 0; }
        }
    }
    return result;
}

int sudokuTable::candidate::randCand() {
    if (this->size < 1) { return 0; }
    int x = rand() % (this->size) + 1;
    int counter = -1;
    while (x > 0)
    {
        counter++;
        if (this->set[counter] > 0) { x--; }
    }
    return this->set[counter];
}

int sudokuTable::candidate::unique() {
    if (this->size > 1) {return 0;}
    int c = 0;
    while (this->set[c] == 0)
    {
        c++;
    }
    return this->set[c];
}

