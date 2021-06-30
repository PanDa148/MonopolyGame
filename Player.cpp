#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Player.h"
#include "Property.h"
#include "Land.h"
Player::Player(std::string new_name):
    name(new_name),
    cash(15000),
    debt(0),
    in_jail(false),
    position(0),
    get_out_of_jail_card(false)
    {}
//basic functions
std::string Player::get_name(){
    return name;
}

void Player::add_property(){
	properties_owned.push_back(position);
}

int Player::num_properties_owned(){
	return properties_owned.size();
}
int Player::get_property_owned(int index){
	return properties_owned[index];
}

int Player::calc_net_worth(std::vector<Space*>& spaces) {
    int total = cash-debt;
    for (int x=0; x<properties_owned.size(); x++){
        Space* p = spaces[properties_owned[x]];
		total+=p->get_value();//(p->get_num_houses())*(p->get_house_val())+(p->get_num_hotels())*(p->get_hotel_val());
        
	}
    net_worth=total;
    return total;
}
