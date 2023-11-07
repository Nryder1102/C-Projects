//Morgan Precanico
//Assignment 4
#include "Enhanced Time.h"
#include "Enhanced Date.h"
#include "DateAndTime.h"
#include "Card.h"
#include "DeckOfCards.h"
#include "../MWP.cpp"
#include <iostream>
#include <ctime>

using namespace std;

typedef void (*AssignmentParts)();

void part1();
void part2();
void part3();
void part4();
void part5();
void part6();
void part7();



int main(){


    srand(static_cast<unsigned int>(time(0)));

    AssignmentParts parts[7] = {part1,part2,part3,part4,part5,part6,part7};

    while(true){

        mwp::cls();

        //User's choice
        int choice{0};

        //Ask which part to run
        cout << "Welcome to Assignment 4!\nWhich part would you like to run?\n1) Enhanced Time - Ticker Function\n2) Enhanced Date\n3) Combined Date And Time\n4) Returning Errors From Time\n5) Card Shuffling and Dealing\n6) Card Shuffling and Dealing 2\n7) PROJECT: Card Shuffling and Dealing\n0) Exit" << endl;

        //Repeat the choice until a valid option is selected
        while(true){
            cout << "> ";

            cin >> choice;

            //If choice isn't zero, run corresponding part
            if(choice != 0){
                //Do some answer validation to make sure you don't look for a spot in the array that doesn't exist
                //If choice -1 is equal or greater than 0, or equal or less than 5, proceed
                if(choice-1 >= 0 && choice-1 <= 6){
                    parts[choice-1]();
                    //Break back to big loop when the part is done
                    break;
                //Else print not an option
                }else{
                    cout << "Not an Option!" << endl;
                }
            //If choice is 0, exit
            }else{
                break;
            }
            
        }
        //If choice is 0, exit, if not, loop
        if(choice == 0){
            break;
        }
    }
}

//Enhanced Time - Tick Function - Done
void part1(){

    mwp::cls();

    cout << "Welcome to the Enhanced Time Class' Ticker Function!" << endl;
       
    //Make a vector to split the user input into (HourMinuteSecond)
    vector<string> HMS;
    //Make a time object
    Time ticker;

    //Until a time in the correct format is entered, keep asking
    while(true) {
        try {
            string currentTime{ "" };
            cout << "Enter Current Time (HH:MM:SS): ";
            cin >> currentTime;
            //Split the input string according to the character ':'
            HMS = mwp::splitString(currentTime, ':');
            //Assign the corresponding number to the corresponding type
            ticker.setHour(stoi(HMS[0]));
            ticker.setMinute(stoi(HMS[1]));
            ticker.setSecond(stoi(HMS[2]));
            break;
        }
        catch (...) {
            cout << "Not a valid time!" << endl;
        }
    }
    
    //Ask how many seconds to tick for
    int seconds{0};
    cout << "How many seconds to tick for?\n> ";
    cin >> seconds;

    string choice{ "" };
    cout << "Display every iteration (Defaults to No)? (y/n): ";
    cin >> choice;
        
    cout << endl;
    
    //I'm displaying the start and end times so I don't have to bloat the screen with each second ticking

    //Display the start time
    ticker.displayTime("Start: ");

    //Tick for the specified amount of seconds
    for(int i{0}; i < seconds; i++){
        ticker.tick();
        //If the user chose to show every iteration, display the time
        if (choice == "y") {
            ticker.displayTime();
        }
    }

    //Display the end time
    ticker.displayTime("End: ");

    system("pause");
}

void part2(){
    int month{0};
    int day{0};
    int year{0};
    cin >> month;
    cin >> day;
    cin >> year;
    Date date(month,day,year);
    system("pause");
}

void part3(){
    
}

void part4(){
    
}

void part5(){
    
}

void part6(){
    
}

void part7(){
    
}