#pragma once
#include <string>
#include <vector>
#include <iostream>

class Player
{
  std::string name;
  int cash;
  int debt;
  bool in_jail;
  bool get_out_of_jail_card;
  int net_worth;
    std::vector <int>properties_owned;
    int position;
public:
    Player (std::string new_name);
    std::string get_name ();
    int get_position();
    void set_position(int new_position);
    void advance_position(int num_spaces);
  int get_cash ();
  void add_cash (int new_cash);
  int get_debt ();
  bool is_in_jail();
  void change_jail_status(bool new_status);
  void add_debt (int new_debt);
  void add_property (int num);
  bool has_get_out_of_jail_card();
  void set_get_out_of_jail_card(bool new_card);
  int get_net_worth();
  void set_net_worth(int new_net_worth);
  int get_num_properties_owned();
  int get_property_owned(int index);
};
