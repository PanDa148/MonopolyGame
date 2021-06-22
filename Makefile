all: clean monopoly_game

monopoly_game: main.o Monopoly.o Dice.o Player.o Space.o  Card.o Property.o Land.o Service_Provider.o Airport.o
	g++ -std=c++0x main.o Monopoly.o Dice.o Player.o Space.o Card.o Property.o Land.o Service_Provider.o Airport.o -o monopoly_game

main.o: main.cpp
	 g++ -c -std=c++0x main.cpp

Monopoly.o: Monopoly.cpp
	g++ -c -std=c++0x Monopoly.cpp

Dice.o: Dice.cpp
	g++ -c -std=c++0x Dice.cpp

Player.o: Player.cpp
	g++ -c -std=c++0x Player.cpp

Space.o: Space.cpp
	g++ -c -std=c++0x Space.cpp

Card.o: Card.cpp
	g++ -c -std=c++0x Card.cpp

Property.o: Property.cpp
	g++ -c -std=c++0x Property.cpp

Land.o: Land.cpp
	g++ -c -std=c++0x Land.cpp

Service_Provider.o: Service_Provider.cpp
	g++ -c -std=c++0x Service_Provider.cpp

Airport.o: Airport.cpp
	g++ -c -std=c++0x Airport.cpp

clean:
	rm -rf *o monopoly_game
