#pragma once
#include <string>

class Player;

class Object{

    //Friends


    public:

        Object();

        Object(std::string name, int cost);

        virtual void equip(Player& target);
        virtual void unequip(Player& target);

        //Getters
        std::string getName();
        int getCost();
        bool getEquippedState();
        
        //Setters
        void setObject(std::string name, int cost);
        void setName(std::string name);
        void setCost(int cost);
        void setEquippedState(bool state);

        virtual std::string toString();

        ~Object();

    protected:
        std::string name;
        int cost;
        bool isEquipped;
};

class Armor : public Object {

    public:
        Armor();
        Armor(std::string name, int healthMod, int cost);

        void equip(Player& target);
        void unequip(Player& target);

        void setArmor(std::string name, int healthMod, int cost);
        void setHealthMod(int healthMod);

        int getHealthMod();

        std::string toString();

    protected:
        int healthMod;
};

class Weapon : public Object {
    public:
        Weapon();
        Weapon(std::string name, int attackMod, int cost);

        void setWeapon(std::string name, int attackMod, int cost);
        void setAttackMod(int attackMod);

        int getAttackMod();

        std::string toString();

    protected:
        int attackMod;
};

class Shield : public Object {
    public:
        Shield();
        Shield(std::string name, int defenseMod, int cost);

        void setShield(std::string name, int defenseMod, int cost);
        void setDefenseMod(int defenseMod);

        int getDefenseMod();

        std::string toString();

    protected:
        int defenseMod;
};