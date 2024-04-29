#include <iostream>
#include "game.h"

int main() {
    srand(time(0));
    sudokuTable s;
    s.construct();
    s.show();
    int r = 1, c = 0, se = 0;
    while (true)
    {
        std::cin >> r >> c >> se;
        if (r > 10) { break; }
        sudokuTable::candidate* ca = s.checkCell(r,c,se);
        std::cout << ca->size;
        delete ca;
    }
}
