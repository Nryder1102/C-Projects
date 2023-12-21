#include "Object.h"
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

Shield::Shield(){
    setObject("No Shield", 0);
    defenseMod = 0;
}

Shield::Shield(string name, int defenseMod, int cost){
    setShield(name, defenseMod, cost);
}

void Shield::setShield(string name, int defenseMod, int cost){
    setObject(name, cost);
    setDefenseMod(defenseMod);
}

void Shield::setDefenseMod(int newDefenseMod){defenseMod = newDefenseMod;}
int Shield::getDefenseMod(){return defenseMod;}

string Shield::toString(){return name + " (+" + to_string(defenseMod) + ")";}