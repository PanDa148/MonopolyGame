#pragma once
#include "Property.h"
class Player;

class Airport : public Property
{
public:
  Airport ();
  Airport (std::string new_name, int new_position);
  std::string get_color ();
  int get_value ();
  int get_mortgage_value ();
  int get_house_val ();
  int get_hotel_val ();
  int get_num_houses ();
  int get_num_hotels ();
  void action(Player& player, std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
  int determine_rent (std::vector<Space*>& spaces_ref);
  void show_details();
};

