#pragma once
#include "Space.h"
#include "Player.h"
#include "Card.h"
#include <vector>
#include <string>
class Monopoly{
    std::vector<Player> players;
    std::vector<Space*> spaces;
    std::vector<Card*> community_chest_cards;
    std::vector<Card*> chance_cards;
    public:
    Monopoly();
    void assign_players();
    void end_game();
    void assemble_game_board();
    void assemble_cards();
    int move_player(Player& player,int num);
    void players_turn(Player& player);
    void manage_player_turns();
    void take_mortgage(Player& player);
    bool is_bankrupt(Player& player);
    std::string player_who_went_bankrupt();
    void show_properties_owned(Player& player);
    int show_options(Player& player);
  //void buy_sell_property (Property* property, int direction);
 /* bool has_property (std::string property_name);
  Bool has_monopoly (std::string color);
  Void buy_sell_residences (Land& land, int num, std::string type);*/
};
