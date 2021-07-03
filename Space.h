#pragma once
#include <iostream>
#include <string>
#include <vector>

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
  virtual void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
  virtual int determine_rent(std::vector<Space*>& spaces);
};

class GO:public Space{
  public:
  GO();
  void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
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
    void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};

class Income_Tax:public Space{
    public:
    Income_Tax();
    void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};

class Interest_on_credit_card_debt:public Space{
    public:
    Interest_on_credit_card_debt();
    void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};

class Community_Chest : public Space{
    public:
    Community_Chest();
    virtual void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};

class Chance : public Space{
    public:
    Chance();
    virtual void action(Player& player,  std::vector<Space*>& spaces, int dice_rolled, std::vector<Player>& players, std::vector<Card*>& community_chest_cards, std::vector<Card*>& chance_cards);
};
