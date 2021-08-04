#pragma once
#include <iostream>
#include <string>
#include <vector>

class GameBoard;
class Player;
class Card;
class Space {
protected:
  std::string name;

public:
  Space ();
  Space (std::string new_name);
  bool mortgaged;
  std::string owner;
  int num_houses;
  bool hotel;
  virtual int get_value();
  virtual int get_house_val ();
  virtual int get_hotel_val ();
  virtual std::string get_color ();
  std::string get_name ();
  int get_position();
  virtual void show_details();
  virtual int get_mortgage_value ();
  virtual void action(Player& player,  GameBoard& gb,std::vector<Player>& players);
  virtual std::string CSVstring();
};
