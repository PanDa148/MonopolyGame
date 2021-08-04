all: clean monopolygame

monopolygame: Airport Card CardDeck Card_Space Chance Collect Community_Chest Dice Free_Parking GameBoard GetOutOfJail GO Go_To_Jail Income_Tax Interest_on_credit_card_debt Jail Land main Monopoly Pay Player Property Service_Provider Space 
	g++ -std=c++17 Airport.o Card.o CardDeck.o Card_Space.o Chance.o Collect.o Community_Chest.o Dice.o Free_Parking.o GameBoard.o GetOutOfJail.o GO.o Go_To_Jail.o Income_Tax.o Interest_on_credit_card_debt.o Jail.o Land.o main.o Monopoly.o Pay.o Player.o Property.o Service_Provider.o Space.o -o monopolygame

Airport: Airport.cpp
	g++ -c -std=c++17 Airport.cpp

Card: Card.cpp
	g++ -c -std=c++17 Card.cpp

CardDeck: CardDeck.cpp
	g++ -c -std=c++17 CardDeck.cpp

Card_Space: Card_Space.cpp
	g++ -c -std=c++17 Card_Space.cpp

Chance: Chance.cpp
	g++ -c -std=c++17 Chance.cpp

Collect: Collect.cpp
	g++ -c -std=c++17 Collect.cpp

Community_Chest: Community_Chest.cpp
	g++ -c -std=c++17 Community_Chest.cpp

Dice: Dice.cpp
	g++ -c -std=c++17 Dice.cpp

Free_Parking: Free_Parking.cpp
	g++ -c -std=c++17 Free_Parking.cpp

GameBoard: GameBoard.cpp
	g++ -c -std=c++17 GameBoard.cpp

GetOutOfJail: GetOutOfJail.cpp
	g++ -c -std=c++17 GetOutOfJail.cpp

GO: GO.cpp
	g++ -c -std=c++17 GO.cpp

Go_To_Jail: Go_To_Jail.cpp
	g++ -c -std=c++17 Go_To_Jail.cpp

Income_Tax: Income_Tax.cpp
	g++ -c -std=c++17 Income_Tax.cpp

Interest_on_credit_card_debt: Interest_on_credit_card_debt.cpp
	g++ -c -std=c++17 Interest_on_credit_card_debt.cpp

Jail: Jail.cpp
	g++ -c -std=c++17 Jail.cpp

Land: Land.cpp
	g++ -c -std=c++17 Land.cpp

main: main.cpp
	g++ -c -std=c++17 main.cpp

Monopoly: Monopoly.cpp
	g++ -c -std=c++17 Monopoly.cpp

Pay: Pay.cpp
	g++ -c -std=c++17 Pay.cpp

Player: Player.cpp
	g++ -c -std=c++17 Player.cpp

Property: Property.cpp
	g++ -c -std=c++17 Property.cpp

Service_Provider: Service_Provider.cpp
	g++ -c -std=c++17 Service_Provider.cpp

Space: Space.cpp
	g++ -c -std=c++17 Space.cpp

clean:
	rm -rf *o monopolygame
