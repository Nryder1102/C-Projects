//Morgan Precanico, 2023

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Simple library of functions I made to make my life easier/more convienent.
//Most are probably un-needed, but they make me happy
namespace mwp
{
    //Return a random integer between the min and max numbers
    int randBetween(int minNumber,int maxNumber)
    {
        //Seed the random number generation with the current time
        srand(time(0));
        //Generate and assign the random int between the min/max
        int output = minNumber + rand() % maxNumber;
        //Return the output
        return output;
    }

    //Simple function to clear the screen
    void cls(){
        system("CLS");
    }
}