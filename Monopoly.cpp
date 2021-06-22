#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Space.h"
#include "Monopoly.h"
#include "Land.h"
#include "Airport.h"
#include "Service_Provider.h"
#include "Card.h"
#include "Dice.h"
//Compilation command: g++ -c -std=c++0x Monopoly.cpp
Monopoly::Monopoly(){}

void Monopoly::assign_players() {
    int num_players=0;
    Player null_player(" ");
    players.push_back(null_player);
    std::vector<std::string> mascots {"Dog","Ship","Coffee","Laptop","Shoe","McDonald's Cup","Airplane","Cellphone"};
    while(num_players<1 || num_players>8){
        std::cout<<"How many players?\n";
        std::cin>>num_players;
    }
    int player_num=1;
    while (player_num<=num_players) {
        int choice;
        int input;
        std::cout<<"Which token does player "<<player_num<<" want to be?\n";
        for (int i=0; i<mascots.size(); i++) {
            std::cout<<i+1<<": "<<mascots[i]<<"\n";
        }
        std::cin>>input;
        choice = input-1;
        if (choice>=0 && choice<mascots.size()) {
            Player player(mascots[choice]);
            players.push_back(player);
            mascots.erase(mascots.begin()+choice);
            player_num++;
        }
        else {
            std::cout<<"Invalid input\n";
            std::cout<<"Try again\n";
        }
    }
}

void Monopoly::assemble_game_board() {
    Space* a = new GO(0);
    Space* b = new Land("Jacobs Field",1,"purple",600,20,100,300,900,1600,2500);
    Space* c = new Community_Chest(2);
    Space* d = new Land("Texas Stadium",3,"purple",600,40,200,600,1800,3200,4500);
    Space* e = new Income_Tax(4);
    Space* f = new Airport("ORD Airport",5);
    Space* g = new Land("Grand Ole Opry",6,"light blue",1000,60,300,900,2700,4000,5500);
    Space* h = new Chance(7);
    Space* i = new Land("Gateway Arch",8,"light blue",1000,60,300,900,2700,4000,5500);
    Space* j = new Land("Mall of America",9,"light blue",1200,80,400,1000,3000,4500,6000);
    Space* k = new Jail(10);
    Space* l = new Land("Centennial Olympic Park",11,"pink",1400,100,500,1500,4500,6250,7500);
    Space* m = new Service_Provider("Cell Phone Service Provider",12);
    Space* n = new Land("Red Rocks Amphitheatre",13,"pink",1400,100,500,1500,4500,6250,7500);
    Space* o = new Land("Liberty Bell",14,"pink",1600,120,600,1800,5000,7000,9000);
    Space* p = new Airport("LAX Airport",15);
    Space* q = new Land("South Beach",16,"orange",1800,140,700,2000,5500,7500,9500);
    Space* r = c;
    Space* s = new Land("Johnson Space Center",18,"orange",1800,140,700,2000,5500,7500,9500);
    Space* t = new Land("Pioneer Square",19,"orange",2000,160,800,2200,6000,8000,10000);
    Space* u = new Free_Parking(20);
    Space* v = new Land("CamelBack Mtn.",21,"red",2200,180,900,2500,7000,8750,10500);
    Space* w = h;
    Space* x = new Land("Waikiki Beach",23,"red",2200,180,900,2500,7000,8750,10500);
    Space* y = new Land("Disney World",24,"red",2400,200,1000,3000,7500,9250,11000);
    Space* z = new Airport("JFK Airport",25);
    Space* A = new Land("French Quarter",26,"yellow",2600,220,1100,3300,8000,9750,11500);
    Space* B = new Land("Hollywood",27,"yellow",2600,220,1100,3300,8000,9750,11500);
    Space* C = new Service_Provider("Internet Service Provider",28);
    Space* D = new Land("Golden Gate Bridge",29,"yellow",2800,240,1200,3600,8500,10250,12000);
    Space* E = new Go_To_Jail(30);
    Space* F = new Land("Las Vegas Blvd.",31,"green",3000,260,1300,3900,9000,11000,12750);
    Space* G = new Land("Wrigley Field",32,"green",3000,260,1300,3900,9000,11000,12750);
    Space* H = c;
    Space* I = new Land("White House",34,"green",3200,280,1500,4500,10000,12000,14000);
    Space* J = new Airport("ATL Airport",35);
    Space* K = h;
    Space* L = new Land("Fenway Park",37,"blue",3500,350,1750,5000,11000,13000,15000);
    Space* M = new Interest_on_credit_card_debt(38);
    Space* N = new Land("Times Square",39,"blue",4000,500,2000,6000,14000,17000,20000);
    spaces = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,A, B, C, D, E, F, G, H, I, J, K, L, M, N};
}

