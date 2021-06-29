#include <iostream>
#include "Dice.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib>

Dice::Dice()
    :die1(0)
    ,die2(0)
{}
    
int Dice::get_roll() {
    return die1+die2;
}
bool Dice::is_doubles() {
    return die1==die2;
}

void Dice::roll() {
    std::cout<<"Press r to roll\n";
    std::string input;
    std::cin >> input;
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    std::cout<<"You rolled: "<<die1+die2<<"\n";
}
