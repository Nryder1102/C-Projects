#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

class Board;
class Tile;
class Card;

class Entity {

public:
	

	Entity();
	Entity(std::string);

	virtual ~Entity() = default;

	void listInfo(Entity& target, Board& board);
	void listBoard(std::vector<Entity*>& players);

	virtual void takeTurn(Board& board, std::vector<Entity*>& players);
	virtual void move(Board& board, int spaces, std::vector<Entity*>& players);
	void buy(Tile& tile); //Done
	void sell(Tile& tile, int amount);
	void mortgage(Tile& tile);
	void upgrade(Tile& tile); //Done
	virtual void trade(Entity& target);
	void payRent(Entity& target, int amount); //Done
	virtual void bankrupt(Entity& target, int amount);

	//Setters
	void setName(std::string newName) {name = newName;}
	void setMoney(int newMoney) {money = newMoney;}
	void setSpace(int newSpace) {currentSpace = newSpace;}

	//Getters
	std::string getName() {return name;}
	int getMoney() {return money;}
	int getSpace() { return currentSpace; }
	std::vector<Tile*> getTiles() {return tiles; }


	//Public Variables
	//Used to check if the Entity is in Jail	
	bool inJail = false;
	//Used to check if the Entity is Bankrupt
	bool isBankrupt = false;
	//Used to decide turn order
	int startRoll;
	//Used to cast into the correct child class
	bool isPlayer;
	//Used to check if the entity has get out of jail card
	bool hasGetOutCard = false;

protected:
	std::string name;
	int money;
	int jailFlag;
	int currentSpace;
	std::vector<Tile*> tiles;

};

class Player : public Entity {

public:

	Player(std::string);

	~Player() = default;

	void takeTurn(Board& board, std::vector<Entity*>& players);

	void trade(Entity& target);

private:

};