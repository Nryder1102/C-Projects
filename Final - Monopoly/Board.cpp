#include "Board.h"
#include "Entity.h"
#include "Monopoly.h"
#include <vector>

using namespace std;
Entity Board::banker;
Entity* Board::bankerPtr = &banker;
vector<Tile> Board::special = { Tile("Go",Set::Special, bankerPtr),Tile("Community Chest",Set::Special, bankerPtr),Tile("Income Tax",Set::Special, bankerPtr),Tile("Chance",Set::Special, bankerPtr),Tile("Jail",Set::Special, bankerPtr),Tile("Community Chest",Set::Special, bankerPtr),Tile("Free Parking",Set::Special, bankerPtr),Tile("Chance",Set::Special, bankerPtr),Tile("Go To Jail",Set::Special, bankerPtr),Tile("Community Chest",Set::Special, bankerPtr),Tile("Chance",Set::Special, bankerPtr),Tile("Luxury Tax",Set::Special, bankerPtr) };
vector<Tile> Board::utility = { Tile("Default",Set::Special,bankerPtr) };
vector<Tile> Board::railroad = { Tile("Default",Set::Special,bankerPtr) };
vector<Tile> Board::red = { Tile("Kentucky Avenue", Set::Red,220,{18,90,250,700,875,1050},150,110,bankerPtr),Tile("Indiana Avenue", Set::Red,220,{18,90,250,700,875,1050},150,110, bankerPtr),Tile("Illinois Avenue", Set::Red, 240,{20,100,300,750,925,1100},150,120, bankerPtr) };
vector<Tile> Board::orange = { Tile("St. James Place", Set::Orange,180,{14,70,200,550,750,950},100,90,bankerPtr),Tile("Tennessee Avenue", Set::Orange,180,{14,70,200,550,750,950},100,90,bankerPtr),Tile("New York Avenue", Set::Orange,200,{16,80,220,600,800,1000},100,100,bankerPtr) };
vector<Tile> Board::yellow = { Tile("Atlantic Avenue", Set::Yellow,260,{22,110,330,800,975,1150},150,130,bankerPtr),Tile("Ventnor Avenue", Set::Yellow,260,{22,110,330,800,975,1150},150,130,bankerPtr),Tile("Marvin Gardens", Set::Yellow,280,{24,120,360,850,1025,1200},150,140,bankerPtr) };
vector<Tile> Board::green = { Tile("Pacific Avenue", Set::Green, 300,{26,130,290,900,1100,1275},200,150, bankerPtr),Tile("North Carolina Avenue", Set::Green, 300,{26,130,290,900,1100,1275},200,150,  bankerPtr),Tile("Pennsylvania Avenue", Set::Green, 320,{28,150,450,1000,1200,1400},200,160, bankerPtr) };
vector<Tile> Board::lightblue = { Tile("Oriental Avenue", Set::LightBlue, 100, { 6,30,90,270,400,550 }, 50, 50, bankerPtr),Tile("Vermont Avenue", Set::LightBlue, 100, { 6,30,90,270,400,550 }, 50, 50, bankerPtr),Tile("Connecticut Avenue", Set::LightBlue, 120, { 8,40,100,300,450,600 }, 50, 60, bankerPtr) };
vector<Tile> Board::darkblue = { Tile("Park Place", Set::DarkBlue, 350,{35,175,500,1100,1300,1500},200,175,bankerPtr), Tile("Boardwalk",Set::DarkBlue,400,{50,200,600,1400,1700,2000},200,200,bankerPtr) };
vector<Tile> Board::magenta = { Tile("St. Charles Place", Set::Magenta, 140, {10,50,150,450,625,750}, 100, 70, bankerPtr), Tile("States Avenue", Set::Magenta, 140, {10,50,150,450,625,750}, 100, 70, bankerPtr), Tile("Virginia Avenue", Set::Magenta,160,{12,60,180,500,700,900},100,80,bankerPtr) };
vector<Tile> Board::darkpurple = {Tile("Mediterranean Avenue", Set::DarkPurple, 60, {2,10,30,90,160,250},50,30, bankerPtr),Tile("Baltic Avenue",Set::DarkPurple, 60, {4,20,60,180,320,450},50,30, bankerPtr) };

Board::Board() {
	utility.clear();
	railroad.clear();
	Monopoly::genSet(Set::Utility, utility, *bankerPtr);
	Monopoly::genSet(Set::Railroad, railroad, *bankerPtr);
	genBoard(banker);
}

