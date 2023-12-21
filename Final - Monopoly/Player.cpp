#include "Entity.h"
#include "Monopoly.h"
#include "MWP.hpp"

using namespace std;

Player::Player(string n) {
	name = n;
	isPlayer = true;
}

void Player::takeTurn(Board& board, vector<Entity*>& players) {
	bool turn = true;
	int turnNum{0};
	if (!isBankrupt) {
		cout << name << "'s turn begins." << endl;
		mwp::wait(1.5);
		//If you aren't bankrupt and not in jail, take your turn
		if (!inJail) {
			while (turn) {
				int choice{0};
				cout << "What would you like to do?\n1) Roll\n2) Check Info\n3) Manage Your Properties";
				//While turnNum doesn't equal three, and you still have a valid turn, ask what you want to do
				if (turnNum != 3) {
					cout << "\n> ";
					cin >> choice;
					cout << endl;
					//If cin didn't fail, proceed to the switch
					if (!cin.fail()) {
						switch (choice) {
							//Roll dice and move
						case 1: {

							int roll1 = Monopoly::rollDice();
							int roll2 = Monopoly::rollDice();

							cout << "Roll 1: " << roll1 << endl;
							mwp::wait(0.5);
							cout << "Roll 2: " << roll2 << endl;
							mwp::wait(0.5);

							if (roll1 == roll2 && turnNum != 3) { turnNum++; }
							if (turnNum == 3) { break; }

							move(board, roll1 + roll2, players);

							if (roll1 == roll2 && !inJail) {
								cout << "You've rolled doubles, and your turn continues." << endl;
							}
							else {
								turn = false;
							}
							break;
						}
							  //Check various info
						case 2: {
							int infoChoice;
							bool infoLoop = true;
							while (infoLoop) {
								cout << "What kind of info would you like to check?\n1) Player\n2) Tile\n3) Board\n4) Back\n";
								cout << "> ";
								cin >> infoChoice;
								switch (infoChoice) {
								case 1: {
									cout << "Who's info would you like to check?" << endl;
									for (int i{ 0 }; i < players.size(); i++) {
										mwp::wait(0.3);
										cout << i + 1 << ") " << players[i]->getName() << endl;
									}
									int inspectPlayer;
									while (true) {
										cout << "> ";
										cin >> inspectPlayer;
										if (inspectPlayer > 0 && inspectPlayer <= players.size()) {
											break;
										}
										else {
											cout << "Not an option!" << endl;
										}
									}
									listInfo(*players[inspectPlayer - 1], board);
									break;
								}
								case 2: {
									cout << "Which tile would you like to check? (1-40)" << endl;
									int inspectTile;
									while (true) {
										cout << "> ";
										cin >> inspectTile;
										if (inspectTile >= 1 && inspectTile <= 40) {
											break;
										}
										else {
											cout << "Not an option!" << endl;
										}
									}
									board[inspectTile - 1].calcRent(board);
									cout << board[inspectTile - 1];
									break;
								}
								case 3: {
									listBoard(players);
									break;
								}
								case 4: {
									infoLoop = false;
									break;
								}
								default: {
									cout << "Not an Option!" << endl;
									break;
								}
								}
							}
							break;
						}
							  //Manage Your Properties
						case 3: {
							int manageChoice;
							cout << "What would you like to do?\n1) Sell Houses\n2) Mortgage Properties\n> ";
							cin >> manageChoice;
							if (manageChoice == 1) {
								cout << "Which properties would you like to sell houses from?" << endl;
								while (true) {
									int propertyChoice;
									vector<Tile*> temp;
									for (int i{ 0 }; i < tiles.size(); i++) {
										if (tiles[i]->houses > 0) {
											temp.push_back(tiles[i]);
										}
									}
									for (int i{ 0 }; i < temp.size(); i++) {
										cout << to_string(i + 1) + ") " << temp[i]->name << " | " << temp[i]->houses << " Houses" << endl;
									}
									cout << "0) Exit\n> ";
									cin >> propertyChoice;
									if (propertyChoice == 0) {
										break;
									}
									else if (propertyChoice >= 1 && propertyChoice <= temp.size()) {
										cout << "You sell all the houses on " << temp[propertyChoice]->name << "." << endl;
										sell(*temp[propertyChoice-1], temp[propertyChoice-1]->houses);
									}
								}
							}
							else if (manageChoice == 2) {
								while (true) {
									cout << "Which property to mortgage/unmortgage?" << endl;
									int mortgageChoice;
									for (int i{ 0 }; i < tiles.size(); i++) {
										cout << to_string(i + 1) + ") " << tiles[i]->name << (tiles[i]->isMortgaged ? " | Mortgaged" : "") << endl;
									}
									cout << "0) Exit\n> ";
									cin >> mortgageChoice;
									if (mortgageChoice != 0) {
										mortgage(*tiles[mortgageChoice - 1]);
									}
									else {
										break;
									}
								}
							}
							else {
								cout << "Not an Option!" << endl;
							}
							break;
						}
							  //Player specific cheat menu
						case 1102: {
							string code;
							cout << "Enter Cheat Code: ";
							cin >> code;
							if (code == "set") {
								string cheatSet;
								string findSet = "utility railroad red orange yellow green lightblue lblue darkblue dblue magenta darkpurple dpurple";
								size_t findFlag;
								cout << "Which set to give: ";
								cin >> cheatSet;
								findFlag = findSet.find(cheatSet);
								if (findFlag != string::npos) {
									for (int i{ 0 }; i < board.getSet(cheatSet).size(); i++) {
										board.getSet(cheatSet).at(i).setOwner(*this);
										tiles.push_back(&board.getSet(cheatSet).at(i));
									}
								}
								else {
									cout << "Not a valid set!" << endl;
								}

							}
							else if (code == "money") {
								int giveMoney;
								cout << "How much money to give: $";
								cin >> giveMoney;
								money += giveMoney;
							}
							else if (code == "moveto") {
								int moveSpace;
								cout << "Which tile to move to: ";
								cin >> moveSpace;
								currentSpace = moveSpace - 1;
								move(board, 0, players);
							}
							else if (code == "bankrupt") {
								int bankruptChoice;
								cout << "Which player to bankrupt: " << endl;
								for (int i{ 0 }; i < players.size(); i++) {
									cout << to_string(i + 1) + ") " << players[i]->getName() << endl;
								}
								cin >> bankruptChoice;
								try {
									players[bankruptChoice - 1]->isBankrupt = true;
								}
								catch (...) {
									cout << "Not a valid choice." << endl;
								}
							}
						}
								 //Default 'Not an Option'
						default: {
							cout << "Not an Option!" << endl;
							break;
						}
					}
					}
					else {
						cin.clear();
						cin.ignore(500, '\n');
						cout << "Not an option!" << endl;
					}
				}
				//Go directly to jail
				else {
					cout << "You've rolled doubles three times in a row, and are being sent to Jail." << endl;
					currentSpace = 10;
					inJail = true;
					turn = false;
				}
				
			}
		}
		//If you aren't bankrupt, but are in jail, do all this stuff
		else {
			cout << "You are in Jail." << endl;
			cout << "What would you like to do?\n1) Pay Fine ($50)\n2) Roll for Doubles\n3) Play 'Get Out of Jail Free' Card\n4) Check Info\n5) Manage Your Properties";
			while (inJail && turn) {
				int choice;
				cout << "\n> ";
				cin >> choice;
				cout << endl;
				//If cin didn't fail, proceed to the switch
				if (!cin.fail()) {
					switch (choice) {
						//Pay off the fine
					case 1: {
						//If you have enough money, you're released, and can take your turn
						if (money - 50 >= 0) {
							money -= 50;
							cout << "You have paid your fine, and have been released." << endl;
							inJail = false;
							mwp::wait(1.5);
							int roll1 = Monopoly::rollDice();
							int roll2 = Monopoly::rollDice();
							cout << "Roll 1: " << roll1 << endl;
							mwp::wait(0.5);
							cout << "Roll 2: " << roll2 << endl;
							mwp::wait(0.5);
							cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
							mwp::wait(0.5);
							move(board, roll1 + roll2, players);
							break;
						}
						//If you don't, choose again
						else {
							cout << "You don't have enough money to pay off your fine." << endl;
							cout << "(Balance: $" << money << ")" << endl;
						}
						break;

					}
						  //Roll for Doubles
					case 2: {

						int roll1 = Monopoly::rollDice();
						int roll2 = Monopoly::rollDice();

						//If you haven't been in jail for three turns, attempt to roll doubles
						if (jailFlag != 3) {
							cout << "Roll 1: " << roll1 << endl;
							mwp::wait(0.5);
							cout << "Roll 2: " << roll2 << endl;
							mwp::wait(0.5);
							if (roll1 == roll2) {
								cout << "You've rolled doubles, and has escaped from Jail early." << endl;
								mwp::wait(1.5);
								inJail = false;
								int roll1 = Monopoly::rollDice();
								int roll2 = Monopoly::rollDice();
								cout << "Roll 1: " << roll1 << endl;
								mwp::wait(0.5);
								cout << "Roll 2: " << roll2 << endl;
								mwp::wait(0.5);
								cout << "You move " << roll1 + roll2 << " spaces." << endl;
								mwp::wait(0.5);
								move(board, roll1 + roll2, players);
								jailFlag = 0;
							}
							else {
								cout << "You weren't able to escape from Jail this turn." << endl;
								mwp::wait(1.5);
								jailFlag++;
								turn = false;
							}
						}
						//Else the Jailer will attempt to take $50 from you
						else {
							cout << "You have been in Jail for three turns, and must now pay your fine." << endl;
							//If successful, yay
							if (money - 50 >= 0) {
								money -= 50;
								cout << "You pay off your fine with no issue, and have been released." << endl;
								mwp::wait(1.5);
								inJail = false;
								int roll1 = Monopoly::rollDice();
								int roll2 = Monopoly::rollDice();
								cout << "Roll 1: " << roll1 << endl;
								mwp::wait(0.5);
								cout << "Roll 2: " << roll2 << endl;
								mwp::wait(0.5);
								cout << "You move " << roll1 + roll2 << " spaces." << endl;
								mwp::wait(0.5);
								move(board, roll1 + roll2, players);
								jailFlag = 0;
							}
							//If not, run bankrupt() to give the player one last change to sell, mortgage, etc enough to pay the fine
							else {
								cout << "You don't have enough money to pay off your fine." << endl;
								cout << "(Balance: $" << money << ")" << endl;
								bankrupt(*board[currentSpace].owner, 50);
								//If after that, you aren't bankrupt, yay
								if (!isBankrupt) {
									cout << "You cobbled together enough money to pay your fine, and have been released." << endl;
									mwp::wait(1.5);
									inJail = false;
									int roll1 = Monopoly::rollDice();
									int roll2 = Monopoly::rollDice();
									cout << "Roll 1: " << roll1 << endl;
									mwp::wait(0.5);
									cout << "Roll 2: " << roll2 << endl;
									mwp::wait(0.5);
									cout << "You move " << roll1 + roll2 << " spaces." << endl;
									mwp::wait(0.5);
									move(board, roll1 + roll2, players);
									jailFlag = 0;

								}
								//If you are bankrupt, the Jailer will take whatever is left in your balance and let you out
								else {
									cout << "You weren't able to put together enough money to pay your fine. The Jailer takes what you do have and releases you." << endl;
									cout << "You have gone Bankrupt." << endl;
									turn = false;
								}
							}
						}
						break;
					}
						  //Play GOOJF Card
					case 3: {
						if (hasGetOutCard) {
							cout << "You show the Jailer your 'Get Out Of Jail Free' card. He begrudgingly lets you out, after taking your card." << endl;
							inJail = false;
							hasGetOutCard = false;
							int roll1 = Monopoly::rollDice();
							int roll2 = Monopoly::rollDice();
							cout << "Roll 1: " << roll1 << endl;
							cout << "Roll 2: " << roll2 << endl;
							cout << "You move " << roll1 + roll2 << " spaces." << endl;
							move(board, roll1 + roll2, players);
							break;
						}
						else {
							cout << "You don't have a 'Get Out Of Jail Free' card to use!" << endl;
						}
						break;
					}
						  //Check someone's info
					case 4: {
						int infoChoice;
						bool infoLoop = true;
						while (infoLoop) {
							cout << "What kind of info would you like to check?\n1) Player\n2) Tile\n3) Board\n4) Back\n";
							cout << "> ";
							cin >> infoChoice;
							switch (infoChoice) {
							case 1: {
								cout << "Who's info would you like to check?" << endl;
								for (int i{ 0 }; i < players.size(); i++) {
									mwp::wait(0.3);
									cout << i + 1 << ") " << players[i]->getName() << endl;
								}
								int inspectPlayer;
								while (true) {
									cout << "> ";
									cin >> inspectPlayer;
									if (inspectPlayer > 0 && inspectPlayer <= players.size()) {
										break;
									}
									else {
										cout << "Not an option!" << endl;
									}
								}
								listInfo(*players[inspectPlayer - 1], board);
								break;
							}
							case 2: {
								cout << "Which tile would you like to check? (1-40)" << endl;
								int inspectTile;
								while (true) {
									cout << "> ";
									cin >> inspectTile;
									if (inspectTile >= 1 && inspectTile <= 40) {
										break;
									}
									else {
										cout << "Not an option!" << endl;
									}
								}
								cout << board[inspectTile - 1];
								break;
							}
							case 3: {
								listBoard(players);
								break;
							}
							case 4: {
								infoLoop = false;
								break;
							}
							default: {
								cout << "Not an Option!" << endl;
								break;
							}
							}
						}
						break;
					}
						  //Manage your Properties
					case 5: {
						int manageChoice;
						cout << "What would you like to do?\n1) Sell Houses\n2) Mortgage Properties\n> ";
						cin >> manageChoice;
						if (manageChoice == 1) {
							cout << "Which properties would you like to sell houses from?" << endl;
							while (true) {
								int propertyChoice;
								vector<Tile*> temp;
								for (int i{ 0 }; i < tiles.size(); i++) {
									if (tiles[i]->houses > 0) {
										temp.push_back(tiles[i]);
									}
								}
								for (int i{ 0 }; i < temp.size(); i++) {
									cout << to_string(i + 1) + ") " << temp[i]->name << " | " << temp[i]->houses << " Houses" << endl;
								}
								cout << "0) Exit\n> ";
								cin >> propertyChoice;
								if (propertyChoice == 0) {
									break;
								}
								else if (propertyChoice >= 1 && propertyChoice <= temp.size()) {
									cout << "You sell all the houses on " << temp[propertyChoice]->name << "." << endl;
									sell(*temp[propertyChoice - 1], temp[propertyChoice - 1]->houses);
								}
							}
						}
						else if (manageChoice == 2) {
							while (true) {
								cout << "Which property to mortgage/unmortgage?" << endl;
								int mortgageChoice;
								for (int i{ 0 }; i < tiles.size(); i++) {
									cout << to_string(i + 1) + ") " << tiles[i]->name << (tiles[i]->isMortgaged ? " | Mortgaged" : "") << endl;
								}
								cout << "0) Exit\n> ";
								cin >> mortgageChoice;
								if (mortgageChoice != 0) {
									mortgage(*tiles[mortgageChoice - 1]);
								}
								else {
									break;
								}
							}
						}
						else {
							cout << "Not an Option!" << endl;
						}
						break;
					}
						  //Not an Option
					default: {
						cout << "Not an Option!" << endl;
						break;
					}
					}
				}
				else {
					cin.clear();
					cin.ignore(500, '\n');
					cout << "Not an option!" << endl;
				}
				
			}
		}
		cout << name << "'s turn ends." << endl;
		cout << "---------------------------------------------" << endl;
		mwp::wait(1);
	}
}

void Player::trade(Entity& target) {

}