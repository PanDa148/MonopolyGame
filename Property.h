#pragma once
#include <vector>
#include "GameBoard.h"
#include "Space.h"
class Player;
class Property : public Space
{
protected:
  int value;
  std::string color;

public:
  Property ();
  Property (std::string new_name, int new_value, std::string new_color);
  int get_value ();
  std::string get_color ();
  int get_mortgage_value ();
  virtual void show_details();
  int count(GameBoard& gb);
  virtual int rent(GameBoard& gb);
  void action(Player& player, GameBoard& gb, std::vector<Player>& players);
  //virtual std::string CSVstring();
};