//Generate the game board
void Board::genBoard(Entity& bankerPtr) {
	//Create the board
	//Go
	board.push_back(&special[0]);
	//Mediterranean
	board.push_back(&darkpurple[0]);
	//Chest
	board.push_back(&special[1]);
	//Baltic
	board.push_back(&darkpurple[1]);
	//Income Tax
	board.push_back(&special[2]);
	//RR 1
	board.push_back(&railroad[0]);
	//Oriental
	board.push_back(&lightblue[0]);
	//Chance
	board.push_back(&special[3]);
	//Vermont
	board.push_back(&lightblue[1]);
	//Connecticut
	board.push_back(&lightblue[2]);
	//Jail
	board.push_back(&special[4]);
	//St. Charles
	board.push_back(&magenta[0]);
	//Utility 1
	board.push_back(&utility[0]);
	//States
	board.push_back(&magenta[1]);
	//Virginia
	board.push_back(&magenta[2]);
	//RR 2
	board.push_back(&railroad[1]);
	//St. James
	board.push_back(&orange[0]);
	//Chest
	board.push_back(&special[5]);
	//Tenesse
	board.push_back(&orange[1]);
	//New York
	board.push_back(&orange[2]);
	//Free Parking
	board.push_back(&special[6]);
	//Kentucky
	board.push_back(&red[0]);
	//Chance
	board.push_back(&special[7]);
	//Indiana
	board.push_back(&red[1]);
	//Illinois
	board.push_back(&red[2]);
	//RR 3
	board.push_back(&railroad[2]);
	//Atlantic
	board.push_back(&yellow[0]);
	//Ventnor
	board.push_back(&yellow[1]);
	//Utility 2
	board.push_back(&utility[1]);
	//Marvin
	board.push_back(&yellow[2]);
	//Go to Jail
	board.push_back(&special[8]);
	//Pacific
	board.push_back(&green[0]);
	//North Carolina
	board.push_back(&green[1]);
	//Chest
	board.push_back(&special[9]);
	//Pennsylvania
	board.push_back(&green[2]);
	//RR 4
	board.push_back(&railroad[3]);
	//Chance
	board.push_back(&special[10]);
	//Park
	board.push_back(&darkblue[0]);
	//Luxury Tax
	board.push_back(&special[11]);
	//Boardwalk
	board.push_back(&darkblue[1]);
}

//Check if a specified player owns the full set of tiles
bool Board::checkFullSet(Set set, Entity& target) {
	int setSize = getSet(set).size();
	int flag{0};
	for (int i{ 0 }; i < setSize; i++) {
		if (getSet(set).at(i).owner == &target && getSet(set).at(i).owner != bankerPtr) {
			flag++;
		}
	}
	return (flag == setSize ? true : false);
}

//Returns true if the property is upgradeable
bool Board::checkHouseUpgrade(Set set, Tile& tile) {

	int highestHouse{0};
	int setSize = getSet(set).size();
	int flag{ 0 };

	for (int i{ 0 }; i < getSet(set).size(); i++) {
		if (getSet(set).at(i).houses > highestHouse) {
			highestHouse = getSet(set).at(i).houses;
		}
	}

	for (int i{ 0 }; i < setSize; i++) {
		if (getSet(set).at(i).houses == highestHouse) {
			flag++;
		}
	}

	if (flag == setSize || tile.houses < highestHouse) {
		return true;
	}
	else {
		return false;
	}

}

//Function to check if every property in a set has four houses
bool Board::checkFullHouses(Set set) {
	int setSize = getSet(set).size();
	int flag{ 0 };
	for (int i{ 0 }; i < setSize; i++) {
		if (getSet(set).at(i).houses == 4) {
			flag++;
		}
	}
	return (flag == setSize ? true : false);
}

//Return a specified set of tiles
vector<Tile>& Board::getSet(Set set) {
	switch (set) {
	case Set::Special: {
		return special;
		break;
	}
	case Set::Utility: {
		return utility;
		break;
	}
	case Set::Railroad: {
		return railroad;
		break;
	}
	case Set::Red: {
		return red;
		break;
	}
	case Set::Orange: {
		return orange;
		break;
	}
	case Set::Yellow: {
		return yellow;
		break;
	}
	case Set::Green: {
		return green;
		break;
	}
	case Set::LightBlue: {
		return lightblue;
		break;
	}
	case Set::DarkBlue: {
		return darkblue;
		break;
	}
	case Set::Magenta: {
		return magenta;
		break;
	}
	case Set::DarkPurple: {
		return darkpurple;
		break;
	}
	}
}

//Version of getSet to be used with a string, pretty much specifically for the cheat menu
vector<Tile>& Board::getSet(string set) {
	if (set == "utility") {
		return getSet(Set::Utility);
	}
	else if (set == "railroad") {
		return getSet(Set::Railroad);
	}
	else if (set == "red") {
		return getSet(Set::Red);
	}
	else if (set == "orange") {
		return getSet(Set::Orange);
	}
	else if (set == "yellow") {
		return getSet(Set::Yellow);
	}
	else if (set == "green") {
		return getSet(Set::Green);
	}
	else if (set == "lightblue" || set == "lblue" || set == "light blue") {
		return getSet(Set::LightBlue);
	}
	else if (set == "darkblue" || set == "dblue" || set == "dark blue") {
		return getSet(Set::DarkBlue);
	}
	else if (set == "magenta") {
		return getSet(Set::Magenta);
	}
	else if (set == "darkpurple" || set == "dpurple" || set == "dark purple") {
		return getSet(Set::DarkPurple);
	}
}