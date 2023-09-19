//Morgan Precanico, 2023
//A library of functions to make my life easier
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Create a custom namespace to use elsewhere
namespace mwp
{
    //Return a random int between the min and max numbers
    int randBetween(int minNumber,int maxNumber)
    {
        //Seed the random number generation with the current time
        srand(time(0));
        //Generate and assign the random int between the min/max
        int output = minNumber + rand() % maxNumber;
        //Return the output
        return output;
    }

}