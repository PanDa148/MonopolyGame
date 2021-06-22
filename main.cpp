#include <string>
#include <vector>
#include <iostream>
#include "Monopoly.h"
#include <algorithm>

int main()
{
    //std::string new_name,std::string new_color,int new_value,int new_rent_val,int new_mortgage_value,int new_house_val,int new_hotel_val)
    //new_name, new_value, new_rent_val, new_mortgage_value
    /*Property* disney_world = new Land ("Disney World", "red", 2500, 300, 1750, 100, 200);
    Property* jfk = new Airport ("JFK", 1000,200,500);
    Property* internet = new Service_Provider ("Internet", 750, 100, 350);
    std::vector<Property*> properties {disney_world,jfk,internet};
    std::cout<<properties[0]->get_color();
    for (Property* p:properties) {
        delete p;
    }
    properties.clear();*/
    std::cout<<"Welcome to monopoly!\n";
    Monopoly monopoly;
    monopoly.assemble_game_board();
    monopoly.assign_players();
    monopoly.manage_player_turns();
    monopoly.end_game();
    /*monopoly.assign_players(players);
    monopoly.end_game(players);*/
}
