#include <iostream>
#include <fstream>
#include "sudoku.h"
#include "game.h"

record::record() {
    difficulty = -1;
    time = 0;
}

int record::getTime(std::string str) {
    int index = 0;
    while (true){
        if (str[index + 1] == '!'){
            break;
        }
        index++;
    }
    int counter = 0; int res = 0;
    while (str[index] != ' '){
        int power = 1;
        for (int i = 0; i < counter; i++){
            power *= 10;
        }
        res += (str[index] - '0') * power;
        counter++; index--;
    }
    return res;
}

int record::getDiff(std::string str){
    return (str[0] - '0')*1;
}

record::~record() {
    if (difficulty < 0) {
        std::cout << "Sorry, your record can not be processed (code 1)\n";
        return;
    }
    std::fstream fs;
    fs.open("records.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if (!fs.is_open()) {std::cout << "Sorry, your record can not be processed (code 2)\n"; return;}
    fs << difficulty << " " << time << "!" << std::endl;
    fs.close();
}