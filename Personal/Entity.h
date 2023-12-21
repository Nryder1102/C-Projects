#pragma once
#include <string>
#include <ostream>
#include <vector>
#include "Object.h"

class Entity {

    //Friends
    friend std::ostream& operator<<(std::ostream& output, const Entity& target);

    public:

        Entity();
        Entity(std::string name, int health, int attack, int defense);

        void healTarget(Entity& target);
        void attackTarget(Entity& target);
        void defendTarget(Entity& target);

        //Getters
        std::string getName();
        int getHealth();
        int getMaxHealth();
        int getAttack();
        int getDefense();
        bool getDefendState();

        //Setters
        void setEntity(std::string name, int newHealth, int newAttack, int newDefense);
        void setName(std::string name);
        void setHealth(int newHealth);
        void setMaxHealth(int newMaxHealth);
        void setAttack(int newAttack);
        void setDefense(int newDefense);
        void setDefendState(bool newState);

    protected:
        //Entity's Name
        std::string name;
        //Entity's Health
        int health;
        //Entity's Max Health
        int maxHealth;
        //Entity's Attack
        int attack;
        //Entity's Defense
        int defense;
        //Flag for if the Entity is Defended
        bool isDefended;

};

class Player : public Entity {

    //Friends
    friend std::ostream& operator<<(std::ostream& output, Player& target);

    public:

        //Player Constructor
        Player(std::string name);

        void equipItem(int stash, int index);
        void equipItem(Armor item);
        void equipItem(Weapon item);
        void equipItem(Shield item);

        void addToStash(Armor item);
        void addToStash(Weapon item);
        void addToStash(Shield item);

        void setEquippedArmor(Armor newArmor);

        std::vector<Armor> getArmorStash();


    protected:

        //Player's Level
        int level;
        //Player's Exp
        int exp;
        //Player's Exp Cap
        int expCap;

        //Player's Inventory
        //Have to do it like this, because if I just do a vector of Objects, I'll lose data

        //Armor Stash
        std::vector<Armor> armorStash;
        Armor equippedArmor;
        //Weapon Stash
        std::vector<Weapon> weaponStash;
        Weapon equippedWeapon;
        //Shield Stash
        std::vector<Shield> shieldStash;
        Shield equippedShield;

        int gold;
};

class Enemy : public Entity {

    Enemy();

};