#include <iostream>
#include "game.h"

int main() {
    srand(time(0));
    sudokuTable s;
    s.construct();
    s.show();
}
