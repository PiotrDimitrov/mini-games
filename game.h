#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H
#include "sudoku.h"
#include <iostream>

class record { //class helps to write game records into a file
public:
    record();
    ~record();
private:
    double time;
    int difficulty;
    static int getTime(std::string str);
    static int getDiff(std::string str);
    static void checkBest(record r);
    friend class game;
};

class game {
public:
    game();
    ~game();
private:
    static int enter();
    int difficulty;
    void play();
    static void solver();
    record rec;
};
#endif //SUDOKU_GAME_H
