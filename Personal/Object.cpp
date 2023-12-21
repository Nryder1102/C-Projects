#include <string>
#include <iostream>
#include "Object.h"
#include "Entity.h"

using namespace std;

Object::Object(){
    setObject("Template", 10);
}

Object::Object(string name, int cost){
    setObject(name, cost);
}

void Object::equip(Player& target){}
void Object::unequip(Player& target){}

void Object::setObject(string name, int cost){
    setName(name);
    setCost(cost);
}
void Object::setName(string newName){name = newName;}
void Object::setCost(int newCost){cost = newCost;}
void Object::setEquippedState(bool newState) {isEquipped = newState;}

string Object::getName(){return name;}
int Object::getCost(){return cost;}
bool Object::getEquippedState() {return isEquipped;}

string Object::toString(){return name;}

Object::~Object(){}
