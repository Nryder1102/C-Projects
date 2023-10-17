//Morgan Precanico
//Assignment 2
//Imports
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "MWP.cpp"
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
void anyTriangle(int height, char fillingChar);
int power(int base, int exponent);

//Make the main functon
void main(){
    //Welcome the user to assignment two, and ask which part to run
    //Make a loop so the user can keep running things as long as they wish
    bool runLoop = true;

    cout << "Welcome to Assignment 2!" << endl;

    while(runLoop){

        //Ask which part of the assignment to run
        cout << "Which part of Assignment 2 would you like to run?\n1) Parking Charges\n2) Triangle of Asterisks \n3) Triangle of Any Character \n4) Guess-The-Number\n5) Guess-The-Number 2\n6) Recursive Exponentation\n0) Exit\n> ";

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


//Parking Charges - Done
void part1(){
    //Clear the screen
    mwp::cls();

    //Introduce to program
    cout << "Welcome to the Parking Charges Calculator!" << endl;

    //Ask user how many cars there are
    cout << "How many cars are there?: ";

    //Cars int
    int cars{0};
    cin >> cars;

    //Make two arrays as big as there are cars, one for hours, one for charges
    //Had to use vectors as you can't assign an array length using a variable in regular c++
    //The way I understand it, Vectors are to C++ what ArrayLists are to Java?
    vector<double> hours(cars);
    vector<double> charges(cars);

    //For each slot in the array, ask for the hours
    for(int i{1}; i < cars + 1; i++){
        double time{0};
        cout << "How many hours has Car #" << i << " been here?: ";
        cin >> time;
        hours[i-1] = time;
    }

    //For each slot in the hours array, calculate the charges and set the corresponding slot in the charges array
    for(int i{0}; i < cars; i++){
        charges[i] = calculateCharges(hours[i]);
    }

    //Make a total hours double
    double totalHours{0};

    //Make a total charges double
    double totalCharges{0};

    //Add up the respective numbers
    for(int i{0}; i < cars; i++){
        totalHours += hours[i];
        totalCharges += charges[i];
    }
    

    //Print each hour/charge combo nicely in tabular format
    cout << "-----------------------------" << endl;
    cout << "Car" << setw(10) << "Hours" << setw(10) << "Charge" << endl;
    for(int i{1}; i < cars + 1; i++){
        cout << i << setw(12) << fixed << setprecision(1) << hours[i-1] << setw(5) << "$" << fixed << setprecision(2) << charges[i-1] << endl;
    }
    cout << "TOTAL" << setw(8) << fixed << setprecision(1) << totalHours << setw(5) << "$" << fixed << setprecision(2) << totalCharges << endl;
    cout << "-----------------------------" << endl;

    //Ask the user if they want to continue or quit
    string confirm{""};
    cout << "Continue? (-1 to Exit): ";
    cin >> confirm;

    //If they want to quit, clear the screen and restart
    if(confirm == "-1"){
        mwp::cls();
    }
    else{
        part1();
    }
}

//Triangle of Asterisks - Done
void part2(){
    
    //Make a loop so the user can run as many times as wanted
    while(true){
        //Clear the screen
        mwp::cls();

        //Ask user for the height of the triangle
        cout << "Welcome to the Triangle of Asterisks Program!" << endl;
        cout << "Please enter the triangle's height: ";
        
        //Make a height integer
        int height{0};

        cin >> height;

        //Run the triangle function with the specified height
        triangle(height);

        //Ask the user if they want to continue or quit
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;

        //If they want to quit, clear the screen and break the loop
        if(confirm == "-1"){
            mwp::cls();
            break;
        }
    }
}

//Triangle of Any Character - Done
void part3(){
    //Make a loop so the user can run as many times as wanted
    while(true){
        //Clear the screen
        mwp::cls();

        //Ask user for the height of the triangle
        cout << "Welcome to the Triangle of Any Character Program!" << endl;
        cout << "Please enter the triangle's height: ";
        
        //Make a height integer
        int height{0};

        cin >> height;

        //Ask the user for the specified character
        cout << "Please enter the triangle's character: ";

        //Make a character? char
        char fillingChar{'*'};

        cin >> fillingChar;

        //Run the anyTriangle function with the specified height and character
        anyTriangle(height, fillingChar);

        //Ask the user if they want to continue or quit
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;

        //If they want to quit, clear the screen and break the loop
        if(confirm == "-1"){
            mwp::cls();
            break;
        }
    }
    
}

//Guess-The-Number Game - Done
void part4(){
    //Clear the screen
    mwp::cls();

    //Introduce the program
    cout << "Welcome to Guess-The-Number!" << endl;
        
    //Generate a random number between 1-1000
    int number = mwp::randBetween(1,1000);

    //Ask for the user's first guess
    cout << "I have a number between 1 and 1000.\nCan you guess my number?" << endl;
    cout << "Please type your first guess: ";

    //Make a guess int
    int guess{0};

    cin >> guess;

    //Loop until the user guesses right
    while(true){
        //If the guess equals the number
        if(guess == number){
            //Print hey, you did good, and break the loop
            cout << "Excellent! You guessed the number!" << endl;
            break;
        }
        //If the guess is too high, say so, and ask for another guess
        else if(guess > number){
            cout << "Too High. Try Again: ";
            cin >> guess;
        }
        //If the guess is too low, say so, and ask for another guess
        else if(guess < number){
            cout << "Too Low. Try Again: ";
            cin >> guess;
        }
    }

    //Ask if the user wants to play again    
    cout << "Would you like to play again? (y/n): ";
    char confirm{' '};
    cin >> confirm;

    //If confirm doesn't equal y or n, keep waiting for a valid input
    while(confirm != 'y' && confirm != 'n'){
        cin >> confirm;
    }
    //If confirm is y, run again
    if(confirm == 'y'){
        part4();
    }
    
}

//Guess-The-Number Game Modification - Done
void part5(){
//Clear the screen
    mwp::cls();

    //Introduce the program
    cout << "Welcome to Guess-The-Number 2!" << endl;
        
    //Generate a random number between 1-1000
    int number = mwp::randBetween(1,1000);

    //Ask for the user's first guess
    cout << "I have a number between 1 and 1000.\nCan you guess my number?" << endl;
    cout << "Please type your first guess: ";

    //Make a guess int
    int guess{0};

    //Make a number of guesses int
    int guesses{1};

    cin >> guess;

    //Loop until the user guesses right
    while(true){
        //If the guess equals the number
        if(guess == number){
            //Print a different response based on how many guesses the user made
            if(guesses < 10){
                cout << "Either you know the secret or you got lucky! Guesses: " << guesses << endl;
            }
            else if(guesses == 10){
                cout << "Ahah! You know the secret! Guesses: " << guesses << endl;
            }
            else{
                cout << "You should be able to do better! Guesses: " << guesses << endl;
            }
            break;
        }
        //If the guess is too high, say so, and ask for another guess, then add one to the guess total
        else if(guess > number){
            cout << "Too High. Try Again: ";
            cin >> guess;
            guesses++;
        }
        //If the guess is too low, say so, and ask for another guess, then add one to the guess total
        else if(guess < number){
            cout << "Too Low. Try Again: ";
            cin >> guess;
            guesses++;
        }
    }

    //Ask if the user wants to play again    
    cout << "Would you like to play again? (y/n): ";
    char confirm{' '};
    cin >> confirm;

    //If confirm doesn't equal y or n, keep waiting for a valid input
    while(confirm != 'y' && confirm != 'n'){
        cin >> confirm;
    }
    //If confirm is y, run again
    if(confirm == 'y'){
        part5();
    }
    
}

//Recursive Exponentation - Done
void part6(){
    //Make a loop so the user can - blah blah blah
    //Same thing as the other 5 parts
    while(true){
        //Clear the screen
        mwp::cls();

        //Introduce the program
        cout << "Welcome to the Recursive Exponentation Program!" << endl;

        //Ask user for the base and exponent

        //Make a base int
        int base{0};

        //Make an exponent int
        int exponent{0};

        //Make an *unsigned* result int, just in case
        unsigned int result{0};

        cout << "Please enter the base number: ";
        cin >> base;

        cout << "Please enter the exponent: ";
        cin >> exponent;

        //Get the result of the power function
        result = power(base, exponent);

        //Print the result
        cout << "The result is: " << result << endl;

        //Ask the user if they want to continue or quit
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;

        //If they want to quit, clear the screen and break the loop
        if(confirm == "-1"){
            mwp::cls();
            break;
        }
    }
}




//Extra Functions for the Parts


//Calculate Charges per Hour per Car - Done
//+ Base Charge: $20
//+$5 for every hour/part of an hour over three
//EX: 3.1hrs = 4hrs
//+ Base Hours: 3
//+ Max Charge: $50
double calculateCharges(double hours){
    //Make a charge double
    double charge{0};
    //If hours is less than or equal to three, charge = $20
    if(hours <= 3){
        charge = 20;
    }
    //Else, base charge = 20, subtract 3 from hours, round up hours to the nearest whole integer, then for each extra hour, add $5, until you hit $50, which is the max charge
    else{
        charge = 20;
        hours -= 3;
        hours = ceil(hours);
        for(int i{0}; i != hours; i++){
            if(charge + 5 >= 50){
                charge = 50;
            }
            else{
                charge += 5;
            }
        }
    }
    //Return the charge
    return charge;
}

//Create a Triangle of Asterisks to the Desired Height - Done
void triangle(int height){
    //If the height isn't 1, call the function again until it hits one
    if(height != 1){
        triangle(height-1);
    }
    //Once it hits one, start printing asterisks on the same line until it hits the current height
    for(int i{0}; i < height; ++i){
        cout << "*";
    }
    //End the line
    cout << endl;
}

//Create a Triangle of Chosen Character to Desired Height - Done
void anyTriangle(int height, char fillingChar){
    //If the height isn't 1, call the function again until it hits one
    if(height != 1){
        anyTriangle(height-1, fillingChar);
    }
    //Once it hits one, start printing the chosen character on the same line until it hits the current height
    for(int i{0}; i < height; ++i){
        cout << fillingChar;
    }
    //End the line
    cout << endl;
}

//Recursive Exponentation Function - Done
int power(int base, int exponent){
    //If the exponent isn't equal to one, return base * base until exponent equals 1
    if(exponent != 1){
        return base * power(base, exponent-1);
    }
    else{
        //If exponent is one, return just the base
        return base;
    }
    

}