#pragma once
#include "Player.h"
#include "Property.h"
#include "GameBoard.h"
#include <vector>
#include <string>

class Monopoly{
    private:
    std::vector<Player> players;
    GameBoard gb;

    void players_turn(Player& player);
    void take_mortgage(Player& player);
    bool is_bankrupt(Player& player);
    std::string player_who_went_bankrupt();
    void show_stats(Player& player);
    int show_options(Player& player);
    void assign_players();
    void end_game();
    void mainGameLoop();
    bool endTurn(Player& player);

    public:
    Monopoly();
    ~Monopoly();
    void play();
};