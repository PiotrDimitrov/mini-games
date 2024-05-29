#include "game.h"
#include <iostream>
#include <chrono>
#include "games/sudoku/classicSudoku.h"

game::game() {

}

game::~game() {

}

void game::defineMode(){
    std::cout << "1. Sudoku" << std::endl;
    std::cout << "2. Wordly" << std::endl;
    std::cout << "3. 15 Puzzle" << std::endl;
    std::cout << "4. " << std::endl;

    std::string input;
    std::cin >> input;
    std::string temp;
    int counter = 0;
    for (int i = 0; i < input.length(); i++){
        if (input[i] <= '9' && input[i] >= '0'){
            temp = temp + input[i];
            counter++;
        }
        if (counter >= 2) {break;}
    }
    input = temp;
    if (input.length() == 1){
        mode = (input[0] -'0');
    } else if (input.length() == 2){
        mode = (input[1] -'0') + (input[0] -'0')*10;
    } else {std::cout << "Invalid input\n"; mode = -1;}
}

void game::defineSubMode() {
    std::string input;
    switch (mode) {
        case 1:
            std::cout << "Classic 9x9: " << std::endl;
            std::cout << "1. Easy 9x9" << std::endl;
            std::cout << "2. Medium 9x9" << std::endl;
            std::cout << "3. Hard 9x9" << std::endl;
            std::cout << "4. Insane 9x9" << std::endl;
            std::cout << std::endl << "Classic 16x16: " << std::endl;
            std::cout << "5. Easy 16x16" << std::endl;
            std::cout << "6. Medium 16x16" << std::endl;
            std::cout << "7. Hard 16x16" << std::endl;
            std::cout << std::endl << "Multi-sudoku: " << std::endl;
            std::cout << "8. Double-doku" << std::endl;
            std::cout << "9. Triple-doku" << std::endl;
            std::cout << "10. Samurai sudoku" << std::endl;
            std::cout << "11. Sohei sudoku" << std::endl;
            std::cout << "12. Double-doku column" << std::endl;
            std::cout << "13. Triple-doku column" << std::endl;
            std::cout << "14. Cross sudoku" << std::endl;
            std::cout << std::endl << "Other options: " << std::endl;
            std::cout << "15. Solve my 9x9 sudoku" << std::endl;
            std::cout << "16. Quit" << std::endl;
            break;
        case 2:
            std::cout << "1. Four letters words" << std::endl;
            std::cout << "2. Five letters words" << std::endl;
            std::cout << "3. Six letters words" << std::endl;
            std::cout << "4. Seven letters words" << std::endl;
            std::cout << "5. Quit" << std::endl;
            break;
        case 3:
            std::cout << "1. 4x4 puzzle" << std::endl;
            std::cout << "2. 5x5 puzzle" << std::endl;
            std::cout << "3. Quit" <<std::endl;
            break;
    }

            std::cin >> input;
            std::string temp;
            int counter = 0;
            for (int i = 0; i < input.length(); i++){
                if (input[i] <= '9' && input[i] >= '0'){
                    temp = temp + input[i];
                    counter++;
                }
                if (counter >= 2) {break;}
            }
            input = temp;
            if (input.length() == 1){
                submode = (input[0] -'0');
            } else if (input.length() == 2){
                submode = (input[1] -'0') + (input[0] -'0')*10;
            } else {std::cout << "Invalid input\n"; submode = -1;}
}

void game::launch() {
    switch (mode) {
        //SUDOKU
        case 1:
            if (1 <= submode && submode <= 7){
                classicSudoku clssdk(submode/5 + 3);
                difficulty = submode;
                int diff = clssdk.sdk->puzzle(difficulty);
                clssdk.difficulty = diff;
                clssdk.play();
            }
            else if (submode == 15){
                classicSudoku::solver();
            }

    }
}

void game::solver() {
    sudoku1 userSudoku;
    int n = 3;
    std::string sudokuLine;
    std::cout << "Enter 9 numbers in format of string: xxxxxxxxx" << std::endl;
    std::cout << "Enter each out of 9 line to set sudoku1 and type 0 instead of empty cells\n";
    for (int i = 0; i < n*n; i++){
        std::cin >> sudokuLine;
        if (sudokuLine.length() != 9) {i--; std::cout << "Invalid format\n"; continue;}
        for (int j = 0; j < n*n; j++) {
            userSudoku.table[i][j] = int(sudokuLine[j] - '0');
        }
    }
    for (int i = 0; i < n*n; i++){
        for (int j = 0; j < n*n; j++){
            if (!userSudoku.safeCell(i ,j)){std::cout << "Your table is not valid\n"; return;}
        }
    }
    userSudoku.construct(false);
    userSudoku.show();
}




