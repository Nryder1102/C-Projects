//Morgan Precanico
//Assignment 1
//Imports
#include <iostream>
#include <iomanip>
#include <cmath>
#include "MWP.cpp"
using namespace std;

//While making this, I realized that VSCode will assign comments above things as sort of their definition when you hover over them, so I might take advantage of this in the future, just making sure this is known in case my pseudocode looks a litle weird. That's just me labeling stuff

//Initialize the various parts of the assignment

void part1();
void part2();
void part3();
void part4();
void part5();
void part6();


//The Big One That Runs Everything Else
void main()
{
    //Make a loop so the user can run multiple parts before quitting
    //Make a boolean to run the big loop that everything else will run out of
    
    //Boolean that makes the overarching program run, while true
    bool runLoop = true;

    //While that's true, keep asking what to run until the user exits
    while(runLoop)
    {
        //Clear screen, so it doesn't become messy
        mwp::cls();

        //Ask which part of the assignment to run
        cout << "Which part of Assignment 1 would you like to run?\n1) Credit Limits\n2) Fundraising Initiative Calulator\n3) Tabular Output\n4) Factorial (Part A)\n5) Modified Compound-Interest Program\n6) Bar-Chart Printing Program\n0) Exit\n> ";

        //Assign the user's choice as an int

        //User's input as an int
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
    }
    

}

//Credit Limits - Done
void part1()
{
    //Make a loop to run as long as the user wants
    //Make a boolean to run that loop

    //Boolean to run the Credit Limits function
    bool creditLoop = true;
    //Introduce the idea of the program, more as a way to make sure it worked
    cout << "Welcome to the Credit Limits Program!";
    //While that boolean is true, run the loop
    while(creditLoop)
    {
        //Clear the screen when the loop begins
        mwp::cls();
        
        //Make an account number integer
        //Account Number
        int accNumber = {0};

        //Ask for an account number, or if the user wants to quit
        cout << "Please enter your Account Number, or '-1' to Quit: ";
        cin >> accNumber;

        //If the input = -1, stop, otherwise, continue
        if(accNumber == -1){
            creditLoop = false;
            break;
        }

        //Make a beginning balance double
        //Beginning Balance
        double startBal = {0};

        //Ask for a balance at the beginning of the month
        cout << "Please enter the Beginning Balance: ";
        cin >> startBal;

        //Make a total charges double
        //Total Charges
        double totalCharges = {0};

        //Ask for a total of all charges this month
        cout << "Please enter the Total Charges: ";
        cin >> totalCharges;

        //Make a monthly credit double
        //Total Monthly Credits Used
        double totalCredits = {0};

        //Ask for how much credit was applied this month
        cout << "Please enter the Total Credits Used: ";
        cin >> totalCredits;

        //Make a credit allowed double
        //Max Credit Allowed
        double creditLimit = {0};

        //Ask for the allowed credit limit
        cout << "Please enter the Credit Limit: ";
        cin >> creditLimit;

        //Make a total balance double
        //Total Balance
        double balance = {0};

        //Calculate the balance
        //Balance = Beginning Balance + Charges - Credits
        balance = startBal + totalCharges - totalCredits;

        //Display the provided information nicely
        //Clear the screen
        mwp::cls();
        //----------------------------------
        //Account Number: #
        //(With two decimal places)
        //Credit Limit:   #
        //(With two decimal places)
        //Balance:        #
        //Print credit limit exceeded if the new balance > credit limit
        //----------------------------------
        cout << "----------------------------------" << endl;
        cout << "Account Number:  " << accNumber << endl;
        cout << "Credit Limit:    " << setprecision(2) << fixed << creditLimit << endl;
        cout << "Balance:         " << setprecision(2) << fixed << balance << endl;
        if(balance > creditLimit){
            cout << "Credit Limit Exceeded" << endl;
        }
        cout << "----------------------------------" << endl;

        //Ask if the user wants to continue or quit
        cout << "Continue? (Enter -1 to Quit): ";

        //String to confirm user's choice
        string confirm = {""};
        cin >> confirm;
        //If user enters -1, quit
        if(confirm == "-1"){
            creditLoop = false;
        }
    }
}

