#pragma once
#include "Space.h"
#include "Player.h"
#include "Card.h"
#include "Land.h"
#include "Airport.h"
#include "Service_Provider.h"
#include <vector>
#include <string>

class Monopoly{
    private:
    std::vector<Player> players;
    std::vector<Space*> spaces;
    std::vector<Card*> community_chest_cards;
    std::vector<Card*> chance_cards;

    void assemble_cards();
    int move_player(Player& player,int num);
    void players_turn(Player& player);
    void take_mortgage(Player& player);
    bool is_bankrupt(Player& player);
    std::string player_who_went_bankrupt();
    void show_properties_owned(Player& player);
    int show_options(Player& player);

    public:
    Monopoly();
    ~Monopoly();
    void assign_players();
    void assemble_game_board();
    void end_game();
    void manage_player_turns();
};
