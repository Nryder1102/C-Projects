//Morgan Precanico
//Monopoly Final

#include <vector>
#include <iostream>
#include <iomanip>

#include "Board.h"
#include "Entity.h"

#include "MWP.hpp"

using namespace std;

void setTurnOrder(vector<Entity*>& list);

int main() {

	Entity banker;

	srand(static_cast<unsigned int>(time(0)));
	
	//Make the board

	Board board;

	//How many players in the game
	int playerCount{0};
	//How many bots in the game
	int botCount{0};

	//Vector of all players/bots
	vector<Entity*> players;


	bool startLoop = true;
	cout << "Welcome to Monopoly!\nHow many players would you like to play with (1-6)?\n> ";
	
	while (startLoop) {
		cin >> playerCount;
		if (playerCount >= 1 && playerCount <= 6) {
			if (playerCount != 6) {
				cout << "How many bots would you like to play with (" << (playerCount == 1 ? "1-5" : "0-" + to_string(6 - playerCount)) << ")?\n";
				while (true) {
					cout << "> ";
					cin >> botCount;
					if (playerCount == 1 && botCount >= 1 && botCount <= 5) {
						startLoop = false;
						break;
					}
					else if (playerCount != 1 && botCount >= 0 && botCount <= 6 - playerCount) {
						startLoop = false;
						break;
					}
					else {
						cout << "That's not an option!" << endl;
					}
				}
				
			}
			else {
				startLoop = false;
			}
		}
		else {
			cout << "I'm sorry, that's not an option!\n> ";
		}
	}

	for (int i{ 0 }; i < playerCount; i++) {
		string name;
		while (true) {
			cout << "Player #" << i + 1 << ", please enter your name: ";
			cin >> name;
			if (name != "Banker") {
				break;
			}
			else {
				cout << "That name is not available!" << endl;
			}
		}
		Player* temp = new Player(name);
		players.push_back(temp);
	}

	for (int i{ 0 }; i < botCount; i++) {
		Entity* temp = new Entity("Bot" + to_string(i));
		players.push_back(temp);
	}


	mwp::cls();

	for (int i{ 0 }; i < players.size(); i++) {
		int roll1 = mwp::randBetween(1, 6);
		int roll2 = mwp::randBetween(1, 6);
		players[i]->startRoll = roll1 + roll2;
	}

	setTurnOrder(players);

	cout << "Turn Order is: " << endl;
	for (int i{ 0 }; i < players.size(); i++) {
		cout << to_string(i+1) + ") " << players[i]->getName() << ": " << to_string(players[i]->startRoll) << endl;
	}

	system("pause");

	mwp::cls();

	//Game Loop, continues until there's one player left
	while (players.size() > 1) {

		//Run a round of monopoly
		for (int i{ 0 }; i < players.size(); i++) {
			//Skip over players that are bankrupt
			if(!players[i]->isBankrupt){
				players[i]->takeTurn(board, players);
			}
		}

		//Run through at the end of every round, and remove players that are bankrupt from the vector
		for (int i{ 0 }; i < players.size(); i++) {
			if (players[i]->isBankrupt) {
				players.erase(remove_if(players.begin(), players.end(), [](Entity* it) {return it->isBankrupt;}), players.end());
			}
		}
		
	}

	
	mwp::cls();
	string winBanner;
	string winName = players[0]->getName() + " has won!";
	winBanner += " _____  _____  _____  _____  _____  _____  _____  _____  _____ \n";
	winBanner += "(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)\n";
	winBanner += "            _________ _        _        _______  _______  _    \n";
	winBanner += "   |\\     /|\\__   __/( (    /|( (    /|(  ____ \\(  ____ )( )   \n";
	winBanner += "   | )   ( |   ) (   |  \\  ( ||  \\  ( || (    \\/| (    )|| |   \n";
	winBanner += "   | | _ | |   | |   |   \\ | ||   \\ | || (__    | (____)|| |   \n";
	winBanner += "   | |( )| |   | |   | (\\ \\) || (\\ \\) ||  __)   |     __)| |   \n";
	winBanner += "   | || || |   | |   | | \\   || | \\   || (      | (\\ (   (_)   \n";
	winBanner += "   | () () |___) (___| )  \\  || )  \\  || (____/\\| ) \\ \\__ _    \n";
	winBanner += "   (_______)\\_______/|/    )_)|/    )_)(_______/|/   \\__/(_)   \n";
	winBanner += " _____  _____  _____  _____  _____  _____  _____  _____  _____ \n";
	winBanner += "(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)(_____)\n";
	cout << winBanner << endl;
	mwp::displayTextOnCenter(winName, 63);
	

}

void setTurnOrder(vector<Entity*>& list) {
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = i + 1; j < list.size(); j++) {
			if (list[i]->startRoll < list[j]->startRoll)
			{
				Entity* temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}