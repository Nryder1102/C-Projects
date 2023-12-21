#include "Entity.h"
#include "Board.h"
#include "Monopoly.h"
#include "MWP.hpp"
#include <string>
#include <iostream>


using namespace std;

Entity::Entity() : isPlayer(false) {
	name = "Banker";
	money = 1500;
}

Entity::Entity(string n) {
	name = n;
	money = 1500;
}

void Entity::listInfo(Entity& target, Board& board) {

	string output = "";
	string utility = "Utilities:";
	string railroad = "Railroads:";
	string red = "Red:";
	string orange = "Orange:";
	string yellow = "Yellow:";
	string green = "Green:";
	string lblue = "Light Blue:";
	string dblue = "Dark Blue:";
	string magenta = "Magenta:";
	string dpurple = "Dark Purple:";

	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Name            : " << target.name << endl;
	cout << "Balance         : $" << target.money << endl;
	cout << "Current Space   : " << board[target.currentSpace].name << endl;
	if (board[target.currentSpace].name == "Jail") {
		cout << "In Jail         : " << (target.inJail == true ? "Yes" : "Just Visiting") << endl;
	}
	cout << "Owned Properties: " << endl;
	cout << "-----------------------------------------------------" << endl;
	for (int i{ 0 }; i < target.tiles.size(); i++) {
		string delim = " ";

		if (utility != "Utilities:") { delim = ", "; }
		if (railroad != "Railroads:") { delim = ", "; }
		if (red != "Red:") { delim = ", "; }
		if (orange != "Orange:") { delim = ", "; }
		if (yellow != "Yellow:") { delim = ", "; }
		if (green != "Green:") { delim = ", "; }
		if (lblue != "Light Blue:") { delim = ", "; }
		if (dblue != "Dark Blue:") { delim = ", "; }
		if (magenta != "Magenta:") { delim = ", "; }
		if (dpurple != "Dark Purple:") { delim = ", "; }

		if (target.tiles[i]->set == Set::Utility) {
			utility += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Railroad) {
			railroad += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Red) {
			red += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Orange) {
			orange += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Yellow) {
			yellow += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Green) {
			green += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::LightBlue) {
			lblue += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::DarkBlue) {
			dblue += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::Magenta) {
			magenta += delim + target.tiles[i]->name;
		}else if (target.tiles[i]->set == Set::DarkPurple) {
			dpurple += delim + target.tiles[i]->name;
		}
	}

	if (utility != "Utilities:") {output += utility + "\n";}
	if (railroad != "Railroads:") {output += railroad + "\n";}
	if (red != "Red:") {output += red + "\n";}
	if (orange != "Orange:") {output += orange + "\n";}
	if (yellow != "Yellow:") {output += yellow + "\n";}
	if (green != "Green:") {output += green + "\n";}
	if (lblue != "Light Blue:") {output += lblue + "\n";}
	if (dblue != "Dark Blue:") {output += dblue + "\n";}
	if (magenta != "Magenta:") {output += magenta + "\n";}
	if (dpurple != "Dark Purple:") {output += dpurple + "\n";}

	if (output != "") {
		cout << output;
	}
	else {
		cout << "No Owned Properties" << endl;
	}
	cout << "-----------------------------------------------------" << endl << endl;
}

