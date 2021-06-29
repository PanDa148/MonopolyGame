#pragma once

#include <string>
#include <iostream>

class Space;
class Player;
class Card{
	protected:
	std::string text;
	public:
	Card();
	Card(std::string new_text);
	//virtual void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};
/*
class Collect : public Card{
	int amount;
	public:
	Collect (std::string new_text, int new_amount);
	void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};


class Pay : public Card{
    int amount;
    public:
    Pay (std::string new_text, int new_amount);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Go_to_jail : public Card{
    public:
    Go_to_jail (std::string new_text);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Collect_from_each_player : public Card{
    int amount;
    public:
    Collect_from_each_player(std::string new_text,int new_amount);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Get_out_of_jail_free  : public Card{
  public:
    Get_out_of_jail_free (std::string new_text) ;
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Pay_for_each_residence : public Card {
    int house_amount;
    int hotel_amount;
    public:
    Pay_for_each_residence (std::string new_text,int new_house_amount,int new_hotel_amount);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
} ;

class Jury_Duty : public Card{
    public:
    Jury_Duty(std::string new_text);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Advance_to : public Card{
    std::string space_color;
    int space_pos;
    public:
    Advance_to(std::string new_text, int new_space_pos);
    Advance_to(std::string new_text,std::string new_space_color);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};

class Pay_each_player: public Card{
    int amount;
    public:
    Pay_each_player(std::string new_text,int new_amount);
    void function(Player& player, std::vector<Space*>& spaces, std::vector<Player>& players);
};*/
