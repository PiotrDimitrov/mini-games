#include <iostream>
#include <fstream>
#include "sudoku1.h"
#include "game.h"

record::record() {  //default constructor
    difficulty = -1;
    time = 0;
}

int record::getTime(std::string str) {
    //receives string consisting of "difficulty" "time" format and returns time in integer
    //example: "2 130s" -> 130
    int index = 0;
    while (true){
        if (str[index + 1] == 's'){
            break;
        }
        index++;
    }
    int counter = 0;
    int res = 0;
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
    //receives string consisting of "difficulty" "time" format and returns difficulty in integer
    //example "1 30s" -> 1
    return int(str[0] - '0');
}

void record::checkBest(record r){
    //checks times through all records in a file and compares with current solving time
    std::fstream file("records.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string line;
    int bestTime = 32760;
    while (std::getline(file, line))
    {
        if (r.getDiff(line) != r.difficulty){continue;}
        if (bestTime > r.getTime(line)) {bestTime = r.getTime(line);}
    }
    if (bestTime > r.time) {
        if (bestTime == 32760) { bestTime = (int)r.time; }
        std::cout << "New best. Your previous best result is " << bestTime << " seconds" << std::endl;
    }
    file.close();
}

record::~record() {
    //default destructor writes data from record into file at the end of the program
    //writes data in format "difficulty" "time""s" (ex: "2 140s")
    if (difficulty < 0) {
        std::cout << "Sorry, your record can not be processed (code 1)\n";
        return;
    }
    if (time <= 0) {
        std::cout << "Sorry, your record can not be processed (code 5)\n";
        return;
    }
    std::fstream fs;
    fs.open("records.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if (!fs.is_open()) {std::cout << "Sorry, your record can not be processed (code 2)\n"; return;}
    fs << difficulty << " " << time << "s" << std::endl;
    fs.close();
}