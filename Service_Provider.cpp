#include <iostream>
#include "Service_Provider.h"
#include "Player.h"
Service_Provider::Service_Provider(){}
Service_Provider::Service_Provider(std::string new_name, int new_position)
    :Property(new_name, new_position)
    {}
int Service_Provider::get_value() {
    return 1500;
}

int Service_Provider::get_mortgage_value() {
    return 750;
}
std::string Service_Provider::get_color() {
    return "sp";
}

int Service_Provider::get_num_houses() {
    return 0;
}

int Service_Provider::get_num_hotels() {
    return 0;
}

int Service_Provider::get_house_val() {
    return 0;
}

int Service_Provider::get_hotel_val() {
    return 0;
}

int Service_Provider::determine_rent(std::vector<Space*>& spaces_ref, int dice_rolled) {
    int count=0;
    for (int x=0; x<spaces_ref.size(); x++){
	if (spaces_ref[x]->get_owner()==owner_name && spaces_ref[x]->get_color()==Service_Provider::get_color()){
	    count++;
	}
    }
    switch(count){
        case 1:
            return 40*dice_rolled;
            break;
        case 2:
            return 100*dice_rolled;
            break;
	default:
	    return 0;
    }
}
void Service_Provider::action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref) {
	std::string input=" ";
	int rent = 0;
	while(input!="y" && input!="n" && input!="rent"){
		if (Service_Provider::get_owner() == "no one"){
			std::cout<<Service_Provider::get_name()<<" is not owned. Would you like to buy it for $"<<Service_Provider::get_value()<<"?(y/n)\n";
			std::cin>>input;
		}
		else if (Service_Provider::get_owner() == player.get_name()){
			std::cout<<"You own "<<name<<".\n";
			input="n";
		}
		else if (mortgaged) {
			std::cout<<name<<" is mortgaged.\n";
			input="n";
		}
		else {
			rent = Service_Provider::determine_rent(spaces_ref, dice_rolled);
			std::cout<<Service_Provider::get_name()<<" is owned by "<<Service_Provider::get_owner()<<". Rent is $"<<rent<<".\n";
			input="rent";
		}
	}
	if (input=="y"){
		Service_Provider::set_owner(player.get_name());
		player.add_cash(-Service_Provider::get_value());
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
		std::cout<<"Rent paid to "<<Service_Provider::get_owner()<<"\n";
	}
}
void Service_Provider::show_details(){
	std::cout<<"\n"<<name<<"\n";
	if (mortgaged){
		std::cout<<"MORTGAGED\n";
	}
	std::cout<<"If one \"Service Provider\" is owned, rent is 40 times amount shown on dice.\n";
	std::cout<<"If both \"Serivce Providers\" are owned, rent is 100 times amount shown on dice.\n";
	std::cout<<"Mortgage value	$750\n\n";
}
