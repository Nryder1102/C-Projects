//Morgan Precanico
//Assignment 1
//Imports
#include <iostream>
#include "MWP.cpp"
using namespace std;

//Initialize the parts
void part1();
void part2();
void part3();
void part4();
void part5();
void part6();
void part7();

void main()
{
    //Make a loop so the user can run multiple parts before quitting
    bool runLoop = true;
    while(runLoop)
    {
        //Clear screen, so it doesn't become messy
        system("CLS");
        //Ask which part of the assignment to run
        cout << "Which part of Assignment 1 would you like to run?\n1) Credit Limits\n2) Fundraising Initiative Calulator\n3) Tabular Output\n4) Factorial (Part A)\n5) \n6)\n7)\n0) Exit\n> ";
        //Assign the choice as an int
        int choice = {0};
        //Grab user input
        cin >> choice;

        //Run a different part of the assignment depending on choice
        switch(choice)
        {
            case 1:{
                part1();
                break;
            }

            //If the user enters 0, exit
            case 0:{
                cout << "Exiting!";
                runLoop = false;
            }
            //If the user enters something unexpected, loop again
            default:{}
        }
    }
    

}

void part1()
{
    cout << "Hello World";
}