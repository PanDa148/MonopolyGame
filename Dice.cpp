#include "Dice.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

Dice::Dice() : die1(0), die2(0){}

int Dice::get_roll () {
    return die1+die2;
}

bool Dice::is_doubles() {
    return die1==die2;
}

void Dice::normal() {
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
}

void Dice::test(std::vector<int> rolls) {
    if (i<rolls.size()) {
        die1=rolls[i];
        die2=rolls[i+1];
        i+=2;
    } 
    else {
        normal();
    }
}

void Dice::roll()  {
    std::cout<<"Press r to roll\n";
    std::string input;
    std::cin >> input;
    test(cards);
    std::cout<<"You rolled: "<<get_roll()<<"\n";
}