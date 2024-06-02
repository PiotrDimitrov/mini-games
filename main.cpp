#include "useless/sudoku1.h"
#include "game.h"
#include <windows.h>
#include "games/sudoku/sudoku.h"
#include "games/sudoku/multidoku.h"

int main() {
game newGame;   //create game instance to start game
newGame.defineMode();
newGame.defineSubMode();
newGame.launch();

//sudoku first;
//first.construct();
//first.show();
//std::vector<int> vec = {-1, -1, -1, -1, 0, 1, -1, 3, 4};
//sudoku second(first, vec);
//second.show();
//second.fill(0,0);
//second.show();

//multidoku m(3);
//m.puzzle();
//m.print();
}




//    std::cout << " I want to be nice today!" << std::endl;
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    int k;
//    for(k = 0; k < 256; k++)
//    {
//        // pick the colorattribute k you want
//        SetConsoleTextAttribute(hConsole, k);
//        std::cout << k << " I want to be nice today!" << std::endl;
//    }