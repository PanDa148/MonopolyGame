#include "GameBoard.h"
#include "GO.h"
#include "Go_To_Jail.h"
#include "Land.h"
#include "Airport.h"
#include "Service_Provider.h"
#include "Community_Chest.h"
#include "Chance.h"
#include "Jail.h"
#include "Interest_on_credit_card_debt.h"
#include "Income_Tax.h"
#include "Free_Parking.h"

GameBoard::GameBoard(){
    spaces[0] = new GO();
    spaces[1] = new Land("Jacobs Field","purple",600,20,100,300,900,1600,2500);
    spaces[2] = new Community_Chest();
    spaces[3] = new Land("Texas Stadium","purple",600,40,200,600,1800,3200,4500);
    spaces[4] = new Income_Tax();
    spaces[5] = new Airport("ORD");
    spaces[6] = new Land("Grand Ole Opry","light blue",1000,60,300,900,2700,4000,5500);
    spaces[7] = new Chance();
    spaces[8] = new Land("Gateway Arch","light blue",1000,60,300,900,2700,4000,5500);
    spaces[9] = new Land("Mall of America","light blue",1200,80,400,1000,3000,4500,6000);
    spaces[10] = new Jail();
    spaces[11] = new Land("Centennial Olympic Park","pink",1400,100,500,1500,4500,6250,7500);
    spaces[12] = new Service_Provider("Cell Phone");
    spaces[13] = new Land("Red Rocks Amphitheatre","pink",1400,100,500,1500,4500,6250,7500);
    spaces[14] = new Land("Liberty Bell","pink",1600,120,600,1800,5000,7000,9000);
    spaces[15] = new Airport("LAX");
    spaces[16] = new Land("South Beach","orange",1800,140,700,2000,5500,7500,9500);
    spaces[17] = new Community_Chest();
    spaces[18] = new Land("Johnson Space Center","orange",1800,140,700,2000,5500,7500,9500);
    spaces[19] = new Land("Pioneer Square","orange",2000,160,800,2200,6000,8000,10000);
    spaces[20] = new Free_Parking();
    spaces[21] = new Land("CamelBack Mtn.","red",2200,180,900,2500,7000,8750,10500);
    spaces[22] = new Chance();
    spaces[23] = new Land("Waikiki Beach","red",2200,180,900,2500,7000,8750,10500);
    spaces[24] = new Land("Disney World","red",2400,200,1000,3000,7500,9250,11000);
    spaces[25] = new Airport("JFK");
    spaces[26] = new Land("French Quarter","yellow",2600,220,1100,3300,8000,9750,11500);
    spaces[27] = new Land("Hollywood","yellow",2600,220,1100,3300,8000,9750,11500);
    spaces[28] = new Service_Provider("Internet");
    spaces[29] = new Land("Golden Gate Bridge","yellow",2800,240,1200,3600,8500,10250,12000);
    spaces[30] = new Go_To_Jail();
    spaces[31] = new Land("Las Vegas Blvd.","green",3000,260,1300,3900,9000,11000,12750);
    spaces[32] = new Land("Wrigley Field","green",3000,260,1300,3900,9000,11000,12750);
    spaces[33] = new Community_Chest();
    spaces[34] = new Land("White House","green",3200,280,1500,4500,10000,12000,14000);
    spaces[35] = new Airport("ATL");
    spaces[36] = new Chance();
    spaces[37] = new Land("Fenway Park","blue",3500,350,1750,5000,11000,13000,15000);
    spaces[38] = new Interest_on_credit_card_debt();
    spaces[39] = new Land("Times Square","blue",4000,500,2000,6000,14000,17000,20000);
}

Space* GameBoard::operator[](int i) {
    return spaces[i];
}

int GameBoard::length() {
    return 40;
}

void GameBoard::roll() {
    dice.roll();
}

int GameBoard::getRoll() {
    return dice.get_roll();
}

bool GameBoard::isDoubles() {
    return dice.is_doubles();
}

GameBoard::~GameBoard() {
    for (int i=0; i<length(); i++) {
        delete spaces[i];
    }
}

/*void GameBoard::printSpacesCSV() {
	std::ofstream gameboard("Spaces1.csv");
	gameboard<<"name,value,owner,color,base_rent,rent1,rent2,rent3,rent4,rentH\n";
	for (int i=0; i<40; i++) {
		gameboard<<spaces[i]->CSVstring()<<"\n";
	}
}*/
