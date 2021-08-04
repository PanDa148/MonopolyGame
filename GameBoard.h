#pragma once
#include "Dice.h"
#include "Space.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

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
	void printSpacesCSV();
};
