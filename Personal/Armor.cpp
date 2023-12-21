#include "Object.h"
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

Armor::Armor(){
    setObject("No Armor", 0);
    healthMod = 0;
    isEquipped = false;
}

Armor::Armor(string name, int healthMod, int cost){
    setArmor(name, healthMod, cost);
}

void Armor::equip(Player& target){
    target.setMaxHealth(target.getMaxHealth()+healthMod);
    target.setEquippedArmor(*this);
    isEquipped = true;
}

void Armor::unequip(Player& target){
    Armor base;
    target.setMaxHealth(target.getMaxHealth()-healthMod);
    if(target.getHealth() > target.getMaxHealth()){
        target.setHealth(target.getMaxHealth());
    }
    target.setEquippedArmor(base);
    isEquipped = false;
}

void Armor::setArmor(string name, int healthMod, int cost){
    setObject(name, cost);
    setHealthMod(healthMod);
}

void Armor::setHealthMod(int newHealthMod){healthMod = newHealthMod;}
int Armor::getHealthMod(){return healthMod;}

string Armor::toString(){
    string output = name + " (+" + to_string(healthMod) + ")";
    return output;
    }