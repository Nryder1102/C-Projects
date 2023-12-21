//Morgan Precanico
//Assignment 5
#include "MWP.hpp"
#include "DoubleScriptedArray.h"
#include "HugeInteger.h"
#include <iomanip>
#include <iostream>

using namespace std;

typedef void (*AssignmentParts)();

void part1();
void part2();
void part3();
void part4();

int main() {
    srand(static_cast<unsigned int>(time(0)));

    AssignmentParts parts[4] = { part1,part2,part3,part4 };

    while (true) {

        mwp::cls();

        //User's choice
        int choice{ 0 };

        //Ask which part to run
        cout << "Welcome to Assignment 5!\nWhich part would you like to run?\n1) DoubleScriptedArray\n2) HugeInteger Class\n3) \n4) \n0) Exit" << endl;

        //Repeat the choice until a valid option is selected
        while (true) {
            cout << "> ";

            cin >> choice;

            //If choice isn't zero, run corresponding part
            if (choice != 0) {
                //Do some answer validation to make sure you don't look for a spot in the array that doesn't exist
                //If choice -1 is equal or greater than 0, or equal or less than 5, proceed
                if (choice - 1 >= 0 && choice - 1 <= 6) {
                    parts[choice - 1]();
                    //Break back to big loop when the part is done
                    break;
                    //Else print not an option
                }
                else {
                    cout << "Not an Option!" << endl;
                }
                //If choice is 0, exit
            }
            else {
                break;
            }

        }
        //If choice is 0, exit, if not, loop
        if (choice == 0) {
            break;
        }
    }

    return 0;
}

//Double Scripted Array - Done
void part1(){

    //Clear screen
    mwp::cls();

    //Make rows and columns ints
    int rows;
    int cols;

    //Prompt for rows and columns
    cout << "Enter how many Rows: ";
    cin >> rows;
    cout << "Enter how many Cols: ";
    cin >> cols;

    //Make a DoubleScriptedArray with that amount of rows/cols
    DoubleScriptedArray dArray(rows, cols);

    //Clear
    mwp::cls();

    //Ask/Input values for each slot in the array
    cin >> dArray;

    //Clear screen
    mwp::cls();

    //Ask for which spot in the array to grab, re-using the ints from before. Probably bad practice, but it works
    cout << "Enter row to grab: ";
    cin >> rows;
    cout << "Enter col to grab: ";
    cin >> cols;

    //Print the corresponding value 
    cout << "\nValue: " << dArray(rows - 1, cols - 1) << endl;
    
    //Print the array
    cout << endl << "Table: " << endl << dArray;

    //Pause until user wants to continue
    system("pause");

}

//HugeInteger Class
void part2(){

    mwp::cls();

    HugeInteger user;
    HugeInteger test1(100);
    HugeInteger test2(1000000);

    int addNumber = mwp::randBetween(1,250);
    int subNumber = mwp::randBetween(1,250);
    int mulNumber = mwp::randBetween(1,250);
    int divNumber = mwp::randBetween(1,250);

    cout << "Please enter a number: ";
    cin >> user;

    if(user == test1){
        cout << "Your number is equal to: ";
    }else if(user >= test1){
        cout << "Your number is greater than: ";
    }else if(user <= test1){
        cout << "Your number is less than: ";
    }

    cout << test1 << endl;

    if(user == test2){
        cout << "Your number is equal to: ";
    }else if(user >= test2){
        cout << "Your number is greater than: ";
    }else if(user <= test2){
        cout << "Your number is less than: ";
    }

    cout << test2 << endl;

    cout << user << " + " << addNumber << " = " << user + addNumber << endl;
    cout << user << " - " << subNumber << " = " << user - subNumber << endl;
    cout << user << " x " << mulNumber << " = " << user * mulNumber << endl;
    cout << user << " / " << divNumber << " = " << user + divNumber << endl;

    

    system("pause");
}

void part3(){

}

void part4(){

}