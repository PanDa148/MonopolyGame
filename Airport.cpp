#include "Airport.h"
#include <iostream>
#include "Player.h"
Airport::Airport(){}
Airport::Airport(std::string new_name, int new_position)
    :Property(new_name, new_position)
    {}
int Airport::get_value() {
    return 2000;
}

int Airport::get_mortgage_value() {
    return 1000;
}
std::string Airport::get_color() {
    return "air";
}

int Airport::get_num_houses() {
    return 0;
}

int Airport::get_num_hotels() {
    return 0;
}

int Airport::get_house_val() {
    return 0;
}

int Airport::get_hotel_val() {
    return 0;
}

int Airport::determine_rent(std::vector<Space*>& spaces_ref) {
    int count=0;
    for (int x=0; x<spaces_ref.size(); x++){
	if (spaces_ref[x]->get_owner()==owner_name && spaces_ref[x]->get_color()==Airport::get_color()){
	    count++;
	}
    }
    switch(count){
        case 1:
            return 250;
            break;
        case 2:
            return 500;
            break;
        case 3:
            return 1000;
            break;
        case 4:
            return 2000;
            break;
	default:
	    return 0;
    }
}

void Airport::action(Player& player, std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
	std::string input=" ";
	int rent = 0;
	while(input!="y" && input!="n" && input!="rent"){
		if (Airport::get_owner() == "no one"){
			std::cout<<Airport::get_name()<<" is not owned. Would you like to buy it for $"<<Airport::get_value()<<"?(y/n)\n";
			std::cin>>input;
		}
		else if (Airport::get_owner() == player.get_name()){
			std::cout<<"You own "<<name<<".\n";
			input="n";
		}
		else if (mortgaged) {
			std::cout<<name<<" is mortgaged.\n";
			input="n";
		}
		else {
			rent = Airport::determine_rent(spaces_ref);
			std::cout<<Airport::get_name()<<" is owned by "<<Airport::get_owner()<<". Rent is $"<<rent<<".\n";
			input="rent";
		}
	}
	if (input=="y"){
		Airport::set_owner(player.get_name());
		player.add_cash(-Airport::get_value());
		player.add_property(position);
	}
	if (input=="rent"){
		player.add_cash(-rent);
		for (int x = 0; x<players_ref.size(); x++){
			if (players_ref[x].get_name()==owner_name){
				
				players_ref[x].add_cash(rent);
				break;
			}
		}
		std::cout<<"Rent paid to "<<Airport::get_owner()<<"\n";
	}
}

void Airport::show_details(){
	std::cout<<"\n"<<name<<"\n";
	if (mortgaged){
		std::cout<<"MORTGAGED\n";
	}
	std::cout<<"Rent			$250\n";
	std::cout<<"If 2 Airports are owned      500\n";
	std::cout<<"If 3     \"     \"    \"       1000\n";
	std::cout<<"If 4     \"     \"    \"       2000\n";
	std::cout<<"Mortgages value            $1000\n\n";
}
