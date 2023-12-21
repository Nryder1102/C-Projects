#include "Entity.h"
#include "../MWP.hpp"
#include <iostream>

using namespace std;

Entity::Entity(){
    setEntity("Template", 10, 10, 10);
    setDefendState(false);
}

Entity::Entity(string name, int health, int attack, int defense){
    setEntity(name,health,attack,defense);
    setDefendState(false);
}

//Heal Target by 5, up to Target's max health
void Entity::healTarget(Entity& target){
    if(target.health + 5 > target.maxHealth){
        target.setHealth(target.maxHealth);
    }else{
        target.setHealth(target.health + 5);
    }
}

//Damage Target by Entity's Attack
void Entity::attackTarget(Entity& target){
    if(target.isDefended){
        if(attack - (target.defense * 2) > 0){
            if(target.health - (attack - (target.defense * 2)) > 0){
                target.setHealth(target.health - (attack - (target.defense * 2)));  
                target.setDefendState(false);

            }else{
                target.setHealth(0);
                target.setDefendState(false);
            }
        }else{
            cout << "No Damage Done!" << endl;
            target.setDefendState(false);
        }
    }else{
        if(attack - target.defense > 0){
            if(target.health - (attack - target.defense) > 0){
                target.setHealth(target.health - (attack - target.defense));  
            }else{
                target.setHealth(0);
            }
        }else{
            cout << "No Damage Done!" << endl;
        }
    } 
}

//Defend Target Entity (Doubles Target's Defense for the next Attack against them)
void Entity::defendTarget(Entity& target){
    if(target.isDefended == false){
        target.setDefendState(true);
    }else{
        cout << "Target is already being Defended!" << endl;
    }
    
}

//Setters

//Set the entire Entity object
void Entity::setEntity(string newName, int newHealth, int newAttack, int newDefense){
    setName(newName);
    setHealth(newHealth);
    setMaxHealth(newHealth);
    setAttack(newAttack);
    setDefense(newDefense);
}
//Set the Entity's Name
void Entity::setName(string newName){name = newName;}
//Set the Entity's Health
void Entity::setHealth(int newHealth){health = newHealth;}
//Set the Entity's Max Health
void Entity::setMaxHealth(int newMaxHealth){maxHealth = newMaxHealth;}
//Set the Entity's Attack
void Entity::setAttack(int newAttack){attack = newAttack;}
//Set the Entity's Defense
void Entity::setDefense(int newDefense){defense = newDefense;}
//Set if the Entity is being Defended
void Entity::setDefendState(bool newState){isDefended = newState;}

//Getters

//Get Entity's Name
string Entity::getName(){return name;}
//Get Entity's Health
int Entity::getHealth(){return health;}
//Get Entity's Max Health
int Entity::getMaxHealth(){return maxHealth;}
//Get Entity's Attack
int Entity::getAttack(){return attack;}
//Get Entity's Defense
int Entity::getDefense(){return defense;}
//Get if the Entity is being Defended
bool Entity::getDefendState(){return isDefended;}

//Output Entity details as so:
//Name:
//HP: Current/Max
//ATK: 
//DEF: Current (If Defended)
ostream& operator<<(ostream& output, const Entity& target)
{
    string ifDef = "";
    if(target.isDefended){
        ifDef = "(+" + to_string(target.defense) + " Defended)";
    }
    output << "Name: " << target.name << "\nHP:   " << target.health << "/" << target.maxHealth << "\nATK:  " << target.attack << "\nDEF:  " << target.defense << " " << ifDef << endl;
    return output;
}