void Entity::listBoard(vector<Entity*>& players) {
	
	string b = "<---------J---------F---------X---------";
	char digits[] = { '1','2','3','4','5','6' };
	
	//Replace the spot in the b string with the number of the player there, if there's multiple, replace with an asterisk
	for (int i{ 0 }; i < players.size(); i++) {
		char *search = std::find(std::begin(digits), std::end(digits), b[players[i]->currentSpace]);
		if (search != std::end(digits)) {
			b[players[i]->currentSpace] = '*';
		}
		else {
			b[players[i]->currentSpace] = digits[i];
		}
	}


	//Could this have been done easier? Oh, almost certainly, but this is what I got to work
	cout << endl;
	cout << "|" << b[20] << "|" << b[21] << "|" << b[22] << "|" << b[23] << "|" << b[24] << "|" << b[25] << "|" << b[26] << "|" << b[27] << "|" << b[28] << "|" << b[29] << "|" << b[30] << "|" << endl;
	cout << "|" << b[19] << "|                 |" << b[31] << "|" << endl;
	cout << "|" << b[18] << "|                 |" << b[32] << "|" << endl;
	cout << "|" << b[17] << "|                 |" << b[33] << "|" << endl;
	cout << "|" << b[16] << "|                 |" << b[34] << "|" << endl;
	cout << "|" << b[15] << "|                 |" << b[35] << "|" << endl;
	cout << "|" << b[14] << "|                 |" << b[36] << "|" << endl;
	cout << "|" << b[13] << "|                 |" << b[37] << "|" << endl;
	cout << "|" << b[12] << "|                 |" << b[38] << "|" << endl;
	cout << "|" << b[11] << "|                 |" << b[39] << "|" << endl;
	cout << "|" << b[10] << "|" << b[9] << "|" << b[8] << "|" << b[7] << "|" << b[6] << "|" << b[5] << "|" << b[4] << "|" << b[3] << "|" << b[2] << "|" << b[1] << "|" << b[0] << "|" << endl;

	cout << "\nG = Go, J = Jail, F = Free Parking, X = Go To Jail" << endl;
	cout << "* = Multiple Players" << endl;
	string delim = "";
	for (int i{ 0 }; i < players.size(); i++) {
		cout << delim << to_string(i + 1) << " = " << players[i]->getName();
		delim = ", ";
	}
	cout << endl << endl;
}

