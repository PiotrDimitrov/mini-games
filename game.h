#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H
#include "useless/sudoku1.h"
#include <iostream>

class record { //class helps to write game records into a file
public:
    record();
    ~record();
private:
    double time;
    int mode;
    int submode;
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
public:
    int mode;
    int submode;
    static int enter();
    int difficulty;
    void play();
    static void solver();
    record rec;
    void defineMode();
    void defineSubMode();
    void launch();
};
#endif //SUDOKU_GAME_H
