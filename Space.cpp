#include <string>
#include <vector>
#include <iostream>
#include "Space.h"
#include "Player.h"

Space::Space(){}
Space::Space(std::string new_name)
    : name(new_name)
    , mortgaged(false)
    , owner("")
    , num_houses(0)
    , hotel(false)
{}
    
std::string Space::get_name() {
    return name;
}

int Space::get_value() {
    return 0;
}

int Space::get_house_val() {
    return 0;
}

int Space::get_hotel_val() {
    return 0;
}

std::string Space::get_color () {
    return "";
}

void Space::action(Player& player, GameBoard& gb, std::vector<Player>& players) {
    int x=0;
}
void Space::show_details() {
    std::cout<<"";
}

int Space::get_mortgage_value () {
    return 0;
}

std::string Space::CSVstring() {
	return name;
}
