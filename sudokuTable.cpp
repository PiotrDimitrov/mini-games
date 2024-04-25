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

    for (int sec = 0; sec < 3; sec++)
    {

        int* numSet = randomSet();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                table[i + sec * 3][j + sec * 3] = numSet[i*3 + j];
            }
        }
        delete [] numSet; numSet = nullptr;
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



