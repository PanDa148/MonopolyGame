#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Player.h"
Player::Player(std::string new_name):
    name(new_name),
    cash(15000),
    debt(0),
    in_jail(false),
    position(0),
    get_out_of_jail_card(false),
    net_worth(0)
    {}
//basic functions
std::string Player::get_name(){
    return name;
}

int Player::get_position() {
    return position;
}
void Player::set_position(int new_position) {
    position = new_position;
}

void Player::advance_position(int num_spaces) {
    position = position + num_spaces;
}

int Player::get_cash(){
    return cash;
}
void Player::add_cash(int new_cash){
    cash = cash + new_cash;
}
int Player::get_debt(){
    return debt;
}
void Player::add_debt(int new_debt) {
    debt = debt+new_debt;
}

bool Player::is_in_jail(){
    return in_jail;
}

void Player::change_jail_status(bool new_status) {
    in_jail = new_status;
}

bool Player::has_get_out_of_jail_card(){
	return get_out_of_jail_card;
}

void Player::set_get_out_of_jail_card(bool new_card){
	get_out_of_jail_card=new_card;
}

void Player::add_property(int num){
	properties_owned.push_back(num);
}
int Player::get_net_worth(){
	return net_worth;
}
void Player::set_net_worth(int new_net_worth){
	net_worth=new_net_worth;
}

int Player::get_num_properties_owned(){
	return properties_owned.size();
}
int Player::get_property_owned(int index){
	return properties_owned[index];
}
