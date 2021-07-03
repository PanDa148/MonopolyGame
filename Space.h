#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameBoard.h"

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
  virtual int determine_rent(GameBoard& gb);
};

class GO:public Space{
  public:
  GO();
  void action(Player& player,  GameBoard& gb, std::vector<Player>& players);
};

class Jail:public Space{
    public:
    Jail();
};

class Free_Parking:public Space{
    public:
    Free_Parking();
};

class Go_To_Jail:public Space{
    public:
    Go_To_Jail();
    void action(Player& player, GameBoard& gb, std::vector<Player>& players);
};

class Income_Tax:public Space{
    public:
    Income_Tax();
    void action(Player& player, GameBoard& gb,std::vector<Player>& players);
};

class Interest_on_credit_card_debt:public Space{
    public:
    Interest_on_credit_card_debt();
    void action(Player& player, GameBoard& gb,std::vector<Player>& players);
};

class Card_Space : public Space {
    public:
    Card_Space(std::string type);
};

class Community_Chest : public Card_Space{
    public:
    Community_Chest();
};

class Chance : public Card_Space{
    public:
    Chance();
};
