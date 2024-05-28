#include "sudoku.h"
#include "game.h"
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k;
    for(k = 1; k <= 256; k++)
    {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        std::cout << k << " I want to be nice today!" << std::endl;
    }

//game newGame;   //create game instance to start game
}