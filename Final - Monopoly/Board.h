#pragma once
#include <string>
#include <vector>
#include <array>
#include <iostream>

class Entity;

enum class Set {
	Special,
	Utility,
	Railroad,
	Red,
	Orange,
	Yellow,
	Green,
	LightBlue,
	DarkBlue,
	Magenta,
	DarkPurple
};

class Board;

class Tile {

	friend std::ostream& operator<<(std::ostream&, const Tile&);

public:
	Tile(std::string n, Set s);
	Tile(std::string n, Set s, Entity* o);
	Tile(std::string n, Set s, int c);
	Tile(std::string n, Set s, int c, Entity* o);
	Tile(std::string n, Set s, int c, std::array<int, 6> rTbl);
	Tile(std::string n, Set s, int c, std::array<int, 6> rTbl, int hC, int m, Entity* o);

	const static std::string sets[];

	void doAction(Entity& target, Board& board, std::vector<Entity*> players);
	void calcRent(Board& board);
	void calcRent(Board& board, int roll);

	void setOwner(Entity& newOwner) { owner = &newOwner; }

	std::string name;
	Entity* owner;
	Set set;
	int cost{0};
	int rent{0};
	std::array<int, 6> rentTable;
	int houses{0};
	int houseCost{0};
	int mortgage{0};
	bool isMortgaged = false;

private:


};

class Board {
public:

	Board();

	~Board() = default;

	void genBoard(Entity& banker);

	bool checkFullSet(Set set, Entity& target);
	bool checkHouseUpgrade(Set set, Tile& tile);
	bool checkFullHouses(Set set);

	Tile& operator[](int i) {return *board[i];}
	size_t size() {return board.size();}
	std::vector<Tile>& getSet(Set set);
	std::vector<Tile>& getSet(std::string set);

	//Default Banker entity, that every tile will start with
	static Entity banker;
	//Pointer to the default banker
	static Entity* bankerPtr;
	

private:

	std::vector<Tile*> board;
	static std::vector<Tile> special;
	static std::vector<Tile> utility;
	static std::vector<Tile> railroad;
	static std::vector<Tile> red;
	static std::vector<Tile> orange;
	static std::vector<Tile> yellow;
	static std::vector<Tile> green;
	static std::vector<Tile> lightblue;
	static std::vector<Tile> darkblue;
	static std::vector<Tile> magenta;
	static std::vector<Tile> darkpurple;
	

};

