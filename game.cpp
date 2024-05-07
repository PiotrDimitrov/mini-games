#include "sudoku.h"
#include "game.h"
#include <iostream>
#include <chrono>
#include <fstream>

game::game() {
    srand(time(0));

    int difficulty = enter();
    if (difficulty != 5) { play(difficulty);}
}

game::~game() {

}


int game::enter() {
    char input;
    std::cout << "  -= SUDOKU GAME =-  " << std::endl;
    std::cout << "Choose your difficulty: " << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    std::cout << "4. Insane" << std::endl;
    std::cout << "5. Quit the game" << std::endl;
    while (true)
    {
        std::cin >> input;
        if (int(input) > 53 || int(input) < 49)
        {
            std::cout << "Enter valid value!" << std::endl;
        } else {
            return (int(input) - 48);
        }
    }
    return 1;
}

void game::play(int diff) {
    rec.difficulty = diff;
    sudoku sudokuTable;
    diff = (diff - 1) * 4 + 40;
    diff = 1;
    sudokuTable.construct();
    int cells = sudokuTable.puzzle(diff);
    sudokuTable.show();
    std::cout << "Fill numbers in table in format: row column number (integers)" << std::endl;
    int r, c, n; int errors = 0;
    time_t start, end;
    time(&start);
    while (cells > 0){
        std::cin >> r >> c >> n;
        if (n == -1) {return;}
        r--; c--;
        if (r > 8 || c >> 8 || r < 0 || c < 0 || n < 1 || n > 9)
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


    std::fstream file("records.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    int bestTime = 32760;
    while (std::getline(file, line))
    {
        if (rec.getDiff(line) != rec.difficulty){continue;}
        if (bestTime > rec.getTime(line)) {bestTime = rec.getTime(line);}
    }
    if (bestTime > rec.time) {std::cout << "New best. Your previous best result is " << bestTime << " seconds" << std::endl;}
    file.close();
}