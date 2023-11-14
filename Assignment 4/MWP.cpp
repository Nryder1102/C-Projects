//Morgan Precanico, 2023
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "MWP.hpp"
using namespace std;

//Simple library of functions I made to make my life easier/more convienent.
//Most are probably un-needed, but they make me happy
namespace mwp
{
    //Return a random integer between the min and max numbers
    int mwp::randBetween(int minNumber,int maxNumber)
    {
        //Generate and assign the random int between the min/max
        int output = minNumber + rand() % maxNumber;
        //Return the output
        return output;
    }

    //Simple function to clear the screen
    void mwp::cls(){
        system("CLS");
    }
    
    //Function to split strings according to a specified token
    vector<string> splitString(string str, char splitter) {
        vector<string> result;
        string current = ""; 
        for(int i = 0; i < str.size(); i++){
            if(str[i] == splitter){
                if(current != ""){
                    result.push_back(current);
                    current = "";
                } 
                continue;
            }
            current += str[i];
        }
        if (current.size() != 0) {
            result.push_back(current);
        }  
        return result;
    }
}