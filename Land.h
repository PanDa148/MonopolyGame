#pragma once

#include "Property.h"
class Player;
class Land : public Property
{
  int base_rent_val;
  int rent_1h;
  int rent_2h;
  int rent_3h;
  int rent_4h;
  int rent_hotel;

public:
    Land ();
    Land (std::string new_name,std::string new_color, int new_value, int new_base_rent_val, int new_rent_1h, int new_rent_2h, int new_rent_3h, int new_rent_4h, int new_rent_hotel);
  
  int total_val();
  void show_details();
  int get_house_val ();
  int get_hotel_val ();
  int rent(std::vector<Space*>& spaces, int dice_rolled);
  //int determine_rent (std::vector <std::shared_ptr<Property>>properties, int dice_rolled);
  //bool is_sellable (std::vector <std::shared_ptr<Property>>properties);
};
