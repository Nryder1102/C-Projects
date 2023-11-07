//Morgan Precanico
//Assignment 3
//Imports
#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include "MWP.cpp"
#include "fig06_09.cpp"
using namespace std;

//Make a type definition so I can assign the function calls to an array
//I think this works by typedef <type> <alias>, *Pointer() is what this turns out to mean, I think?
typedef void (*AssignmentParts)();

void part1();
void part2();
void part3();
void part4();
void part5();
void part6();
bool testPalindrome(string input, int currentChar);


int main(){

    srand(static_cast<unsigned int>(time(0)));

    //Add the addresses of the functions to the array
    //I think this work by when called, it acts like *AssignmentParts parts[index]()?
    AssignmentParts parts[6] = {part1,part2,part3,part4,part5,part6};

    while(true){

        mwp::cls();

        //User's choice
        int choice{0};

        //Ask which part to run
        cout << "Welcome to Assignment 3!\nWhich part would you like to run?\n1) One Dimensional Array Questions\n2) Dice Rolling\n3) Craps Game Modification\n4) Sales Summary\n5) The Sieve of Eratosthenes\n6) Palindromes\n0) Exit" << endl;

        //Repeat the choice until a valid option is selected
        while(true){
            cout << "> ";

            cin >> choice;

            //If choice isn't zero, run corresponding part
            if(choice != 0){
                //Do some answer validation to make sure you don't look for a spot in the array that doesn't exist
                //If choice -1 is equal or greater than 0, or equal or less than 5, proceed
                if(choice-1 >= 0 && choice-1 <= 5){
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

//One Dimensional Array Questions - Done
void part1(){

    mwp::cls();

    cout << "Welcome to One Dimensional Array Questions!" << endl;

    //A)
    //Make an integer array, with a size of 10, named counts
    array<int,10> counts;
    //For each element in counts, set it to 0
    for(size_t i{0}; i < counts.size(); ++i){
        counts[i] = 0;
    }


    //B)
    //Make an integer array, with a size of 15, named bonus
    array<int,15> bonus;
    //For each element in bonus, set it to a random number between 1-10
    for(size_t i{0}; i < bonus.size(); ++i){
        bonus[i] = mwp::randBetween(1,10);
    }
    //For each element in bonus, add 
    for(size_t i{0}; i < bonus.size(); ++i){
        bonus[i] += 1;
    }


    //C)
    //Make a double array, with a size of 12, named monthlyTemperatures
    array<double,12> monthlyTemperatures;
    //For each element in monthlyTemperatures, ask for user input and set it to the current element
    for(size_t i{0}; i < monthlyTemperatures.size(); ++i){
        cout << "Please enter a double: ";
        double input{0};
        cin >> input;
        monthlyTemperatures[i] = input;
    }


    //D)
    //Print "Best Scores"
    cout << "\n\nBest Scores:\n----------------" << endl;
    //Make an integer array, with a size of 5, named bestScores
    array<int,5> bestScores{100,98,85,96,89};
    //For each element in bestScores, print both which score, and the score itself in column format
    for(size_t i{0}; i < bestScores.size(); ++i){
        cout << "Score " << i+1 << ":" << setw(8) << bestScores[i] << endl;
    }
    cout << "----------------" << endl;
    //Pause until the user presses something, so the screen doesn't clear
    system("pause");

}

//Dice Rolling - Done
void part2(){
    mwp::cls();
    cout << "Welcome to Dice Rolling!\nThis program will roll two dice 36,000,000 times, and tally the results!" << endl;

    //Make an integer array with 11 spots
    array<int,11> results;

    int counter{0};

    for(size_t i{0}; i < results.size(); i++){
        results[i] = 0;
    }

    //For 36000000, generate a random number between 1-6 twice, then add them together
    for(int i{0}; i < 36000000; i++){

        int diceOne = mwp::randBetween(1,6);
        int diceTwo = mwp::randBetween(1,6);
        int sum = diceOne + diceTwo;

        //As the sum can only ever be between 2-12, there are only 11 possible sums, so set add one to the corresponding slot in the array
        results[sum-2] += 1;

        counter++;
    }

    //Print everything nicely
    cout << "----------------------" << endl;
    cout << "Sum" << setw(4) << "|" << setw(15)  << "Times Rolled" << endl;
    cout << "----------------------" << endl;

    for(size_t i{0}; i < results.size(); ++i){
        if(i >= 8){
            cout << i+2 << setw(5) << "|" << setw(15) << results[i] << endl;
        }else{
            cout << i+2 << setw(6) << "|" << setw(15) << results[i] << endl;
        }
        
    }

    cout << "----------------------" << endl;

    system("pause");

}

//Craps Game Modification - Done
void part3(){

    mwp::cls();

    //Make arrays of 21 slots to tally what roll the player wins or loses on
    array<int,21> gamesWon;
    array<int,21> gamesLost;
    //Make everything 0
    for(size_t i{0}; i < gamesWon.size(); i++){
        gamesWon[i] = 0;
        gamesLost[i] = 0;
    }
    //Make a rolls, average, and whether you won or not variable
    int rolls{0};
    int average{0};
    bool won;

    //Run 1000 times
    for(int i{0}; i < 1000; i++){
        rolls = 0;

        //I modified the provided code to take a pointer which will increment the rolls variable, as well as return true if the player won, and false if the player lost
        won = fig06_09::main(&rolls);

        //If the player won, and the number of rolls is less than or equal to 20, then tally it into the according slot
        if(won && rolls <= 20){
            gamesWon[rolls-1] += 1;
        //If the amount of rolls is 21 or over, just add to the last slot in the array
        }else if(won && rolls > 20){
            gamesWon[20] += 1;
        //Same thing as before but if the player lost
        }else if(!won && rolls <= 20){
            gamesLost[rolls-1] += 1;
        }else{
            gamesLost[20] += 1;
        }

        //Add the amount of rolls from this game to the average sum
        average += rolls;
    }

    //Print everything nicely
    cout << "Results for 1000 games of Craps:" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Roll      : | ";
    //Print the roll indices as column headers
    for(int i{0}; i < 21; i++){
        if(i+1 != 21){
            cout << setw(3) << i+1 << setw(3) << "| " << setw(3);
        }else{
            cout << setw(3) << "21+ |";
        }
        
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //Print out how many games won according to how many rolls there were
    cout << "Games Won : | ";
    for(int i{0}; i < 21; i++){
        cout << setw(3) << gamesWon[i] << setw(3) << "| " << setw(3);
    }
    cout << endl;
    //Print out how many games lost according to how many rolls there were
    cout << "Games Lost: | ";
    for(int i{0}; i < 21; i++){
        cout << setw(3) << gamesLost[i] << setw(3) << "| " << setw(3);
    }
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //Add up all times player won, then divide
    double wonSum{0};
    for(int i{0}; i < 21; i++){
        wonSum += gamesWon[i];
    }

    cout << "Win Chance:       | " << (wonSum / 1000)*100 << "%" << endl;
    cout << "Average Length:   | " << average / 1000 << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Based on the numbers, chances of winning drop fast the more rolls there are." << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    system("pause");
}

//Sales Summary - Done
void part4(){

    mwp::cls();

    //Make productSales/salesPerson variables to initialize the array with, for better readability
    static const size_t productSales{5};
    static const size_t salesPerson{4};

    //Make an array of productSales arrays, named sales
    array<array<double,productSales>,salesPerson> sales{0.0, 0.0, 0.0, 0.0, 0.0};

    //Product 1 Price: $50.50 - 10
    //Product 2 Price: $129.99 - 5
    //Product 3 Price: $10.00 - 15
    //Product 4 Price: $29.99 - 10
    //Product 5 Price: $500.00 - 2

    //Modify each salesPerson entry in the array
    for(size_t i{0}; i < sales.size(); i++){
        //Generate product information, per day, for a month
        for(int j{0}; j < 30; j++){
            //Generate how many slips this salesperson sent in this day
            int slips = mwp::randBetween(0,5);
            //Make an array to note which products the slips were for
            array<bool,5> slipList{false,false,false,false,false};
            //Make a count flag
            int count{0};
            //As long as slips isn't 0, do a bunch of stuff
            if(slips != 0){
                //While the loop isn't broken, generate an index and check if it's false or true
                while(true){
                    int element = mwp::randBetween(1,5) - 1;
                    //If the element is false, set it to true, and increment count by one
                    if(slipList[element] == false){
                        slipList[element] = true;
                        count++;
                    }
                    //If the count equals the number of slips, break the loop
                    if(count == slips){
                        break;
                    }
                }
                
                //For each true element in the product list, generate a random number of product sold based on the index
                for(size_t k{0}; k < slipList.size(); k++){
                    if(slipList[k]){
                        switch(k+1){
                            case 1: {
                                sales[i][k] += mwp::randBetween(1,10) * 50.50;
                                break;
                            }
                            case 2: {
                                sales[i][k] += mwp::randBetween(1,5) * 129.99;
                                break;
                            }
                            case 3: {
                                sales[i][k] += mwp::randBetween(1,15) * 10.00;
                                break;
                            }
                            case 4: {
                                sales[i][k] += mwp::randBetween(1,10) * 29.99;
                                break;
                            }
                            case 5: {
                                sales[i][k] += mwp::randBetween(1,2) * 500.00;
                                break;
                            }
                        }
                    }
                }
            }
        }
    } 

    //Print everything in tabular format
    cout << "Salesperson:   |";
    //Print each saleperson id
    for(size_t i{0}; i < sales.size(); i++){
        cout << setw(6) << i+1 << setw(6) << "|";
    }
    cout << "     Total" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //Print the amount each salesperson made per product, then print the total across all salespeople
    for(size_t i{0}; i < 5; i++){
        cout << "Product #" << i+1 << ":    | ";
        for(size_t j{0}; j < sales.size(); j++){
            cout << fixed << setprecision(2);
            cout << setw(9) << sales[j][i] << " | ";
        }
        cout << setw(9) << sales[0][i] + sales[1][i] + sales[2][i] + sales[3][i];
        cout << endl;
    }
        
    cout << "--------------------------------------------------------------------------" << endl;

    //Calculate and print the total of everything across the board
    cout << "Total:         | ";

    for(size_t i{0}; i < 4; i++){
        cout << setw(9) << sales[i][0] + sales[i][1] + sales[i][2] + sales[i][3] + sales[i][4] << " | ";
    }

    //Get the Big Total
    double sum{0};
    for(size_t i{0}; i < sales.size(); i++){
        for(size_t k{0}; k < sales[i].size(); k++){
            sum += sales[i][k];
        }
    }
    //Print it
    cout << setw(9) << sum << endl;


    system("pause");
}

//The Sieve of Eratosthenes - Done, with error
void part5(){
    
    mwp::cls();

    cout << "Welcome to the Sieve of Eratosthenes!\nThis program uses a specific algorithim to get you every prime number between 1-1000!" << endl;

    //Make an array with 1000 slots
    array<int,1000> sieve;

    //Set everything in sieve to 1
    for(int i{0}; i < 1000; i++){
        sieve[i] = 1;
    }


    //Start from 2, if i*i is less than or equal to 1000, step up
    for(int i{2}; i * i <= 1000; i++){
        //If i is equal to 1, check the rest of the array and mark every multiple as 0
        if(sieve[i] == 1){
            //Start at the multiple, rather than the beginning number, so if the originator is 2, start at 4, and as long as j is less than or equal to 1000, step j up by i 
            //EX: i = 2, so j starts at 4, as long as it's less than 1000, step up by 2
            for(int j{i*i}; j <= 1000; j+=i){
                //Mark the multiple as 0
                //This throws a stack overflow error for some reason???
                //I'm not really sure why
                //I wanted to ask in class, but ended up not having time, and I can't figure out how to fix it, so I'm just going to leave it for now
                sieve[j] = 0;
            }
        }
    }

    //Print the subscript of every element in the array that still equals 1
    cout << "Prime Numbers Between 1 - 1000:" << endl;

    for(size_t i{0}; i < sieve.size(); i++){
        if(sieve[i] == 1){
            cout << i << " ";
        }
    }
    cout << "\n";
    system("pause");
}

//Palindromes - Done
void part6(){
    
    mwp::cls();
    //Introduce the program
    cout << "Welcome to the Palindromes Program!\nThis program will check to see if a user input phrase is a palindrome!" << endl;

    //Run until user says otherwise
    while(true){
        string phrase{""};
        //Ask user for a phrase to check
        cout << "Please enter a phrase: ";
        cin >> phrase;

        //Run testPalindrome on the phrase, and if it returns true, print that it is a palindrome, otherwise, print it's not
        if(testPalindrome(phrase,0)){
            cout << phrase << " is a Palindrome!" << endl;
        }else{
            cout << phrase << " is not a Palindrome!" << endl;
        }


        //Ask user if they wish to continue
        string confirm;
        cout << "Continue?(-1 to Exit)\n> ";
        cin >> confirm;
        if(confirm == "-1"){
            break;
        }
    }
}


//Test Palindrome function - Done
bool testPalindrome(string input, int currentChar){
    //If the currentChar of this iteration is bigger than half of the string length, that means it is indeed a palindrome, as it hasn't been able to return false
    if(currentChar > input.size()/2){
       return true;
    }
    //If this doesn't return false, it keeps testing further and further characters to see if they're equal until it either finds one that's different, or hits the base case and fully returns true 
    return input[currentChar] == input[input.size()-currentChar-1] && testPalindrome(input,currentChar+1);
}