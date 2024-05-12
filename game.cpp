#include "sudoku.h"
#include "game.h"
#include <iostream>
#include <chrono>

game::game() {
    //game starting
    srand(time(0));
    difficulty = enter();
    if (difficulty >= 9) { return;}
    if (difficulty == 8) {solver();}
    else { play(); }
}

game::~game() {

}

int game::enter() {
    //function to determine difficulty of current game
    int input;
    std::cout << "  -= SUDOKU GAME =-  " << std::endl;
    std::cout << "Choose your game mode: " << std::endl;
    std::cout << "1. Easy 9x9" << std::endl;
    std::cout << "2. Medium 9x9" << std::endl;
    std::cout << "3. Hard 9x9" << std::endl;
    std::cout << "4. Insane 9x9" << std::endl;
    std::cout << "5. Easy 16x16" << std::endl;
    std::cout << "6. Medium 16x16" << std::endl;
    std::cout << "7. Hard 16x16" << std::endl;
    std::cout << "8. Solve my sudoku" << std::endl;
    std::cout << "9. Quit the game" << std::endl;
    while (true)
    {
        std::cin >> input;
        if (input < 1 || input > 9)
        {
            std::cout << "Enter valid value!" << std::endl;
        } else {
            break;
        }
    }
    return input;
}

void game::play() {
    //main game process
    rec.difficulty = this->difficulty;
    int size;
    if (difficulty >= 5) {size = 4;} else {size = 3;};
    sudoku sudokuTable(size);
    sudokuTable.construct();
    int cells = sudokuTable.puzzle(difficulty);
    sudokuTable.show();
    std::cout << "Fill numbers in table in format: row column number (integers)" << std::endl;
    int r, c, n; int errors = 0;
    time_t start, end;
    int sz = sudokuTable.fullSize;
    time(&start);
    while (cells > 0){
        std::cin >> r >> c >> n;
        if (n < -1 || r < -1 || c < -1) {return;}
        r--; c--;
        if (r > (sz-1) || c > (sz-1) || r < 0 || c < 0 || n < 1 || n > sz)
        {std::cout << "Invalid input" << std::endl; continue;}
        if (sudokuTable.table[r][c] > 0) {std::cout << "Cell isn't empty\n"; continue;}
        if (sudokuTable.table[r][c] == (-1)*n) {sudokuTable.table[r][c] *= (-1); cells--;}
        else {std::cout << "Wrong!" << std::endl; errors++; continue;}
        sudokuTable.show();
    }
    time(&end);
    double solveTime = difftime(end, start);
    rec.time = solveTime;
    std::cout << "Time: " << solveTime << " seconds" << std::endl;
    std::cout << "Wrong guesses: " << errors << std::endl;
    record::checkBest(this->rec);
}

void game::solver() {
    sudoku userSudoku;
    int n =  3;
    std::string sudokuLine;
    std::cout << "Enter 9 numbers in format of string: xxxxxxxxx" << std::endl;
    std::cout << "Enter each out of 9 line to set sudoku and type 0 instead of empty cells\n";
    for (int i = 0; i < n*n; i++){
        std::cin >> sudokuLine;
        if (sudokuLine.length() != 9) {i--; std::cout << "Invalid format\n"; continue;}
        for (int j = 0; j < n*n; j++) {
            userSudoku.table[i][j] = int(sudokuLine[j] - '0');
        }
    }
    userSudoku.construct(false);
    userSudoku.show();
}