#pragma once
#include <string>
#include <vector>
#include <iostream>
class Space;
class Property;
class Land;
class Player
{
private:
  std::string name;
  std::vector <int>properties_owned;
public:
  int cash;
  int debt;
  bool in_jail;
  bool get_out_of_jail_card;
  int position;
  int net_worth;
  Player (std::string new_name);
  std::string get_name ();
  int num_properties_owned();
  int get_property_owned(int index);
  void add_property();
  int calc_net_worth(std::vector<Space*>& spaces);
};
