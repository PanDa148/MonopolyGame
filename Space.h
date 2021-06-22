#pragma once
#include <iostream>
#include <string>
#include <vector>

class Player;
class Card;
class Space
{
protected:
  std::string name;
  int position;

public:
  Space ();
  Space (std::string new_name, int new_positon);
  std::string get_name ();
  int get_position();
  virtual void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
  virtual std::string get_owner();
  virtual std::string get_color();
  virtual bool is_mortgaged();
  virtual int get_mortgage_value();
  virtual void set_mortgage(bool new_mortgage);
  virtual int get_num_houses();
  virtual int get_num_hotels();
  virtual int get_house_val ();
  virtual int get_hotel_val ();
  virtual int get_value();
  virtual void show_details();
  virtual int determine_rent(std::vector<Space*>& spaces_ref);
};

class GO:public Space{
  public:
  GO();
  GO(int position);
  void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

class Jail:public Space{
    public:
    Jail();
    Jail(int position);
};

class Free_Parking:public Space{
    public:
    Free_Parking();
    Free_Parking(int position);
};

class Go_To_Jail:public Space{
    public:
    Go_To_Jail();
    Go_To_Jail(int position);
    void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

class Income_Tax:public Space{
    public:
    Income_Tax();
    Income_Tax(int position);
    void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

class Interest_on_credit_card_debt:public Space{
    public:
    Interest_on_credit_card_debt();
    Interest_on_credit_card_debt(int position);
    void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

class Community_Chest : public Space{
    public:
    Community_Chest();
    Community_Chest(int new_position);
    virtual void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

class Chance : public Space{
    public:
    Chance();
    Chance(int new_position);
    virtual void action(Player& player,  std::vector<Space*>& spaces_ref, int dice_rolled, std::vector<Player>& players_ref, std::vector<Card*>& community_chest_cards_ref, std::vector<Card*>& chance_cards_ref);
};

