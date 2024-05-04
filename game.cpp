#include "sudoku.h"
#include "game.h"
#include <iostream>
#include <chrono>

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
    sudoku sudokuTable;
    diff = (diff - 1) * 3 + 40;
    sudokuTable.construct();
    int cells = sudokuTable.puzzle(diff);
    sudokuTable.show();
    std::cout << "Fill numbers in table in format: row column number (integers)" << std::endl;
    int r, c, n;
    auto start = std::chrono::high_resolution_clock::now();
    int errors = 0;
    while (cells > 0){
        std::cin >> r >> c >> n;
        if (n == -1) {return; break;}
        r--; c--;
        if (r > 8 || c >> 8 || r < 0 || c < 0 || n < 1 || n > 9)
        {std::cout << "Invalid input" << std::endl; continue;}
        if (sudokuTable.table[r][c] > 0) {std::cout << "Cell isnt empty" << std::endl;
            continue;}
        if (sudokuTable.table[r][c] == (-1)*n) {sudokuTable.table[r][c] *= (-1); cells--;}
        else {std::cout << "Wrong!" << std::endl; errors++; continue;}
        sudokuTable.show();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto time = stop - start;
    std::cout << "Time: " << time.count() << " seconds" << std::endl;
    std::cout << "Wrong guesses: " << errors << std::endl;
}