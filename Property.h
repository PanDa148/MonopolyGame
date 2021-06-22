#pragma once

#include <vector>
#include "Space.h"
class Player;
class Property : public Space
{
protected:
  bool mortgaged;
  std::string owner_name;

public:
  Property ();
  Property (std::string new_name, int new_positon);
  void set_owner(std::string new_owner);
  std::string get_owner();
  virtual std::string get_color ();
  virtual int get_value ();
  virtual int get_mortgage_value ();
  virtual int get_num_houses ();
  virtual int get_num_hotels ();
  virtual int get_house_val ();
  virtual int get_hotel_val ();
  bool is_mortgaged ();
  void set_mortgage(bool new_mortgage);
  //virtual int determine_rent (std::vector <std::shared_ptr<Property>>properties,
//			      int dice_rolled, std::vector<Player>& players_ref);
  //virtual bool is_sellable (std::vector <std::shared_ptr<Property>>properties);
};
