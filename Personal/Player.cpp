#include "Object.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <iomanip>

using namespace std;

Player::Player(string name){
    setEntity(name, 20, 1, 1);
    level = 0;
    exp = 0;
    expCap = 10;
    gold = 0;
}


void Player::equipItem(int stash, int index){
    switch(stash){
        case 1:{
            armorStash.at(index).equip(*this);
            break;
        }
        case 2:{
            weaponStash.at(index).equip(*this);
            break;
        }
        case 3:{
            shieldStash.at(index).equip(*this);
            break;
        }
    }
    
}

void Player::equipItem(Armor item){item.equip(*this);}
void Player::equipItem(Weapon item){item.equip(*this);}
void Player::equipItem(Shield item){item.equip(*this);}

void Player::addToStash(Armor item){armorStash.push_back(item);}
void Player::addToStash(Weapon item){weaponStash.push_back(item);}
void Player::addToStash(Shield item){shieldStash.push_back(item);}

vector<Armor> Player::getArmorStash(){return armorStash;}

void Player::setEquippedArmor(Armor newArmor){equippedArmor = newArmor;}


//Output Player details as so:
//Name:
//LV: Current (Exp/ExpCap)
//HP: Current/Max
//ATK: 
//DEF: Current (If Defended)
ostream& operator<<(ostream& output, Player& target)
{
    string ifDef = "";
    if(target.isDefended){
        ifDef = "(+" + to_string(target.defense) + " Defended)";
    }
    output << "Name:  " << target.name << 
            "\nLVL:   " << target.level << " (" << target.exp << "/" << target.expCap << ")" << 
            "\n---------------------------------" <<
            "\nHP:    " << target.health << "/" << target.maxHealth << 
            "\nARMR:  " << target.equippedArmor.toString() << 
            "\nATK:   " << target.attack << 
            "\nWEAP:  " << target.equippedWeapon.toString() << 
            "\nDEF:   " << target.defense << " " << ifDef << 
            "\nSHLD:  " << target.equippedShield.toString() << 
            "\n---------------------------------\n";
    return output;
}