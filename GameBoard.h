#pragma once
#include "Dice.h"
class Space;
class GameBoard {
    private:
    Space* spaces[40];
    Dice dice;

    public:
    GameBoard();
    ~GameBoard();
    Space* operator[](int i);
    int length();
    void roll();
    int getRoll();
    bool isDoubles();
};