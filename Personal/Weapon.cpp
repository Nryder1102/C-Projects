#include "Object.h"
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon(){
    setObject("No Weapon", 0);
    attackMod = 0;
}

Weapon::Weapon(string name, int attackMod, int cost){
    setWeapon(name, attackMod, cost);
}

void Weapon::setWeapon(string name, int attackMod, int cost){
    setObject(name, cost);
    setAttackMod(attackMod);
}

void Weapon::setAttackMod(int newAttackMod){attackMod = newAttackMod;}
int Weapon::getAttackMod(){return attackMod;}

string Weapon::toString(){return name + " (+" + to_string(attackMod) + ")";}