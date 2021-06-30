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

void Space::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    int x=0;
}
int Space::determine_rent(std::vector<Space*>& spaces){
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
void GO::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
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
void Go_To_Jail::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    std::cout<<"Go to jail!!!";
    player.in_jail=true;
    player.position=11;
}

Income_Tax::Income_Tax()
    :Space("Income Tax")
{}
void Income_Tax::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
	/*int net_worth=player.cash-player.debt;
	for (int i=0; i<player.get_num_properties_owned(); i++){
        int x = player.get_property_owned(i);
        Property p = dynamic_cast<Property>(*spaces[x]);
		net_worth=net_worth+p->get_value()+(p->get_num_houses())*(p->get_house_val())+(p->get_num_hotels())*(p->get_hotel_val());
	}
	int tax=net_worth*0.1;
	if (tax<2000){
		std::cout<<"You paid $"<<tax<<".\n";
		player.cash-=tax;
	}
	else{
		std::cout<<"You paid $2000.\n";
		player.cash-=2000;
	
	}*/
}
Interest_on_credit_card_debt::Interest_on_credit_card_debt()
    :Space("Interest on credit card debt")
{}
void Interest_on_credit_card_debt::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    player.cash-=750;
    std::cout<<"You paid $750\n";
}
Community_Chest::Community_Chest()
    :Space("Community Chest")
{}
void Community_Chest::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    std::string input;
    int pos = player.position;
    /*std::cout<<"Press p to select a card\n";
    std::cin>>input;
    Card& selected_card = *(community_chest_cards[0]);
    community_chest_cards.erase(community_chest_cards.begin());
    community_chest_cards.push_back(&selected_card);
    selected_card.function(player, spaces, players);*/
}

Chance::Chance()
    :Space("Chance")
{}
void Chance::action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    //std::string input;
    int pos = player.position;
    /*std::cout<<"Press p to select a card\n";
    std::cin>>input;
    std::cout<<"Card selected\n";
    (chance_cards[0])->function(player, spaces, players);*/
    /* Card& selected_card = *(chance_cards[0]);
    std::cout<<"selected card assigned\n";
    chance_cards.push_back(chance_cards[0]);
    std::cout<<"Selected card added to end\n";
    chance_cards.erase(chance_cards.begin());
    std::cout<<"Selected card deleted\n";
    chance_cards[chance_cards.size()-1]->function(player, spaces, players);*/
}