void Entity::takeTurn(Board& board, vector<Entity*>& players) {
	int turnNum{ 0 };
	bool turn = true;
	if (!isBankrupt) {
		cout << name << "'s turn begins." << endl;
		mwp::wait(1.5);
		//If you aren't bankrupt and not in jail, take your turn
		if (!inJail) {
			while (turn) {
				//Always roll
				int choice = 1;
				if (turnNum != 3) {
					switch (choice) {

					//Roll dice and move
					case 1: {

						int roll1 = Monopoly::rollDice();
						int roll2 = Monopoly::rollDice();
						cout << "Roll 1: " << roll1 << endl;
						mwp::wait(0.5);
						cout << "Roll 2: " << roll2 << endl;
						mwp::wait(0.5);

						if (roll1 == roll2 && turnNum != 3) {turnNum++;}
						if (turnNum == 3) {break;}

						cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
						mwp::wait(0.5);
						move(board, roll1 + roll2, players);

						if (roll1 != roll2) {
							turn = false;
						}
						else {
							if (!inJail) {
								cout << name << " has rolled doubles, and takes another turn." << endl;
							}
							else {
								turn = false;
							}
						}
						break;
					}

					}
				}
				else {
					cout << name << " has rolled doubles three times in a row, and is being taken to Jail." << endl;
					currentSpace = 10;
					inJail = true;
					turn = false;
				}
			}
		}
		//If you aren't bankrupt, but are in jail, do all this stuff
		else {
			cout << name << " is in Jail." << endl;
			mwp::wait(1.5);
			while (inJail && turn) {
				int choice;

				if (money >= 500) {
					choice = mwp::randBetween(1,2);
				}
				else if (money > 100) {
					choice = mwp::randBetween(1,3);
				}
				else {
					choice = mwp::randBetween(2,3);
				}

				switch(choice){
					mwp::wait(0.5);
					//Pay off the fine
					case 1: {
						money -= 50;
						cout << name << " has paid their fine, and has been released." << endl;
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
					//Roll for Doubles
					case 2: {

						cout << name << " is trying to roll for doubles." << endl;

						int roll1 = Monopoly::rollDice();
						int roll2 = Monopoly::rollDice();
						
						//If you haven't been in jail for three turns, attempt to roll doubles
						if (jailFlag != 3) {
							cout << "Roll 1: " << roll1 << endl;
							mwp::wait(0.5);
							cout << "Roll 2: " << roll2 << endl;
							mwp::wait(0.5);
							if (roll1 == roll2) {
								cout << name << " has rolled doubles, and has escaped from Jail early." << endl;
								mwp::wait(1.5);
								inJail = false;
								int roll1 = Monopoly::rollDice();
								int roll2 = Monopoly::rollDice();
								cout << "Roll 1: " << roll1 << endl;
								mwp::wait(0.5);
								cout << "Roll 2: " << roll2 << endl;
								mwp::wait(0.5);
								cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
								mwp::wait(0.5);
								move(board, roll1 + roll2, players);
								jailFlag = 0;
							}
							else {
								cout << name << " wasn't able to escape from Jail this turn." << endl;
								mwp::wait(1.5);
								jailFlag++;
								turn = false;
							}
						}
						//Else the Jailer will attempt to take $50 from you
						else {
							cout << name << " has been in Jail for three turns, and must now pay their fine." << endl;
							mwp::wait(1.5);
							//If successful, yay
							if (money - 50 >= 0) {
								money -= 50;
								cout << name << " pays off their fine with no issue, and has been released." << endl;
								mwp::wait(1.5);
								inJail = false;
								int roll1 = Monopoly::rollDice();
								int roll2 = Monopoly::rollDice();
								cout << "Roll 1: " << roll1 << endl;
								mwp::wait(0.5);
								cout << "Roll 2: " << roll2 << endl;
								mwp::wait(0.5);
								cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
								mwp::wait(0.5);
								move(board, roll1 + roll2, players);
								jailFlag = 0;
							}
							//If not, run bankrupt() to give the player one last change to sell, mortgage, etc enough to pay the fine
							else {
								cout << name << " doesn't have enough money to pay off their fine." << endl;
								mwp::wait(1.5);
								bankrupt(*board[currentSpace].owner, 50);
								//If after that, you aren't bankrupt, yay
								if (!isBankrupt) {
									//If you have enough money to pay your fine, double yay
									if (money - 50 >= 0) {
										money -= 50;
										cout << name << " cobbled together enough money to pay their fine, and has been released." << endl;
										mwp::wait(1.5);
										inJail = false;
										int roll1 = Monopoly::rollDice();
										int roll2 = Monopoly::rollDice();
										cout << "Roll 1: " << roll1 << endl;
										mwp::wait(0.5);
										cout << "Roll 2: " << roll2 << endl;
										mwp::wait(0.5);
										cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
										mwp::wait(0.5);
										move(board, roll1 + roll2, players);
										jailFlag = 0;
									}
								}
								//If you are bankrupt, the Jailer will take whatever is left in your balance and let you out
								else {
									cout << name << " wasn't able to put together enough money to pay their fine. The Jailer takes what they do have and releases them." << endl;
									mwp::wait(1.5);
									cout << name << " has gone Bankrupt." << endl;
									mwp::wait(2);
									turn = false;
								}
							}
						}
						break;
					}
					//Play GOOJF Card
					case 3: {
						if (hasGetOutCard) {
							cout << name << " shows the Jailer their 'Get Out Of Jail Free' card. He begrudgingly lets them out, after taking the card." << endl;
							inJail = false;
							hasGetOutCard = false;
							int roll1 = Monopoly::rollDice();
							int roll2 = Monopoly::rollDice();
							cout << "Roll 1: " << roll1 << endl;
							cout << "Roll 2: " << roll2 << endl;
							cout << name << " moves " << roll1 + roll2 << " spaces." << endl;
							move(board, roll1 + roll2, players);
							break;
						}
					}
				}
			}
		}
		cout << name << "'s turn ends." << endl;
		cout << "---------------------------------------------" << endl;
		mwp::wait(1);
	}
}

//This function handles moving across the board, as well as checking to see what the landed on space does, or if it's owned or not, yada yada. Fun stuff
void Entity::move(Board& board, int spaces, vector<Entity*>& players) {
	if (spaces >= 0) {
		for (int i{ spaces }; i > 0; --i) {

			currentSpace++;

			if (currentSpace == board.size() && i == 1) {
				currentSpace = 0;
			}
			else if (currentSpace == board.size() && i > 1) {
				if (isPlayer) {
					cout << "You've passed GO! You collect $200." << endl;
				}
				else {
					cout << name << " has passed GO! They collect $200." << endl;
				}
				currentSpace = 0;
				money += 200;
			}
		}
	}
	//This should allow for negative movement?
	else {
		for (int i{ spaces }; i < 0; ++i) {

			currentSpace--;

			if (currentSpace == 0 && i < -1) {
				currentSpace = 39;
			}
		}
	}
	

	//Calculate the current rent of the tile when landed on
	if (board[currentSpace].set == Set::Utility) {
		board[currentSpace].calcRent(board, spaces);
	}
	else {
		board[currentSpace].calcRent(board);
	}

	//This'll be kinda tedius, but it'll make me feel good.
	//I'm currently splitting up the responses based on if you're a real person or not
	if (isPlayer) {
		cout << "\n" << name << " lands on " << board[currentSpace].name << endl;
		if (board[currentSpace].set != Set::Special) {cout << board[currentSpace];}
	}
	else {cout << name << " has landed on " << board[currentSpace].name << "." << endl;}

	//If space is owned by not this person, and isn't special
	if (board[currentSpace].owner != board.bankerPtr && board[currentSpace].set != Set::Special && board[currentSpace].owner != this) {
		//If player
		if (isPlayer) {
			//If the tile has been mortgaged, no rent is owed
			if (board[currentSpace].isMortgaged) {cout << "This property has been mortgaged, so no rent is owed." << endl;}
			//Else, attempt to pay rent
			else {
				cout << "The current rent owed on this property is $" << board[currentSpace].rent << "." << endl;
				if (money - board[currentSpace].rent >= 0) {
					cout << "You pay $" << board[currentSpace].rent << " in rent to " << board[currentSpace].owner->getName() << "." << endl;
					payRent(*board[currentSpace].owner, board[currentSpace].rent);
				}
				else {
					cout << "You don't have enough money to pay off the rent." << endl;
					bankrupt(*board[currentSpace].owner, board[currentSpace].rent);
				}
			}
		}
		//Bot versions of the above
		else {
			if (!board[currentSpace].isMortgaged) {
				if (money - board[currentSpace].rent >= 0) {
					cout << name << " pays $" << board[currentSpace].rent << " in rent to " << board[currentSpace].owner->getName() << "." << endl;
					payRent(*board[currentSpace].owner, board[currentSpace].rent);
				}
				else {
					cout << name << "doesn't have enough money to pay off the rent." << endl;
					bankrupt(*board[currentSpace].owner, board[currentSpace].rent);
				}
			}
		}
	}
	//If space is owned by this person
	else if (board[currentSpace].owner == this) {
		if (isPlayer) { cout << "You currently own this space." << endl; }
		else { cout << name << " currently owns this space." << endl; }

		//If the space is not a utility or railroad, and the owner owns the full set, and doesn't have max houses, ask if they want to upgrade
		if (board.checkFullSet(board[currentSpace].set, *this) && board[currentSpace].set != Set::Utility && board[currentSpace].set != Set::Railroad) {
			if (isPlayer && board[currentSpace].houses != 5) {
				cout << "As you own this full color set, you can build houses on this property." << endl;
				if (board.checkHouseUpgrade(board[currentSpace].set,board[currentSpace])) {
					upgrade(board[currentSpace]);
				}
				else {
					cout << "You cannot upgrade this property further until you upgrade the others in the set." << endl;
				}
			}
			//Bot version
			else {
				if (mwp::probability(35)) {
					if (board.checkHouseUpgrade(board[currentSpace].set, board[currentSpace]) && money > 450) {
						cout << name << " upgrades their property." << endl;
						upgrade(board[currentSpace]);
					}
				}
			}
		}
		//Else if you land on a railroad, ask if you want to travel to a different railroad you own
		else if (board[currentSpace].set == Set::Railroad) {

			int flag{0};
			vector<Tile*> ownedRails;
			
			for (int i{ 0 }; i < tiles.size(); i++) {
				if (tiles[i]->set == Set::Railroad) {
					flag++;
					ownedRails.push_back(tiles[i]);
				}
			}

			if (flag >= 2) {
				if (isPlayer) {
					cout << "You own multiple Railroads.\nWould you like to move to a different Railroad?" << endl;
					if (mwp::confirm()) {
						int choice;
						for (int i{ 0 }; i < ownedRails.size(); i++) {
							cout << to_string(i + 1) + ") " << ownedRails[i]->name << endl;
						}
						cin >> choice;
						if (!cin.fail() && choice >= 1 && choice <= ownedRails.size()) {
							cout << "You ride the rails to " << ownedRails[choice]->name << endl;
							for (int i{ 0 }; i < board.size(); i++) {
								if (&board[i] == ownedRails[choice]) {
									currentSpace = i;
									break;
								}
							}
						}
						else {
							cin.clear();
							cin.ignore(500, '\n');
							cout << "You decide not to ride the rails." << endl;
						}
						
					}
				}
				//Bot version
				else {
					if (mwp::probability(30)) {
						int chosenRail = mwp::randBetween(1, ownedRails.size());
						cout << name << " rides the rails to " << ownedRails[chosenRail] << endl;
						for (int i{ 0 }; i < board.size(); i++) {
							if (&board[i] == ownedRails[chosenRail]) {
								currentSpace = i;
								break;
							}
						}
					}
				}
			}

		}
	}
	//If space is unowned and not special
	else if (board[currentSpace].set != Set::Special) {
		if (isPlayer) {
			cout << "Nobody currently owns this space.\nWould you like to buy it? (" << board[currentSpace].cost << ")" << endl;
			cout << "Current Balance: $" << money << endl;
			if (mwp::confirm()) {
				buy(board[currentSpace]);
			}
				else {
					cout << "You choose not to buy this property." << endl;
				}
		}
		//Bot version
		else {
			//Make sure to only buy if the bot has a little extra cash
			if (money > board[currentSpace].cost + 250) {
				//Check how many spaces in the set the bot already owns, prioritizing finishing sets with more owned tiles and starting new ones
				//It'll buy a new set with a 75/25 chance
				//If it owns one in a set, it'll buy it with a 40/60
				//If it owns two in a set, it'll buy it with 60/40
				int setFlag = 0;
				for (int i{ 0 }; i < board.getSet(board[currentSpace].set).size(); i++) {
					if (board.getSet(board[currentSpace].set).at(i).owner == this) {
						setFlag++;
					}
				}
				switch (setFlag) {
				case 0: {
					if (mwp::probability(75)) {
						buy(board[currentSpace]);
					}
					break;
				}
				case 1: {
					if (mwp::probability(40)) {
						buy(board[currentSpace]);
					}
					break;
				}
				case 2: {
					if (mwp::probability(60)) {
						buy(board[currentSpace]);
					}
					break;
				}
				default: {
					buy(board[currentSpace]);
				}
				}
			}
		}
	}
	//Else if the space IS special, do an action
	else {
		board[currentSpace].doAction(*this, board, players);
	}
}

void Entity::buy(Tile& tile) {
	if (money >= tile.cost) {
		tile.setOwner(*this);
		money -= tile.cost;
		tiles.push_back(&tile);
		cout << name << " buys " << tile.name << "." << endl;
	}
	else {
		cout << "You don't have enough money to buy this property!" << endl;
	}
}

//Sell the amount of houses on a selected property
void Entity::sell(Tile& tile, int amount) {
	if (amount != 0) {
		money += round((tile.houseCost * amount) / 2);
		tile.houses -= amount;
	}
}

void Entity::upgrade(Tile& tile){
	if (tile.houses <= 5) {
		if (isPlayer) {
			cout << "Would you like to upgrade this property? (" << tile.houseCost << ")" << endl;
			if (mwp::confirm()) {
				if (money - tile.houseCost >= 0) {
					cout << "You upgrade your property." << endl;
					money -= tile.houseCost;
					tile.houses += 1;
				}
				else {
					cout << "You don't have enough money to upgrade this property." << endl;
				}
			}
			else {
				cout << "You decide not to upgrade this property." << endl;
			}
		}
		else {
			money -= tile.houseCost;
			tile.houses += 1;
		}
	}
}

void Entity::mortgage(Tile& tile) {
	if (!tile.isMortgaged) {
		if (isPlayer) {
			cout << "Would you like to mortgage the property: " << tile.name << "?" << endl;
			if (mwp::confirm()) {
				if (tile.houses > 0) {
					cout << "You can't mortgage a property with houses!\nSell houses?" << endl;
					if (mwp::confirm()) {
						cout << "You mortgage the property for $" << tile.mortgage << "." << endl;
						sell(tile, tile.houses);
						money += tile.mortgage;
						tile.isMortgaged = true;
					}
					else {
						cout << "You decide not to mortgage the property." << endl;
					}
				}
				else {
					money += tile.mortgage;
					tile.isMortgaged = true;
				}
			}
			else {
				cout << "You decide not to mortgage the property." << endl;
			}
		}
	}
	//If the property is currently mortgaged
	else {
		//Player actions
		if (isPlayer) {
			cout << "This property is currently mortgaged. It will cost $" << to_string(tile.mortgage+(tile.mortgage*10)/100) << " to lift it." << endl;
			cout << "Would you like to lift it?" << endl;
			if (mwp::confirm()) {
				if (money >= (tile.mortgage+(tile.mortgage * 10)/100)) {
					money -= tile.mortgage+(tile.mortgage * 10) / 100;
					tile.isMortgaged = false;
				}
				else { cout << "You don't have enough money!" << endl;}
			}
			else {
				cout << "You decide not to lift the mortgage." << endl;
			}
		}
		//Bot will always try to lift mortgage if possible
		else {
			if (money > (tile.mortgage + (tile.mortgage * 10) / 100)) {
				cout << name << " lifts the mortgage on the property." << endl;
				money -= tile.mortgage + (tile.mortgage * 10) / 100;
				tile.isMortgaged = false;
			}
			else {
				cout << name << " decides not to lift the mortgage." << endl;
			}
		}
	}
}

void Entity::trade(Entity& target) {

}

void Entity::payRent(Entity& target, int amount) {
	money -= amount;
	target.money += amount;
}

//Function that serves as a last-ditch effort to sell/mortgage properties when out of money. I
void Entity::bankrupt(Entity& target, int amount) {
	if (isPlayer) { cout << "You are about to Bankrupt!" << endl; }
	//Loop until the player/bot is done
	while (true) {
		//Player actions
		if (isPlayer) {
			{
				int manageChoice;
				cout << "What would you like to do?\n1) Sell Houses\n2) Mortgage Properties\n3) Exit\n> ";
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
				else if(manageChoice == 3){
					break;
				}
				else {
					cout << "Not an Option!" << endl;
				}
			}
		}
		//Bot actions
		else {
			//Bots will just auto-lose to make game faster
			break;
		}
	}

	//If you couldn't reach the amount, all your stuff goes to the player that bankrupted you, or the Banker
	if (money < amount) {
		isBankrupt = true;
		//Give money to the player you bankrupt to
		target.money += money;
		//Set money to 0
		money = 0;
		for (int i{ 0 }; i < tiles.size(); i++) {
			sell(*tiles[i], tiles[i]->houses);
			//Give the money from selling to the player you bankrupt to
			target.money += money;
			money = 0;
			tiles[i]->setOwner(target);
			if (target.name == "Banker") {
				tiles[i]->isMortgaged = false;
			}
			//If the property isn't going back to the banker, check if it's mortgaged
			else {
				if (tiles[i]->isMortgaged) {
					//If it is, prompt to lift the mortgage
					mortgage(*tiles[i]);
					//If they don't, charge the target for 10% of property mortgage cost
					if (tiles[i]->isMortgaged) {
						if (isPlayer) {
							cout << "As you decided not to lift the mortgage, you must pay the Banker $" << to_string((tiles[i]->mortgage * 10) / 100) << "." << endl;
						}
						if (target.money >= (tiles[i]->mortgage * 10) / 100) {
							target.money -= (tiles[i]->mortgage * 10) / 100;
						}
						else {
							cout << target.name << " has gone bankrupt, as they could not cover the fees for their new property." << endl;
							target.isBankrupt = true;
						}
					}
				}
			}
		}
	}

}
