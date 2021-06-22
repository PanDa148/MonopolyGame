#include <string>
#include <vector>
#include <iostream>
#include "Space.h"
#include "Player.h"
#include "Card.h"

Space::Space(){}
Space::Space(std::string new_name, int new_position)
    : name(new_name)
    , position(new_position)
{}
    
std::string Space::get_name() {
    return name;
}

int Space::get_position(){
	return position;
}

void Space::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    int x=0;
}
int Space::determine_rent(std::vector<Space*>& spaces_ref){
	return 0;
}
std::string Space::get_owner(){
	int x=0;
	return " ";
}

std::string Space::get_color(){
	return " ";
}

bool Space::is_mortgaged(){
	return false;
}

int Space::get_mortgage_value(){
	return 0;
}

void Space::set_mortgage(bool new_mortgage){
	int x=0;
}

int Space::get_num_houses(){	
	return 0;
}
int Space::get_num_hotels(){	
	return 0;
}
int Space::get_house_val(){	
	return 0;
}
int Space::get_hotel_val(){	
	return 0;
}
int Space::get_value(){
	return 0;
}
void Space::show_details(){
	int x=0;
}

GO::GO(int new_position)
    :Space("Go", new_position)
{}
void GO::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    player.add_cash(2000);
}

Jail::Jail(int new_position)
    :Space("Jail", new_position)
{}

Free_Parking::Free_Parking(int new_position)
    :Space("Free Parking", new_position)
{}

Go_To_Jail::Go_To_Jail(int new_position)
    :Space("Go To Jail", new_position)
{}
void Go_To_Jail::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    std::cout<<"Go to jail!!!";
    player.change_jail_status(true);
    player.set_position(11);
}

Income_Tax::Income_Tax(int new_position)
    :Space("Income Tax", new_position)
{}
void Income_Tax::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
	int net_worth=player.get_cash()-player.get_debt();
	for (int x=0; x<spaces_ref.size(); x++){
		if(spaces_ref[x]->get_owner()==player.get_name()){
			net_worth=net_worth+spaces_ref[x]->get_value()+(spaces_ref[x]->get_num_houses())*(spaces_ref[x]->get_house_val())+(spaces_ref[x]->get_num_hotels())*(spaces_ref[x]->get_hotel_val());
		}
	}
	int tax=net_worth*0.1;
	if (tax<2000){
		std::cout<<"You paid $"<<tax<<".\n";
		player.add_cash(-tax);
	}
	else{
		std::cout<<"You paid $2000.\n";
		player.add_cash(-2000);
	
	}
}
Interest_on_credit_card_debt::Interest_on_credit_card_debt(int new_position)
    :Space("Interest on credit card debt", new_position)
{}
void Interest_on_credit_card_debt::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    player.add_cash(-750);
    std::cout<<"You paid $750\n";
}
Community_Chest::Community_Chest(int new_position)
    :Space("Community Chest", new_position)
{}
void Community_Chest::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    std::string input;
    position = player.get_position();
    /*std::cout<<"Press p to select a card\n";
    std::cin>>input;
    Card& selected_card = *(community_chest_cards_ref[0]);
    community_chest_cards_ref.erase(community_chest_cards_ref.begin());
    community_chest_cards_ref.push_back(&selected_card);
    selected_card.function(player, spaces_ref, players_ref);*/
}

Chance::Chance(int new_position)
    :Space("Chance", new_position)
{}
void Chance::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
    //std::string input;
    position = player.get_position();
    /*std::cout<<"Press p to select a card\n";
    std::cin>>input;
    std::cout<<"Card selected\n";
    (chance_cards_ref[0])->function(player, spaces_ref, players_ref);*/
    /* Card& selected_card = *(chance_cards_ref[0]);
    std::cout<<"selected card assigned\n";
    chance_cards_ref.push_back(chance_cards_ref[0]);
    std::cout<<"Selected card added to end\n";
    chance_cards_ref.erase(chance_cards_ref.begin());
    std::cout<<"Selected card deleted\n";
    chance_cards_ref[chance_cards_ref.size()-1]->function(player, spaces_ref, players_ref);*/
}
