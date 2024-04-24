#include "sudokuTable.h"
#include <iostream>

sudokuTable::sudokuTable()
{
    this->table = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        this->table[i] = new int[9] {0,0,0,0,0,0,0,0,0};
    }
}

sudokuTable::~sudokuTable()
{
    for (int i = 0; i < 9; i++)
    {
        delete [] this->table[i];
    }
    delete [] this->table;
}

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

