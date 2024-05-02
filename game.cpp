#include "game.h"
#include <iostream>

game::game() {
    srand(time(0));
    sudoku solved;
    solved.construct();
    sudoku unsolved = solved;

    unsolved.show();
}

game::~game() {

}