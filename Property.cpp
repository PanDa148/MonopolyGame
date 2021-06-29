#include <string>
#include <vector>
#include <iostream>
#include "Property.h"
#include "Player.h"

Property::Property(){}
Property::Property(std::string new_name, int new_value, std::string new_color)
    : Space(new_name)
    , mortgaged(false)
    , owner("no one")
    , value(new_value)
    , color(new_color)
    , num_houses(0)
    , hotel(false)
    {}

std::string Property::get_color () {
    return color;
}

int Property::get_value() {
    return value;
}
int Property::get_mortgage_value() {
    return value/2;
}

void Property::show_details() {
    std::cout<<"e\n";
    std::cout<<"\n"<<name<<"\n";
	if (mortgaged){
		std::cout<<"MORTGAGED\n";
	}
}

int Property::count(std::vector<Space*>& spaces) {
    int c=0;
    for (int x=0; x<spaces.size(); x++){
        Property* p = dynamic_cast<Property*>(spaces[x]);
		if (p->owner==owner && p->color==color){
			c++;
		}
    }
    return c;
}

int Property::rent(std::vector<Space*>& spaces, int dice_rolled) {
    return 0;
}

void Property::action(Player& player, std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards) {
    std::string input=" ";
	while(input!="y" && input!="n" && input!="rent"){
		if (owner == "no one"){
			std::cout<<Property::get_name()<<" is not owned. Would you like to buy it for $"<<Property::get_value()<<"?(y/n)\n";
			std::cin>>input;
            if (input=="y"){
                owner=player.get_name();
                player.cash-=Property::get_value();
                player.add_property();
            }
		}
		else if (owner == player.get_name()){
			std::cout<<"You own "<<name<<".\n";
		}
		else if (mortgaged) {
			std::cout<<name<<" is mortgaged.\n";
		}
		else {
			int rent = Property::rent(spaces,dice_rolled);
			std::cout<<Property::get_name()<<" is owned by "<<owner<<". Rent is $"<<rent<<".\n";
			player.cash-=rent;
            for (int x = 0; x<players.size(); x++){
                if (players[x].get_name()==name){
                    players[x].cash+=rent;
                    break;
                }
            }
            std::cout<<"Rent paid to "<<owner<<"\n";
		}
	}
}
