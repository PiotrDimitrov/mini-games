#include "multidoku.h"
#include <iostream>

multidoku::multidoku() {
    this->number = 2;
    tables.reserve(number);
    sudoku f;
    f.construct();
    tables.push_back(f);
    this->first = f;
    std::vector<int> vec = {-1, -1, -1, -1, 0, 1, -1, 3, 4};
    for (int i = 1; i < number; i++){
        sudoku temp(tables[i-1], vec);
        temp.fill(0,0);
        tables.push_back(temp);
        if (i == 1) {second = temp;}
        if (i == 2) {third = temp;}
    }
}

multidoku::multidoku(int number) {
    this->number = number;
    tables.reserve(number);
    sudoku f;
    f.construct();
    tables.push_back(f);
    this->first = f;
    std::vector<int> vec = {-1, -1, -1, -1, 0, 1, -1, 3, 4};
    for (int i = 1; i < number; i++){
        sudoku temp(tables[i-1], vec);
        temp.fill(0,0);
        tables.push_back(temp);
        if (i == 1) {second = temp;}
        if (i == 2) {third = temp;}
    }
}

multidoku::~multidoku() {

}

void multidoku::show() {
    char next;
    int n = 0;
    std::string tab = " ";
    for (int i = 0; i < 3*(number+2); i++){
        if (i % 9 == 0 && i != 0) {tab += "      ";}
        for (int j = 0; j < 9; j++){
            std::cout << tables[n].table[i][j];
        }
        if (i >= 3 && i < 3*(number+2)-3){
            for (int j = 0; j < 9; j++){
                std::cout << tables[n].table[i][j];
            }
        }
        if (i >= 6 && i < 3*(number+2)-6){
            for (int j = 0; j < 9; j++){
                std::cout << tables[n].table[i][j];
            }
        }
        std::cout << std::endl;
    }

}

void multidoku::play() {
    int empty = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int n = 0; n < number; n++) {
                if (tables[n].table[i][j] <= 0) { empty++; }
            }
        }
    }
    std::cout << "Fill numbers in table in format: row column number (integers)" << std::endl;
    int r, c, n;
    int errors = 0;
    std::string input;
    time_t start, end;
    time(&start);
    while (empty > 0) {
        std::cin >> input;
        if (input == "Quit" || input == "quit") { return; }
        r = int(input[0] - '0');
        c = int(input[2] - '0');
        n = int(input[4] - '0');
        r--;
        c--;
        if (r > 3 * (number + 2) || c > 3 * (number + 2) || r < 0 || c < 0 || n < 1 || n > 9) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        int n = 0;
        if (r >= 9 && r <= 11 && c >= 9 && c <= 11) {n = 1; c-=3; r-=3;}
        else if (r >= 12 && r <= 14 && c >= 12 && c <= 14) {n = 2; c-=6; r-=6;}
        if (tables[n].table[r][c] > 0) {std::cout << "Cell isn't empty\n"; continue;}
        if (tables[n].table[r][c] != -1*n) {std::cout << "Wrong!" << std::endl; errors++; continue;}
        else {
            puzzleCell(r, c, n, empty);
        }
        print();
    }
    time(&end);
    double solveTime = difftime(end, start);
    std::cout << "Time: " << solveTime << " seconds" << std::endl;
    std::cout << "Wrong guesses: " << errors << std::endl;
}

void multidoku::puzzle() {

for (int i = 0; i < number - 1; i++){
    tables[i].puzzle(1);
}
tables[number - 1].puzzle(4);
    for (int n = 0; n < number-1; n++){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (i >= 6 && j>= 6 && n + 2 <= number-1){
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3] = tables[n+2].table[i-6][j-6];
                } else if (i >= 6 && j>= 6) {
                    if (n+1 >= number){ continue;}
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3];
                } else if (i >= 3 && j >= 3){
                    if (n+1 >= number){ continue;}
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3];
                }
            }
        }
    }
}

void multidoku::setCell(int i, int j, int value, int num) {

}

void multidoku::puzzleCell(int i, int j, int num, int& emp) {
    tables[num].table[i][j] *= (-1); emp--;
    if (j-3 >= 0 && i-3 >= 0 && num+1 < number) { puzzleCell(i-3, j-3, num+1, emp);}
    if (i+3 < 9 && j+3 < 9 && num-1 >= 0) {puzzleCell(i+3, j+3, num-1, emp);}
}


void multidoku::print() {
    if (number == 2) {printTwo();}
    if (number == 3) {printThree();}
    return;
}

void multidoku::printTwo() {
    char next;
    for (int i = 0; i < 3; i++){
        std::cout << " | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[0].table[i][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 3; i < 9; i++){
        std::cout << " | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[0].table[i][j]);
            std::cout << next << "  ";
        }
        for (int j = 0; j < 3; j++){
            next = sudoku::defineSymbol(tables[1].table[i-3][j+6]);
            std::cout << next;
            if (j == 2) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 6; i < 9; i++){
        std::cout << "          | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[1].table[i][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }
}


void multidoku::printThree() {
    char next;
    for (int i = 0; i < 3; i++){
        std::cout << " | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[0].table[i][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 3; i < 6; i++){
        std::cout << " | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[0].table[i][j]);
            std::cout << next << "  ";
        }
        for (int j = 0; j < 3; j++){
            next = sudoku::defineSymbol(tables[1].table[i-3][j+6]);
            std::cout << next;
            if (j == 2) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 6; i < 9; i++){
        std::cout << " | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[0].table[i][j]);
            std::cout << next << "  ";
        }
        for (int j = 6; j < 9; j++){
            next = sudoku::defineSymbol(tables[1].table[i-1][j]);
            std::cout <<  next << "  ";
        }
        for (int j = 6; j < 9; j++){
            next = sudoku::defineSymbol(tables[1].table[i-2][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 6; i < 9; i++){
        std::cout << "          | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[1].table[i][j]);
             std::cout << next << "  ";
        }
        for (int j = 6; j < 9; j++){
            next = sudoku::defineSymbol(tables[2].table[i-3][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }

    for (int i = 6; i < 9; i++){
        std::cout << "                   | ";
        for (int j = 0; j < 9; j++){
            next = sudoku::defineSymbol(tables[2].table[i][j]);
            std::cout << next;
            if (j == 8) {std::cout << " |" << std::endl;}
            else {std::cout << "  ";}
        }
    }
}
