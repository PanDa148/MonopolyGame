#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.h"
#include "Player.h"

Card::Card(){}
Card::Card(std::string new_text)
	: text(new_text)
{}

Card::Card(std::string new_text, bool j)
	: text(new_text)
	, jail(j)
{}

void Card::print() {
	std::cout<<text<<"\n";
}

void Card::action(Player& player) {
	print();
}