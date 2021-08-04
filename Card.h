#pragma once

#include <string>
#include <iostream>

class Space;
class Player;
class Card{
	protected:
	std::string text;
	public:
	Card();
	Card(std::string new_text);
    Card(std::string new_text, bool j);
    bool jail;
	void print();
	virtual void action(Player& player);
};
