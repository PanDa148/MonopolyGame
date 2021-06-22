#pragma once

#include "Property.h"
class Player;
class Land : public Property
{
  int value;
    std::string color;
  int num_houses;
  int num_hotels;
  int base_rent_val;
  int rent_1h;
  int rent_2h;
  int rent_3h;
  int rent_4h;
  int rent_hotel;

public:
    Land ();
    Land (std::string new_name, int new_position, std::string new_color, int new_value, int new_base_rent_val, int new_rent_1h, int new_rent_2h, int new_rent_3h, int new_rent_4h, int new_rent_hotel);
    std::string get_color ();
  int get_value ();
  void set_value (int new_value);
  int get_mortgage_value ();
  int get_house_val ();
  int get_hotel_val ();
  int get_num_houses ();
  int get_num_hotels ();
  void add_houses (int num);
  void add_hotels (int num);
  void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
  int determine_rent(std::vector<Space*>& spaces_ref);
  void show_details();
  //int determine_rent (std::vector <std::shared_ptr<Property>>properties, int dice_rolled);
  //bool is_sellable (std::vector <std::shared_ptr<Property>>properties);
};
