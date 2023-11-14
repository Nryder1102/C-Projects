//Morgan Precanico
//Assignment 4
#include "Enhanced Time.h"
#include "Enhanced Date.h"
#include "DateAndTime.h"
#include "Card.h"
#include "DeckOfCards.h"
#include "MWP.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

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
        cout << "Welcome to Assignment 4!\nWhich part would you like to run?\n1) Enhanced Time - Ticker Function\n2) Enhanced Date - Next Day\n3) Combined Date And Time\n4) Returning Errors From Time\n5) Card Shuffling and Dealing\n6) Card Shuffling and Dealing 2\n7) PROJECT: Card Shuffling and Dealing\n0) Exit" << endl;

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
            ticker.setHour(stoi(HMS.at(0)));
            ticker.setMinute(stoi(HMS.at(1)));
            ticker.setSecond(stoi(HMS.at(2)));
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

//Enhanced Date - Done
void part2(){
    //Clear Screen
    mwp::cls();
    //Make vector for MonthDayYear
    vector<string> MDY;
    //Make a default date object
    Date date;

    cout << "Welcome to the Enhanced Date Class' NextDay Function!" << endl;

    //Keep asking for a valid date
    while(true) {
        try {
            string currentDate{ "" };
            cout << "Enter Current Date (MM/DD/YYYY): ";
            cin >> currentDate;
            //Split the input string according to the character '/'
            MDY = mwp::splitString(currentDate, '/');
            //Assign the corresponding number to the corresponding type
            date.setMonth(stoi(MDY.at(0)));
            date.setDay(stoi(MDY.at(1)));
            date.setYear(stoi(MDY.at(2)));
            break;
        }
        catch (invalid_argument& error) {
            cout << "Exception Caught: " << error.what() << endl;
        }
        catch (out_of_range) {
            cout << "Not Enough Arguments!" << endl;
        }
    }

    //Ask how many days to tick for
    int days{0};
    cout << "How many days to tick for?\n> ";
    cin >> days;

    string choice{ "" };
    cout << "Display every iteration (Defaults to No)? (y/n): ";
    cin >> choice;
        
    cout << endl;
    
    //I'm displaying the start and end times so I don't have to bloat the screen with each day ticking

    //Display the start time
    cout << "Start: " << date.toString() << endl;

    //Tick for the specified amount of days
    for(int i{0}; i < days; i++){
        date.nextDay();
        //If the user chose to show every iteration, display the date
        if (choice == "y") {
            cout << date.toString() << endl;
        }
    }

    //Display the end date
    cout << "End: " << date.toString() << endl;

    system("pause");
}

//Date And Time - Done
void part3(){
    mwp::cls();

    //Make a vector to split the user input into (HourMinuteSecond)/(MonthDayYear)
    vector<string> HMS;
    vector<string> MDY;
    //Make a DateAndTime object
    DateAndTime dateTime;

    cout << "Welcome to the Combined Date and Time Class!" << endl;

    //Until a time in the correct format is entered, keep asking
    while(true) {
        try {
            string currentTime{ "" };
            cout << "Enter Current Time (HH:MM:SS): ";
            cin >> currentTime;
            //Split the input string according to the character ':'
            HMS = mwp::splitString(currentTime, ':');
            //Assign the corresponding number to the corresponding type
            dateTime.setHour(stoi(HMS.at(0)));
            dateTime.setMinute(stoi(HMS.at(1)));
            dateTime.setSecond(stoi(HMS.at(2)));
            break;
        }
        catch (invalid_argument& error) {
            cout << "Exception Caught: " << error.what() << endl;
        }
        catch (out_of_range) {
            cout << "Not Enough Arguments!" << endl;
        }
    }

    while(true) {
        try {
            string currentDate{ "" };
            cout << "Enter Current Date (MM/DD/YYYY): ";
            cin >> currentDate;
            //Split the input string according to the character '/'
            MDY = mwp::splitString(currentDate, '/');
            //Assign the corresponding number to the corresponding type
            dateTime.setMonth(stoi(MDY.at(0)));
            dateTime.setDay(stoi(MDY.at(1)));
            dateTime.setYear(stoi(MDY.at(2)));
            break;
        }
        catch (invalid_argument& error) {
            cout << "Exception Caught: " << error.what() << endl;
        }
        catch (out_of_range) {
            cout << "Not Enough Arguments!" << endl;
        }
    }

    //Ask how many seconds to tick for
    int seconds{0};
    cout << "How many seconds to tick for?\n> ";
    cin >> seconds;

    cout << endl;
    
    //Display start time/date
    dateTime.displayTime("Start: ");

    //Tick for the specified amount of seconds
    for(int i{0}; i < seconds; i++){
        dateTime.tick();
    }

    //Display the end time/date
    dateTime.displayTime("End: ");

    system("pause");
}

//Returning Errors from Time - Done
void part4(){
    mwp::cls();
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
            ticker.setHour(stoi(HMS.at(0)));
            ticker.setMinute(stoi(HMS.at(1)));
            ticker.setSecond(stoi(HMS.at(2)));
            break;
        }
        //Output what was wrong with the input time, then continue
        catch (invalid_argument& error) {
            cout << "Exception Caught: " << error.what() << endl;
        }
        catch (out_of_range) {
            cout << "Not Enough Arguments!" << endl;
        }
    }

    system("pause");
}

//Deck Of Cards - Done
void part5(){
    //Clear Screen
    mwp::cls();
    
    //Make a deck
    DeckOfCards deck;
    
    try {
        //Shuffle the deck
        deck.shuffle();

        //Set a flag variable for the loop
        int flag{ 1 };

        //For all 52 cards, print the corresponding card in the deck
        for (int i{ 0 }; i < 52; i++) {
            cout << setw(20) << left << deck.dealCard().toString();

            //Every 4 cards, output a newline
            if (flag != 4) {
                flag++;
            }
            else {
                cout << endl;
                flag = 1;
            }
        }
    }
    //Once the out_of_range error is thrown by dealCard(), print "No More Cards!"
    catch (out_of_range) {
        cout << "No More Cards!";
    }

    system("pause");
}

//Deck Of Cards - Get a Hand and Check if you Win Anything - Done
void part6(){
    //Clear screen
    mwp::cls();

    //Make the deck
    DeckOfCards deck;

    //Shuffe the deck
    deck.shuffle();

    //Deal the first 5 cards in the deck as a hand
    vector<Card> hand = deck.dealHand();

    //Check to see if you've got anything in your hand
    int handRank = deck.checkHand(hand);

    system("pause");

}

//Deck Of Cards - Rank Two Hands Against Each Other - Done
void part7(){
    //Clear screen
    mwp::cls();

    //Make the deck
    DeckOfCards deck;

    //Shuffle the deck
    deck.shuffle();

    //Deal two hands of cards
    vector<Card> handOne = deck.dealHand();
    vector<Card> handTwo = deck.dealHand();
    
    //Check if you've got anything in hand one, and return how powerful it is
    cout << "Hand One: " << endl;
    int handOneRank = deck.checkHand(handOne);

    //Do the same for hand two
    cout << "\nHand Two: " << endl;
    int handTwoRank = deck.checkHand(handTwo);
    cout << endl;

    //Output which hand is more powerful, otherwise, print Tie
    if (handOneRank > handTwoRank) {
        cout << "Hand One Wins!" << endl;
    }
    else if (handTwoRank > handOneRank) {
        cout << "Hand Two Wins!" << endl;
    }
    else {
        cout << "Tie!" << endl;
    }

    system("pause");

}