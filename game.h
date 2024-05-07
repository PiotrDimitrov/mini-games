#include <iostream>
#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H


#include "sudoku.h"

class record {
public:
    record();
    ~record();
private:
    double time;
    int difficulty;
    int getTime(std::string str);
    int getDiff(std::string str);
    friend class game;
};

class game {
public:
    game();
    ~game();
private:
    int enter();
    void play(int diff);
    record rec;
};

#endif //SUDOKU_GAME_H
