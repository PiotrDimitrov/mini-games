#include "multidoku.h"

multidoku::multidoku() {
    this->number = 2;
    tables.reserve(number);
    sudoku first;
    first.construct();
    tables.push_back(first);
    this->first = first;
    std::vector<int> vec = {-1, -1, -1, -1, 0, 1, -1, 3, 4};
    for (int i = 1; i < number; i++){
        sudoku temp(tables[i-1], vec);
        temp.fill(0,0);
        tables.push_back(temp);
        if (i == 1) {second = temp;}
        if (i == 2) {third = temp;}
    }
}

multidoku::multidoku(int number) {
    this->number = number;
    tables.reserve(number);
    sudoku f;
    f.construct();
    tables.push_back(f);
    this->first = f;
    std::vector<int> vec = {-1, -1, -1, -1, 0, 1, -1, 3, 4};
    for (int i = 1; i < number; i++){
        sudoku temp(tables[i-1], vec);
        temp.fill(0,0);
        tables.push_back(temp);
        if (i == 1) {second = temp;}
        if (i == 2) {third = temp;}
    }
}

multidoku::~multidoku() {

}

void multidoku::show() {

}

void multidoku::play() {

}

void multidoku::puzzle() {
for (auto e : tables){
    e.puzzle(3);
}
    for (int n = 0; n < number-1; n++){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (i >= 6 && j>= 6 && n + 2 <= number-1){
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3] = tables[n+2].table[i-6][j-6];
                } else if (i >= 6 && j>= 6) {
                    if (n+1 >= number){ continue;}
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3];
                } else if (i >= 3 && j >= 3){
                    if (n+1 >= number){ continue;}
                    tables[n].table[i][j] = tables[n+1].table[i-3][j-3];
                }
            }
        }
    }
}

void multidoku::setCell(int i, int j, int value, int num) {

}

void multidoku::puzzleCell(int i, int j, int num) {
    if (j < 0 || i < 0 || num <= number) { return;}
    tables[num].table[i][j] *= (-1);
    puzzleCell(i-3, j-3, num+1);
}

