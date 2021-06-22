#include "Property.h"
class Player;
class Service_Provider:public Property
{
public:
  Service_Provider ();
  Service_Provider (std::string new_name, int new_position);
  int get_value ();
  int get_mortgage_value ();
    std::string get_color ();
  int get_house_val ();
  int get_hotel_val ();
  int get_num_houses ();
  int get_num_hotels ();
  void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
  int determine_rent (std::vector<Space*>& spaces_ref, int dice_rolled);
  void show_details();
};
