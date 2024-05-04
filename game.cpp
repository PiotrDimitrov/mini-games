#include "sudoku.h"
#include "game.h"
#include <iostream>

game::game() {
    srand(time(0));

    int difficulty = enter();
    if (difficulty != 5) { play(difficulty);}

}

game::~game() {

}


