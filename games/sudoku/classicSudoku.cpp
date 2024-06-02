#include "classicSudoku.h"
#include "sudoku.h"
#include <iostream>

classicSudoku::classicSudoku() {
sdk = new sudoku(size);
//sdk->diagonals();
//sdk->construct();
//sdk->puzzle(difficulty);
}

classicSudoku::classicSudoku(int size) {
    this->size = size;
    sdk = new sudoku(this->size);
    sdk->diagonals();
    sdk->construct();
}

classicSudoku::~classicSudoku() {
    delete sdk;
}

void classicSudoku::play() {
    show();
    std::cout << "Fill numbers in table in format: row column number (integers)" << std::endl;
    int r, c, n; int errors = 0;
    std::string input;
    int cells = difficulty;
    time_t start, end;
    int sz = sdk->fullSize;
    time(&start);
    while (cells > 0){
        std::cin >> input;
        if (input == "Quit" || input == "quit") {return;}
        r = int(input[0] - '0');
        c = int(input[2] - '0');
        n = int(input[4] - '0');
        r--; c--;
        if (r > (sz-1) || c > (sz-1) || r < 0 || c < 0 || n < 1 || n > sz)
        {std::cout << "Invalid input" << std::endl; continue;}
        if (sdk->table[r][c] > 0) {std::cout << "Cell isn't empty\n"; continue;}
        if (sdk->table[r][c] == (-1)*n) {sdk->table[r][c] *= (-1); cells--;}
        else {std::cout << "Wrong!" << std::endl; errors++; continue;}
        show();
    }

    time(&end);
    double solveTime = difftime(end, start);
    std::cout << "Time: " << solveTime << " seconds" << std::endl;
    std::cout << "Wrong guesses: " << errors << std::endl;

}

void classicSudoku::solver() {
    //sudoku userSudoku;
    classicSudoku userSudoku;
    int n = 3;
    std::string sudokuLine;
    std::cout << "Enter 9 numbers in format of string: xxxxxxxxx" << std::endl;
    std::cout << "Enter each out of 9 line to set sudoku1 and type 0 instead of empty cells\n";
    for (int i = 0; i < n*n; i++){
        std::cin >> sudokuLine;
        if (sudokuLine.length() != 9) {i--; std::cout << "Invalid format\n"; continue;}
        for (int j = 0; j < n*n; j++) {
            userSudoku.sdk->table[i][j] = int(sudokuLine[j] - '0');
        }
    }
    for (int i = 0; i < n*n; i++){
        for (int j = 0; j < n*n; j++){
            if (!userSudoku.sdk->safeCell(i ,j)){std::cout << "Your table is not valid\n"; return;}
        }
    }
    userSudoku.sdk->fill(0 , 0);
    userSudoku.show();
}

void classicSudoku::show() {
    char nextSymbol;
    for (int i = 0; i < 4*sdk->fullSize+4; i++){std::cout << "_";}
    std::cout << std::endl;
    for (int i = 0; i < sdk->fullSize; i++)
    {
        for (int j = 0; j < sdk->fullSize; j++) {
            nextSymbol = sdk->defineSymbol(sdk->table[i][j]);
            if (j % sdk->secSize == sdk->secSize-1) {
                std::cout << nextSymbol << "  |  ";
            } else {
                std::cout << nextSymbol << "   ";
            }
        }
        std::cout << std::endl;
        if (i % sdk->secSize == sdk->secSize-1) {
            for (int i = 0; i < 4*sdk->fullSize+4; i++){std::cout << "_";}
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}