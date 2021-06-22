#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.h"
#include "Player.h"
#include "Dice.h"
#include "Space.h"

Card::Card(){}
Card::Card(std::string new_text)
	: text(new_text)
{}

void Card::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	int x=0;
}

Collect::Collect (std::string new_text, int new_amount)
	: Card(new_text)
	, amount(new_amount)
{}

void Collect::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	player.add_cash(amount);
}

Pay::Pay (std::string new_text, int new_amount)
	: Card(new_text)
	, amount(new_amount)
{}

void Pay::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	player.add_cash(-amount);
}

Go_to_jail::Go_to_jail (std::string new_text)
	: Card(new_text)
{}

void Go_to_jail::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	player.set_position(10);
	player.change_jail_status(true);
}

Collect_from_each_player::Collect_from_each_player(std::string new_text, int new_amount)
	: Card(new_text)
	, amount(new_amount)
{}

void Collect_from_each_player::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	for (int x=1; x<players_ref.size(); x++){
		players_ref[x].add_cash(-amount);
		player.add_cash(amount);
	}
}

Get_out_of_jail_free::Get_out_of_jail_free (std::string new_text)
	: Card(new_text)
{}

void Get_out_of_jail_free::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	player.set_get_out_of_jail_card(true);
}

Pay_for_each_residence::Pay_for_each_residence (std::string new_text, int new_house_amount, int new_hotel_amount)
	: Card(new_text)
	, house_amount(new_house_amount)
	, hotel_amount(new_hotel_amount)
{}

void Pay_for_each_residence::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	int num_houses=0;
	int num_hotels=0;
	for(int x = 0; x<spaces_ref.size(); x++){
		if(spaces_ref[x]->get_owner()==player.get_name()){
			num_houses=num_houses+spaces_ref[x]->get_num_houses();
			num_hotels=num_hotels+spaces_ref[x]->get_num_hotels();
		}
	}
	player.add_cash(-num_houses*house_amount-num_hotels*hotel_amount);
}

Advance_to::Advance_to(std::string new_text, int new_space_pos)
	: Card(new_text)
	, space_pos(new_space_pos)
	, space_color(" ")
{}

Advance_to::Advance_to(std::string new_text, std::string new_space_color)
       : Card(new_text)
       , space_color(new_space_color)
       , space_pos(100)
{}

void Advance_to::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	std::vector<Card*> cc;
	std::vector<Card*> c;
	if (space_color==" "){
		player.set_position(space_pos);
    		std::cout<<"You landed on "<<spaces_ref[space_pos]->get_name()<<"\n";
		spaces_ref[space_pos]->action(player, spaces_ref, 0, players_ref, cc, c);
	}
	else if (space_pos==100){
		while (spaces_ref[player.get_position()]->get_color() != space_color){			
			int old_pos = player.get_position();
			if ((old_pos+1)>39) {
				player.set_position(old_pos+1-40);
				std::cout<<"You passed GO!\n";
				player.add_cash(2000);
    			}
    			else {
        			player.advance_position(1);
    			}
		}
    		std::cout<<"You landed on "<<spaces_ref[player.get_position()]->get_name()<<"\n";
		if (spaces_ref[player.get_position()]->get_owner()=="no one"){
			spaces_ref[player.get_position()]->action(player, spaces_ref, 0, players_ref, cc, c);
		}
		else {
			int rent=0;
			if (space_color=="air"){
				rent = 2*spaces_ref[player.get_position()]->determine_rent(spaces_ref);
			}
			else if (space_color=="sp"){
				Dice dice;
				int roll = dice.get_roll();
				rent = 100*roll;
			}
			player.add_cash(-rent);
			for (int x = 0; x<players_ref.size(); x++){
				if (players_ref[x].get_name()==spaces_ref[player.get_position()]->get_owner()){
					players_ref[x].add_cash(rent);
					break;
					std::cout<<"Rent paid to "<<spaces_ref[player.get_position()]->get_owner()<<"\n";
				}
			}
		}
	}
}

Pay_each_player::Pay_each_player(std::string new_text, int new_amount)
	: Card(new_text)
	, amount(new_amount)
{}

void Pay_each_player::function(Player& player, std::vector<Space*>& spaces_ref, std::vector<Player>& players_ref){
	std::cout<<text<<"\n";
	for (int x=1; x<players_ref.size(); x++){
		players_ref[x].add_cash(amount);
		player.add_cash(-amount);
	}
}
