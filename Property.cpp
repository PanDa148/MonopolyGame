#include <string>
#include <vector>
#include <iostream>
#include "Property.h"
#include "Player.h"

Property::Property(){}
Property::Property(std::string new_name, int new_value, std::string new_color)
    : Space(new_name)
    , value(new_value)
    , color(new_color)
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
    std::cout<<"\n"<<name<<"\n";
	if (mortgaged){
		std::cout<<"MORTGAGED\n";
	}
}

int Property::count(GameBoard& gb) {
    int c=0;
    for (int x=0; x<40; x++){
        Space* p = gb[x];
		if (p->owner==owner && p->get_color()==color){
			c++;
		}
    }
    return c;
}

int Property::rent(GameBoard& gb) {
    return 0;
}

void Property::action(Player& player, GameBoard& gb, std::vector<Player>& players) {
		if (owner == ""){
			std::string input=" ";
            while (input!="y" && input !="n"){
                std::cout<<get_name()<<" is not owned. Would you like to buy it for $"<<Property::get_value()<<"?(y/n)\n";
                std::cin>>input;
            }
                owner=player.get_name();
                player.cash-=get_value();
                player.add_property();
		}
		else if (owner == player.get_name()){
			std::cout<<"You own "<<name<<".\n";
		}
		else if (mortgaged) {
			std::cout<<name<<" is mortgaged.\n";
		}
		else {
			int r = rent(gb);
			std::cout<<get_name()<<" is owned by "<<owner<<". Rent is $"<<r<<".\n";
			player.cash-=r;
            for (int x = 0; x<players.size(); x++){
                if (players[x].get_name()==name){
                    players[x].cash+=r;
                    break;
                }
            }
            std::cout<<"Rent paid to "<<owner<<"\n";
		}
}
