#include "sudoku1.h"
#include "game.h"
#include <windows.h>

int main() {
    std::cout << " I want to be nice today!" << std::endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k;
    for(k = 0; k < 256; k++)
    {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        std::cout << k << " I want to be nice today!" << std::endl;
    }

//game newGame;   //create game instance to start game
}