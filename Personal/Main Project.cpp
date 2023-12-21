#include "Entity.h"
#include "Object.h"
#include <vector>
#include <iostream>


using namespace std;
int main(){
    Player test("Test");
    Entity test2;
    Armor test3;
    test3.setHealthMod(20);
    test2.setAttack(15);
    test2.attackTarget(test);
    
    test.healTarget(test);
    cout << test;
    test.equipItem(test3);
    cout << test;

    test.addToStash(test3);

    for(int i{0}; i < test.getArmorStash().size(); i++){
        cout << test.getArmorStash().at(i).toString() << endl;
    }

    return 0;
}