#include "game.h"
#include <iostream>

game::game() {
    srand(time(0));
    sudoku solved;
    solved.construct();
    sudoku unsolved = solved;
    unsolved.puzzle(50);
    unsolved.show();
}

game::~game() {

}