void Monopoly::assemble_cards(){
	Card* aa = new Get_out_of_jail_free("Receive a presidential pardon");
	Card* ab = new Collect_from_each_player("You file as a candidate for Mayor.", 500);
	Card* ac = new Advance_to("Advance to \"GO\"", 0);
	community_chest_cards = {aa, ab, ac};
	Card* ba = new Advance_to("Bad weather forces your flight to get rerouted through Chicago. Advance to ORD Airport.", 5);
	Card* bb = new Advance_to("Celebrate New Year's Eve in The Big Apple. Advance to Times Square.", 38);
	Card* bc = new Advance_to(" ", "air");
	chance_cards = {ba, bb, bc};
}

void Monopoly::end_game() {
     for (int x=1; x<players.size(); x++){ 
	Player& player = players[x];
        player.set_net_worth(player.get_cash()-player.get_debt());
	for (int x=0; x<spaces.size(); x++){
		if(spaces[x]->get_owner()==player.get_name()){
			player.set_net_worth(player.get_net_worth()+spaces[x]->get_value()+(spaces[x]->get_num_houses())*(spaces[x]->get_house_val())+(spaces[x]->get_num_hotels())*(spaces[x]->get_hotel_val()));
		}
	}
    }
    int highest_net_worth=0;
    for (int x=1; x<players.size();x++){
	Player& player=players[x];
	if (player.get_net_worth()>=highest_net_worth){
	    highest_net_worth=player.get_net_worth();
	}
    }
    std::vector<std::string> winners;
    for (int x=1; x<players.size(); x++){
	if (players[x].get_net_worth()==highest_net_worth){
	    winners.push_back(players[x].get_name());
	}
    }
    if (winners.size()==1){
	std::cout<<winners[0]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
    else if (winners.size()==2){
	std::cout<<winners[0]<<" and "<<winners[1]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
    else{
	for (int x=0; x<(winners.size()-1); x++) {
	    std::cout<<winners[x]<<", ";
	}
	std::cout<<"and "<<winners[winners.size()-1]<<" won with a net worth of $"<<highest_net_worth<<"!\n";
    }
    players.clear();
    for (int x = 0; x<=16; x++) {
	delete spaces[x];
    }
    for (int x = 18; x<=21; x++) {
	delete spaces[x];
    }
    for (int x = 23; x<=32; x++) {
	delete spaces[x];
    }
    for (int x = 34; x<=35; x++) {
	delete spaces[x];
    }
    for (int x = 37; x<=39; x++) {
	delete spaces[x];
    }
    spaces.clear();
    for (int x = 0; x<community_chest_cards.size(); x++) {
	delete community_chest_cards[x];
    }
    community_chest_cards.clear();
    for (int x = 0; x<chance_cards.size(); x++) {
	delete chance_cards[x];
    }
    chance_cards.clear();
}

void Monopoly::take_mortgage(Player& player) {
	std::string input;
	std::cout<<"Which property do you want to mortgage?\n";
	std::vector<int> properties_to_mortgage;
	for (int x = 0; x<spaces.size(); x++){
		if ((spaces[x]->get_owner() == player.get_name()) && !(spaces[x]->is_mortgaged())){
			properties_to_mortgage.push_back(x);
		}
	}
	for (int x=0; x<properties_to_mortgage.size(); x++){
		int i = properties_to_mortgage[x];
		std::cout<<x<<": "<<spaces[i]->get_name()<<" for $"<<spaces[i]->get_mortgage_value()<<"\n";
	}
	std::cin>>input;
	int choice = stoi(input);
	player.add_cash(spaces[properties_to_mortgage[choice]]->get_mortgage_value());
	player.add_debt(spaces[properties_to_mortgage[choice]]->get_mortgage_value());
	spaces[properties_to_mortgage[choice]]->set_mortgage(true);
}

void Monopoly::show_properties_owned(Player& player){
	int num_properties_owned = player.get_num_properties_owned();
	std::cout<<"Which property do you want to see?\n";
	int input;
	for (int x=0; x<num_properties_owned; x++){
		std::cout<<x<<": "<<spaces[player.get_property_owned(x)]->get_name()<<"\n";
	}
	std::cin>>input;
	Space& choice = *spaces[player.get_property_owned(input)];
	choice.show_details();
}
int Monopoly::show_options(Player& player) {
	int input;
	std::cout<<"What else do you want to do?\n";
	std::cout<<"0: Move on to the next player\n";
	std::cout<<"1: Show properties I own\n";
	std::cout<<"2: Buy/sell a house\n";
	std::cout<<"3: Buy/sell a hotel\n";
	std::cout<<"4: Mortgage one of my properties\n";
	std::cout<<"5: Pay a mortgage\n";
	std::cout<<"6: Sell property to the bank\n";
	std::cout<<"7: Trade property and/or with another player\n";
	std::cout<<"8: Leave game\n";
	std::cout<<"9: End game\n";
	std::cin>>input;
	return input;
}
int Monopoly::move_player(Player& player,int num){
    int old_pos = player.get_position();
    if ((old_pos+num)>39) {
	player.set_position(old_pos+num-40);
	std::cout<<"You passed GO!\n";
	player.add_cash(2000);
    }
    else {
        player.advance_position(num);
    }
    int new_pos = player.get_position();
    std::cout<<"You landed on "<<spaces[new_pos]->get_name()<<"\n";
    return new_pos;
}
void Monopoly::players_turn (Player& player) {
	std::cout<<player.get_name()<<"'s turn!\n";
	std::string input;
	bool missed_turn=false;
	if (player.is_in_jail()){
    		int choice=0;
    		std::cout<<"You are in jail. What do you want to do?\n";
    		while((choice!=1 && choice !=2 && choice!=3) || (choice==3 && !player.has_get_out_of_jail_card()) ){
			std::cout<<"1: Pay $500\n";
			std::cout<<"2: Miss turn\n";
			if (player.has_get_out_of_jail_card()){
				std::cout<<"3: Use get out of jail card\n";
			}
			std::cin>>input;
			choice = stoi(input);
			switch(choice){
				case 1:
					player.add_cash(-500);
					player.change_jail_status(false);
					std::cout<<"You paid $500. You now have $"<<player.get_cash()<<".\n";
					break;
				case 2:
					std::cout<<"You missed your turn.\n";
					missed_turn=true;
					break;
				case 3:
					if (player.has_get_out_of_jail_card()){
						std::cout<<"You used your get out of jail card.\n";
						player.change_jail_status(false);
					}
					else{
						std::cout<<"Invalid input\n";
					}
					break;
				default:
					std::cout<<"Invalid input\n";
					break;
			}
    		}
	}
	if (!player.is_in_jail()){
    	Dice dice;
    	int roll;
    	int doubles_count=0;
    	bool first_roll = true;
    	while(first_roll || (doubles_count>0 && !(player.is_in_jail()))) {
		if (doubles_count>0) {
	    		std::cout<<player.get_name()<<" can roll again!\n";
		}
               	dice.roll();
        	roll = dice.get_roll();
        	if (dice.is_doubles()) {
    	    		std::cout<<"Doubles!\n";
	    		doubles_count++;
        	}
        	else {
	    		doubles_count=0;
        	}
        	std::cout<<"You rolled a "<<roll<<"!\n";
        	if (doubles_count>2) {
	    		std::cout<<"You rolled doubles 3 times in a row!\n";
	    		std::cout<<"Go to jail!\n";
	    		player.change_jail_status(true);
	    		player.set_position(10);
        	}
		else {
	    		int new_pos = Monopoly::move_player(player,roll);
	    		std::string owner_name = spaces[new_pos]->get_owner();
	    		std::vector<Space*>& spaces_ref = spaces;
			std::vector<Player>& players_ref = players;
			std::vector<Card*>& community_chest_cards_ref = community_chest_cards;
			std::vector<Card*>& chance_cards_ref = chance_cards;

   	    		(spaces[new_pos])->action(player, spaces_ref, roll, players_ref, community_chest_cards_ref, chance_cards_ref);
    			std::cout<<"You have $"<<player.get_cash()<<".\n";
    			while (player.get_cash()<0){
				std::cout<<"You need to take a mortgage to cover the debt\n";
				Monopoly::take_mortgage(player);
   			}
		}
		first_roll = false;
    	}}
	if (missed_turn){
		player.change_jail_status(false);
	}
}

bool Monopoly::is_bankrupt(Player& player){
	int net_worth=player.get_cash()-player.get_debt();
	for (int x=0; x<spaces.size(); x++){
		if(spaces[x]->get_owner()==player.get_name()){
			net_worth=net_worth+spaces[x]->get_value()+(spaces[x]->get_num_houses())*(spaces[x]->get_house_val())+(spaces[x]->get_num_hotels())*(spaces[x]->get_hotel_val());
		}
	}
	return net_worth<0;
}

std::string Monopoly::player_who_went_bankrupt(){
    for (int i=1; i<players.size(); i++){
	Player& player=players[i];
	if (Monopoly::is_bankrupt(player)){
		return player.get_name();
	}
    }
    return " ";
}

void Monopoly::manage_player_turns(){
    bool game = true;
    int input=10;
    while (game) {
	for (int i=1; i<players.size(); i++) {
	    Monopoly::players_turn(players[i]);
	    std::string loser=Monopoly::player_who_went_bankrupt();
	    if (loser!=" "){
		game=false;
		std::cout<<loser<<" went bankrupt!\n";
		break;
	    }
	    if (!players[i].is_in_jail()) {
	    while (input!=0 && input!=9) {
		input=Monopoly::show_options(players[i]);
		switch(input){
			case 0:
				break;
			case 1:
				for (int x=0; x<spaces.size(); x++) {
					if (players[i].get_name()==spaces[x]->get_owner()){
						spaces[x]->show_details();
					}
				}
				break;
			case 2:
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 3: 
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 4:
				Monopoly::take_mortgage(players[i]);
				break;
			case 5:
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 6:
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 7:
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 8:
				std::cout<<"Sorry this hasn't been set up yet\n";
				break;
			case 9:
				game=false;
				break;
			default:
				std::cout<<"Invalid input\n";
				break;
		}
	    }
	    input=10;}
        }
    }
}
/*
bool Monopoly::has_property(std::string property_name) {
    bool found = false;
    for (Property* p:properties_owned) {
        if (p->get_name()==property_name) {
            found = true;
            break;
        }
    }
    return found;
}


void Monopoly::buy_sell_property(Property* property, int direction) {
    int price = property->get_value();
    std::string pname = property->get_name();
    if (direction>0) {
        properties_owned.push_back(p);
        std::cout<<"You bought "<<pname<<" for $"<<price<<".\n";
        Monopoly::add_cash(-direction*price);
        ptr->set_owner(name);
    }
    else {
        if (property->is_sellable(properties_owned)) {
            int index = Monopoly::find_property(pname);
            properties_owned.erase(begin(properties_owned)+index);
            std::cout<<"You sold "<<pname<<" for $"<<price<<".\n";
            Monopoly::add_cash(-direction*price);
            (&property)->set_owner("no one");
        }
        else {
           std::cout<<pname<<" is not sellable.\n";
        }
    }
}

void Monopoly::buy_sell_residences(Land& land, int num, std::string type) {
    std::string action;
    int price;
    if ((num>0 && Player::has_monopoly(land.get_color()) || num<0)) {
        if (num>0) {
        action="bought";
        }
        else {
            action = "sold";
        }
        if (type=="house") {
            price = num*land.get_house_val();
            land.add_houses(num);
        }
        else {
            price = land.get_hotel_val()+4*land.get_house_val();
            land.add_hotels(num);
        }
        Player::add_cash(-price);
        std::cout<<"You "<<action<<" "<<abs(num)<<" "<<type<<"(s) at "<<land.get_name()<<".\n";
    }
    else {
        std::cout<<"You can't buy houses here because you don't have a monopoly yet.\n";
    }
}*/
/*void rent_payment(Property property, Player payer, Player collecter) {
    int rent_val = property.determine_rent();
    payer.add_cash(-rent_val);
    collecter.add_cash(rent_val);
    std::cout<<"$"<<rent_val<<" transferred from "<<payer.get_name()<<" to "<<collecter.get_name();
}
void trade_property(Property property, Player seller, Player buyer) {
    seller.buy_sell_property(property, -1);
    buyer.buy_sell_property(property, 1);
}
void trade_property(Property property, Player seller, Player buyer, int price) {
    int temp = property.get_value();
    property.set_value(price);
    seller.buy_sell_property(property,-1);
    buyer.buy_sell_property(property,1);
    property.set_value(temp);
}*/
