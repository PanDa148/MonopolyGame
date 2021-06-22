#include <string>
#include <vector>
#include <iostream>
#include "Property.h"
#include "Player.h"

Property::Property(){}
Property::Property(std::string new_name, int new_position)
    : Space(new_name, new_position)
    , mortgaged(false)
    , owner_name("no one")
    {}
    
void Property::set_owner(std::string new_owner) {
    owner_name = new_owner;
}

int Property::get_value() {
    return 0;
}
int Property::get_mortgage_value() {
    return 0;
}

bool Property::is_mortgaged() {
    return mortgaged;
}

std::string Property::get_color() {
    return "white";
}

int Property::get_num_houses() {
    return 0;
}

int Property::get_num_hotels() {
    return 0;
}

int Property::get_house_val() {
    return 0;
}

int Property::get_hotel_val() {
    return 0;
}

std::string Property::get_owner(){
	return owner_name;
}

void Property::set_mortgage(bool new_mortgage){
	mortgaged=new_mortgage;
}
/*int Property::determine_rent(std::vector<Property*> properties, int dice_rolled, std::vector<Player>& players_ref) {
    return 0;
}*/

/*bool Property::is_sellable(std::vector<Property*> properties) {
    if (mortgaged) {
        std::cout<<name<<" is mortgaged.\n";
    }
    return !mortgaged;
}*/