//Fundraising Initiative Calculator - Done
void part2()
{
    //Clear the screen
    mwp::cls();
    //Introduce the idea of the program
    cout << "Welcome to the Fundraising Initiative Calculator!" << endl << endl;

    //Make a loop to run as long as the user wants
    //While true
    while(true)
    {
        //Make a total funds raised double
        //Total Funds Raised
        double total = {0};

        //While true
        while(true){
    
            //Number of Laps
            int laps = {0};

            //Ask the user how many laps the student has run, or to quit
            cout << "How many laps have been completed? (-1 to Quit): ";
            cin >> laps;

            //As long as laps doesn't equal -1, continue
            if(laps == -1){
                break;
            }

            //Lap Rate
            double rate = {0};

            //Ask the user how much money the student has been sponsored per lap
            cout << "What is the contribution rate per lap?: $";
            cin >> rate;

            //If amount of laps <= 40, multiply laps * lap rate, then add to total
            if(laps <= 40){
                //Print the student's contribution
                cout << "Contribution: $" << setprecision(2) << fixed << laps * rate << endl << endl;
                total += laps * rate;
            }
            //Else
            else{
                //Multiply 40 * lap rate + ((laps - 40) * (lap rate + 50%))
                //Print the students contribution
                cout << "Contribution: $" << setprecision(2) << fixed << (40 * rate) + ((laps - 40) * (rate + rate/2)) << endl << endl;
                //Add to total
                total += (40 * rate) + ((laps - 40) * (rate + rate/2));
            }
            
                
        }
            
        //After loop has ended
        //Print total funds raised
        cout << "Total Funds Raised: $" << setprecision(2) << fixed << total << endl << endl;
        //Ask user if they want to run again or quit
        string confirm = {""};
        cout << "Run again? (-1 to Quit): ";
        cin >> confirm;
        //If user quits, break loop
        if(confirm == "-1"){ 
            break;
        }
            
    }
}

//Tabular Output - Done
void part3()
{
    //Clear the screen
    mwp::cls();
    //Introduce the program
    cout << "Welcome to Tabular Output!" << endl;
    while(true){
        //Make a counter that starts at zero
        int counter = {0};
        //Make a loop that'll go until the number the user input
        unsigned int loops = {0};
        cout << "What number to go until?: ";
        cin >> loops;
        cout << "---------------------------------" << endl;
        do{
            //If counter == 0, print the first line
            if(counter == 0){
                cout << "x\t2*x\t4*x\t8*x" << endl;
            //Else print the one that changes
            }else{
                cout << counter << "\t" << counter*2 << "\t" << counter*4 << "\t" << counter*8 << endl;
            }
        
            //counter + 1
            counter++;
        //while counter doesn't equal loops +1
        }while(counter != loops + 1);
        cout << "--------------------------------" << endl;
        //Ask user if they want to end
        cout << "Enter -1 to End: ";
        string confirm = {""};
        cin >> confirm;
        //If the user enters -1, end
        if(confirm == "-1"){
            break;
        }
        //Clear the screen
        mwp::cls();
    }
    
}

//Factorial Output (Part A) - Done
void part4()
{
    //Clear the screen
    mwp::cls();
    //Introduce the idea of the program
    cout << "Welcome to Part A of Factorial Output!" << endl;
    //Make a loop to run as long as the user wants
    while(true){
        //Ask user for a non-negative integer
        int count{0};
        int output{1};
        //Set up a loop that goes for as long as the input number
        cout << "Please enter a non-negative integer: ";
        cin >> count;

        for(int i{1}; i <= count; ++i) {
            output *= i;
        }

        cout << output << endl;
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;
        if(confirm == "-1"){
            mwp::cls();
            break;
        }
    }
}

