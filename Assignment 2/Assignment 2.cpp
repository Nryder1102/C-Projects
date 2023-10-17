//Morgan Precanico
//Assignment 2
//Imports
#include <iostream>
#include <iomanip>
#include <cmath>
#include "..\MWP.cpp"
using namespace std;

//I'll probably use this as sorta the skeleton for most multi-part assignments, if I'm being honest. It just works
//Initialize the different parts of the assignment

void part1();
void part2();
void part3();
void part4();
void part5();
void part6();

//Initialize extra functions for the parts

double calculateCharges(double hours);
void triangle(int height);
void anyTriangle(int height, char character);

//Make the main functon
void main(){
    //Welcome the user to assignment two, and ask which part to run
    //Make a loop so the user can keep running things as long as they wish
    bool runLoop = true;

    cout << "Welcome to Assignment 2!" << endl;

    while(runLoop){

        //Ask which part of the assignment to run
        cout << "Which part of Assignment 2 would you like to run?\n1) \n2) \n3) \n4) \n5) \n6) \n0) Exit\n> ";

        //Get user's input as an int
        int choice = {0};

        //Grab user input
        cin >> choice;

        //Run a part based on the user's choice
        switch(choice)
        {
            case 1:{
                part1();
                break;
            }
            case 2:{
                part2();
                break;
            }
            case 3:{
                part3();
                break;
            }
            case 4:{
                part4();
                break;
            }
            case 5:{
                part5();
                break;
            }
            case 6:{
                part6();
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

        //Clear screen, so it doesn't become messy
        mwp::cls();

    }
}


//Parking Charges
void part1(){

}

//Triangle of Asterisks
void part2(){
    
}

//Triangle of Any Character
void part3(){
    
}

//Guess-The-Number Game
void part4(){
    
}

//Guess-The-Number Game Modification
void part5(){
    
}

//Recursive Exponentation
void part6(){
    
}




//Extra Functions for the Parts


//Calculate Charges per Hour per Car
//+ Base Charge: $20
//+$5 for every hour/part of an hour over three
//EX: 3.1hrs = 4hrs
//+ Base Hours: 3
//+ Max Charge: $50
double calculateCharges(double hours){
    //If hours is less than or equal to three, charge = $20
    //if hours is over three, set base charge to $20, subtract 3 from hours
}


//Create a Triangle of Asterisks to the Desired Height
void triangle(int height){

}

//Create a Triangle of Chosen Character to Desired Height
void anyTriangle(int height, char character){
    
}