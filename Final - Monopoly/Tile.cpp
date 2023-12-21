#include "Board.h"
#include "Entity.h"
#include "MWP.hpp"

using namespace std;

const string Tile::sets[] = {"Special","Utility","Railroad","Red","Orange","Yellow","Green","LightBlue","DarkBlue","Magenta","DarkPurple"};

Tile::Tile(string n, Set s) {
    name = n;
    set = s;
}

Tile::Tile(string n, Set s, Entity* o) {
    name = n;
    set = s;
    owner = o;
}

Tile::Tile(string n, Set s, int c) {
    name = n;
    set = s;
    cost = c;
}

Tile::Tile(string n, Set s, int c, Entity* o) {
    name = n;
    set = s;
    cost = c;
    owner = o;
}

Tile::Tile(string n, Set s, int c, array<int, 6> rTbl) {
    name = n;
    set = s;
    cost = c;
    rentTable = rTbl;
}

Tile::Tile(string n, Set s, int c, array<int, 6> rTbl, int hC, int m, Entity* o) {
    name = n;
    set = s;
    cost = c;
    rentTable = rTbl;
    houseCost = hC;
    mortgage = m;
    owner = o;
}

//Do a specified action on a special space
void Tile::doAction(Entity& target, Board& board, vector<Entity*> players) {
    if (name == "Go") {

    }
    else if (name == "Chance") {
        int card = mwp::randBetween(1, 6);
        switch (card) {
        case 1: {
            //Give the target a GOOJF
            cout << target.getName() << " has recieved a 'Get Out Of Jail Free' card!" << endl;
            target.hasGetOutCard = true;
            break;
        }
        case 2: {
            //Target goes back 3
            cout << target.getName() << " has taken a wrong turn! Go back three spaces!" << endl;
            target.move(board, -3, players);
            break;
        }
        case 3: {
            //Pay 50 to the target
            cout << target.getName() << " has been paid a dividend of $50 by the bank!" << endl;
            target.setMoney(target.getMoney() + 50);
            break;
        }
        case 4: {
            //Put the target directly in jail
            cout << target.getName() << " has been arrested! They go directly to Jail!" << endl;
            target.setSpace(10);
            target.inJail = true;
            break;
        }
        case 5: {
            cout << target.getName() << " has been elected Chairman of the Board! They pay out $50 to every other player!" << endl;
            //For every player that isn't the person who got this while money's over 50, pay 50
            for (int i{ 0 }; i < players.size(); i++) {
                if (players[i] != &target && target.getMoney()-50 > 0) {
                    players[i]->setMoney(players[i]->getMoney() + 50);
                    target.setMoney(target.getMoney() - 50);
                }
                //Else if money goes under 50, bankrupt to the player that's being paid
                else if (target.getMoney()-50 < 0) {
                    target.bankrupt(*players[i], 50);
                    //If they couldn't pay it, break
                    if (target.isBankrupt) {
                        break;
                    }
                }
            }
            break;
        }
        case 6: {
            //Target advances to go
            cout << target.getName() << " has advanced directly to Go! They collect $200!" << endl;
            target.setSpace(0);
            target.setMoney(target.getMoney() + 200);
        }
        }
    }
    else if (name == "Community Chest") {

    }
    else if (name == "Free Parking") {
        cout << target.getName() << " has parked in the coveted Free Parking space, and feels great knowing they won't have to pay for parking today." << endl;
    }
    else if (name == "Go To Jail") {
        cout << target.getName() << "'s past has caught up to them, and they are now being sent to Jail." << endl;
        target.setSpace(10);
        target.inJail = true;
    }
    else if (name == "Income Tax") {
        cout << target.getName() << " is charged $200 in Income Tax." << endl;
        if (target.getMoney() - 200 > 0) {
            target.setMoney(target.getMoney() - 200);
        }
        else {
            target.bankrupt(board.banker, 200);
        }
    }
    else if (name == "Luxury Tax") {
        cout << target.getName() << " is charged $100 in Luxury Tax." << endl;
        if (target.getMoney() - 100 > 0) {
            target.setMoney(target.getMoney() - 100);
        }
        else {
            target.bankrupt(board.banker, 100);
        }
    }
}

//Function to calculate rent for every kind of tile, except utilities
void Tile::calcRent(Board& board){
    if (houses == 0 && owner != board.bankerPtr) {
        //If the player owns the full set, and every property is unimproved, then base rent is doubled
        if (board.checkFullSet(set, *owner)) {
            rent = rentTable[0] * 2;
        }
        //If this tile is a Railroad, rent is 25, 50, 100, or 200 based on owned railroads
        else if(set == Set::Railroad) {
            int flag{-1};
            int rrRent[4] = { 25,50,100,200 };
            for (int i{ 0 }; i < board.getSet(Set::Railroad).size(); i++) {
                if (board.getSet(Set::Railroad).at(i).owner == owner) {
                    flag++;
                }
            }
            if (flag == -1) {
                rent = 0;
            }
            else {
                rent = rrRent[flag];
            }
            
        }
        //If the owner of this tile doesn't the full set, then rent is normal for an unimproved tile
        else {
            rent = rentTable[0];
        }
    }
    //If the tile has been improved, rent is equal to the level of improvement
    else {
        rent = rentTable[houses];
    }
}

//Function to calculate rent for specifically utilities
void Tile::calcRent(Board& board, int roll) {
    
    int setInt = static_cast<int>(set);
    int setFlag = 0;

    //Check if the owner of the tile that's calling this function owns the other tiles in the set
    if (board.checkFullSet(Set::Utility, *owner)) {
        rent = roll * 10;
    }
    else {
        rent = roll * 4;
    }
        
}


ostream& operator<<(ostream& output, const Tile& tile) {
    output << "---------------------------------------------" << endl;
    output << "Property Name: " << tile.name << endl;
    output << "Set:           " << tile.sets[static_cast<int>(tile.set)] << endl;
    output << "Owner:         " << tile.owner->getName() << endl;
    
    if (tile.isMortgaged) {
        output << "Rent:          This property is currently mortgaged." << endl;
    }
    else {
        if (tile.set != Set::Special) {
            if (tile.set != Set::Utility && tile.set != Set::Railroad) {
                if (tile.houses < 5) {
                    output << "Upgrades:      " << tile.houses << " Houses" << endl;
                }
                else {
                    output << "Upgrades:      Hotel" << endl;
                }
                
            }
            output << "Rent:         $" << tile.rent << endl;
        }   
    }
    output << "---------------------------------------------" << endl;

    return output;
}