//Modified Compound-Interest Program - Done
void part5()
{
    //Clear the screen
    mwp::cls();
    //Introduce the idea of the program
    cout << "Welcome to the Modified Compund-Interest Program!" << endl;
    //Make a loop to run as long as the user wants
    while(true){

        //Original Figure 5.6 Program
        //cout << fixed << setprecision(2);

        //double principal{1000.0};
        //double rate{0.05};

        //cout << "Initial principal: " << principal << endl;
        //cout << "    Interest Rate: " << rate << endl;

        //cout << "\nYear" << setw(20) << "Amount on Deposit" << endl;

        //for (unsigned int year{1}; year <= 10; year++){
            
        //    double amount = principal * pow(1.0 + rate, year);
            
        //    cout << setw(4) << year << setw(20) << amount << endl;
        //}

        //Set precision to 2
        cout << fixed << setprecision(2);

        //Make a principal variable
        double principal{0};

        //Ask user for the inital principal
        cout << "Please enter the inital principal : $";
        cin >> principal;

        //Print a header for the table
        cout << "\nYear" << setw(15) << "Deposit:" << setw(10) << "5% Rate" << setw(15) << "6% Rate" << setw(15) << "7% Rate" << setw(15) << "8% Rate" << setw(15) << "9% Rate" << setw(15) << "10% Rate" << endl;

        //For each year, print how much money you'd have at each investment rate, between 5%-10%
        for (unsigned int year{1}; year <= 10; year++){
            
            double amount1 = principal * pow(1.0 + 0.05, year);
            double amount2 = principal * pow(1.0 + 0.06, year);
            double amount3 = principal * pow(1.0 + 0.07, year);
            double amount4 = principal * pow(1.0 + 0.08, year);
            double amount5 = principal * pow(1.0 + 0.09, year);
            double amount6 = principal * pow(1.0 + 0.10, year);
            
            //Print the different amounts of money at different rates
            cout << setw(4) << year << setw(25) << amount1 << setw(15) << amount2 << setw(15) << amount3 << setw(15) << amount4 << setw(15) << amount5 << setw(15) << amount6 << endl;
        }

        //Ask the user if they want to continue
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;
        if(confirm == "-1"){
            mwp::cls();
            break;
        }

    }
}

//Bar Chart Printing Program - Done
void part6()
{
    //Clear the screen
    mwp::cls();
    //Introduce the idea of the program
    cout << "Welcome to the Bar-Chart Printing Program!" << endl;
    //Make a loop to run as long as the user wants
    while(true){

        //Make 5 ints, one for each input

        //Number 1
        int one{0};
        //Number 2
        int two{0};
        //Number 3
        int three{0};
        //Number 4
        int four{0};
        //Number 5
        int five{0};

        

        //Ask for 5 numbers
        cout << "Please enter 5 numbers\nNumber 1: ";
        cin >> one;
        cout << "Number 2: ";
        cin >> two;
        cout << "Number 3: ";
        cin >> three;
        cout << "Number 4: ";
        cin >> four;
        cout << "Number 5: ";
        cin >> five;

        //Make an integer array
        int numbers[5] = {one,two,three,four,five};

        //Make a string array for the bars
        string bars[5];
        
        //For each item in the array, get the number
        for(int i{0}; i < 5; i++){
            //If the number equals something between 1-9, get the corresponding bar and add it to the bars array, otherwise display Not A Valid Number!
            switch(numbers[i]){
                case 1:{
                    bars[i] = "1\n1";
                    break;
                }
                case 2:{
                    bars[i] = "22\n22";
                    break;
                }
                case 3:{
                    bars[i] = "333\n333";
                    break;
                }
                case 4:{
                    bars[i] = "4444\n4444";
                    break;
                }
                case 5:{
                    bars[i] = "55555\n55555";
                    break;
                }
                case 6:{
                    bars[i] = "666666\n666666";
                    break;
                }
                case 7:{
                    bars[i] = "7777777\n7777777";
                    break;
                }
                case 8:{
                    bars[i] = "88888888\n88888888";
                    break;
                }
                case 9:{
                    bars[i] = "999999999\n999999999";
                    break;
                }
                default:{
                    bars[i] = "Not a Valid Number!";
                    break;
                }
            }
        }

        //For each item in the bars array, print the bar
        for(int i{0}; i < 5; i++){
            cout << bars[i] << endl;
        }

        //Ask to continue
        string confirm{""};
        cout << "Continue? (-1 to Exit): ";
        cin >> confirm;
        if(confirm == "-1"){
            mwp::cls();
            break;
        }
    }
}
