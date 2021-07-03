#pragma once

#include <vector>
#include "Space.h"
class Player;
class Property : public Space
{
protected:
  int value;
  std::string color;

public:
  bool mortgaged;
  std::string owner;
  int num_houses;
  bool hotel;
  Property ();
  Property (std::string new_name, int new_mortgage_value, std::string new_color);
  int get_value ();
  std::string get_color ();
  int get_mortgage_value ();
  virtual void show_details();
  virtual int count(std::vector<Space*>& spaces);
  virtual int rent(std::vector<Space*>& spaces, int dice_rolled);
  void action(Player& player, std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};
