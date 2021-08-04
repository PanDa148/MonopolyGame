#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "GameBoard.h"
class Community_Chest;
class Chance;
class Space;
class Player
{
private:
  std::string name;
  std::vector <int>properties_owned;
public:
  int cash;
  int debt;
  bool in_jail;
  int position;
  int net_worth;
  Card* jailCard_c;
  Card* jailCard_cc;
  Player (std::string new_name);
  std::string get_name ();
  int num_properties_owned();
  int get_property_owned(int index);
  void add_property();
  int calc_net_worth(GameBoard& gb);
  bool has_get_out_of_jail_card();
  void add_jail_card(Card* c);
  void remove_jail_card();
  void showJailCards();
  void move(int roll);
};