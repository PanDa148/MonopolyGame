#include <string>
#include <vector>
#include <iostream>
#include "Space.h"
#include "Player.h"
#include "Card.h"

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
int Space::determine_rent(GameBoard& gb){
	return 0;
}

void Space::show_details() {

}

int Space::get_mortgage_value () {
    return 0;
}

GO::GO()
    :Space("Go")
{}
void GO::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
    player.cash+=2000;
}

Jail::Jail()
    :Space("Jail")
{}

Free_Parking::Free_Parking()
    :Space("Free Parking")
{}

Go_To_Jail::Go_To_Jail()
    :Space("Go To Jail")
{}
void Go_To_Jail::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
    std::cout<<"Go to jail!!!";
    player.in_jail=true;
    player.position=11;
}

Income_Tax::Income_Tax()
    :Space("Income Tax")
{}
void Income_Tax::action(Player& player,  GameBoard& gb, std::vector<Player>& players) {
	int tax=player.calc_net_worth(gb)*0.1;
	if (tax<2000){
		std::cout<<"You paid $"<<tax<<".\n";
		player.cash-=tax;
	}
	else{
		std::cout<<"You paid $2000.\n";
		player.cash-=2000;
	
	}
}
Interest_on_credit_card_debt::Interest_on_credit_card_debt()
    :Space("Interest on credit card debt")
{}
void Interest_on_credit_card_debt::action(Player& player, GameBoard& gb,std::vector<Player>& players) {
    player.cash-=750;
    std::cout<<"You paid $750\n";
}

Card_Space::Card_Space(std::string type)
    :Space(type)
{}

Community_Chest::Community_Chest()
    :Card_Space("Community Chest")
{}

Chance::Chance()
    :Card_Space("Chance")
{}
