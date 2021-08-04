#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Player.h"
#include "Space.h"
#include "Community_Chest.h"
#include "Chance.h"
Player::Player(std::string new_name):
    name(new_name),
    cash(15000),
    debt(0),
    in_jail(false),
    position(0),
    jailCard_c(NULL),
    jailCard_cc(NULL)
{}
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

int Player::calc_net_worth(GameBoard& gb) {
    int total = cash-debt;
    for (int x=0; x<properties_owned.size(); x++){
        Space* s = gb[properties_owned[x]];
		total+=s->get_value()+(s->num_houses)*(s->get_house_val())+(s->hotel)*(s->get_hotel_val());
	}
    net_worth=total;
    return total;
}

bool Player::has_get_out_of_jail_card() {
    return jailCard_c!=NULL || jailCard_cc!=NULL;
}

void Player::remove_jail_card() {
    if (jailCard_c!=NULL) {
        Chance::cd.returnCard(jailCard_c);
        jailCard_c = NULL;
    } else {
        Community_Chest::cd.returnCard(jailCard_cc);
        jailCard_cc = NULL;
    }
}

void Player::showJailCards() {
    if (jailCard_c!=NULL) {
        jailCard_c->print();
    }
    if (jailCard_cc!=NULL) {
        jailCard_cc->print();
    }
}

void Player::move(int roll) {
    int old_pos = position;
    if ((old_pos+roll)>39) {
	position=old_pos+roll-40;
	std::cout<<"You passed GO!\n";
	cash+=2000;
    }
    else {
        position+=roll;
    }
}
