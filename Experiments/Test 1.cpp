//Morgan Precanico, 2023
//Just a file where I mess around to figure out how C++ works
#define _GLIBCXX_USE_C99 1
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iomanip>
#include <utility>
#include "../MWP.cpp"
using namespace std;

//Define a bunch of functions here so I can use them higher up in the file
void testLab();
int lab1();
double lab2();
string lab3();
int lab4(int);
void lab5();
void lab6();
void lab7();

//The mandatory main function
int main()
{
	testLab();

	//mwp::test();
	return 0;
}

//Where everything happens
void testLab()
{
	
	lab7();
}

int lab1()
{
	int input{0};
	cout << "Please input an integer!\n"
		 << "> ";
	cin >> input;
	return input;
}

double lab2()
{
	double input{0};
	cout << "Please input a double!\n"
		 << "> ";
	cin >> input;
	return input;
}

string lab3()
{
	string input{""};
	cout << "Please input a string!\n"
		 << "> ";
	cin >> input;
	return input;
}

int lab4(int x)
{
	int sum{0};
	int input{0};
	cout << "Please input an integer!\n"
		 << "> ";
	cin >> input;
	sum = input + x;
	return sum;
}

//Grab a user's name, then age, then randomize a number between one and one hundred
void lab5()
{
	//Initialize variables
	string firstName{""};
	string lastName{""};
	int age{0};
	
	//Initialize & assign the randomly generated max age
	unsigned int maxAge{static_cast<unsigned int>(mwp::randBetween(1,100))};
	//cout << maxAge << endl;

	//Ask the user for their first and last name, as well as age
	cout << "Enter your name: ";
	cin >> firstName >> lastName;
	cout << "Enter your current age: ";
	cin >> age;
	
	//If maxAge - age is less or equal to zero, then just say you don't have much time
	if(maxAge - age <= 0) 
	{
		cout << "Sorry, " << firstName << " " << lastName << ", you don't have much time!";
	//If the number's positive, output a message
	}
	else
	{
		//Randomly choose between two different messages to output
		if(mwp::randBetween(1,2) == 2) 
		{
			cout << "Congratulations, " << firstName << " " << lastName << "! You've got exactly: " << maxAge - age << " years left to live!";
		}
		else
		{
			cout << "Congrats, " << firstName << " " << lastName << "! You'll make it to " << maxAge << "!";
		}
	}
}

//Program that has the user enter words until they want to exit, displays the number of letters in the word, and tells you if it's even or odd, and then gives you the average of all the words entered
void lab6()
{
	//initialize variables
	//loop flag
	bool loopFlag = true;
	//current word
	string word{""};
	//letter total
	int total{0};
	//word count
	int wordCount{0};
	//start program with a loop, that keeps going until the user stops it
	//In this case, check if the string contains "-1"
	while (loopFlag)
	{
		//display prompt to ask user to input word or exit program
		cout << "Enter a word, or type -1 to exit: ";
		//grab current word from the prompt
		cin >> word;

		//Check if the word contains -1
		if(word != "-1")
		{
			//If the word isn't -1
			//Initialize another variable for even/odd
			string numType{""};
	
			//Count the amount of letters in the word
			//If length to modulo 2 == 0, set even, otherwise, set odd
			if(word.length() % 2 == 0){numType = "Even";}else{numType = "Odd";}

			//Display the word, amount of letters, and if even or odd
			cout << word << " | Letters: " << word.length() << " | " << numType << endl;
			//Add to total
			total += word.length();
			//Add to word count
			wordCount++;
		//If the word is -1, break the loop
		}else{
			loopFlag = false;
		}
	}
	//Display total amount of letters
	cout << "--------------\nTotal Amount of Letters: " << total << endl;
	//Display the average amount of letters
	cout << "Average Amount of Letters: " << total / wordCount << "\n--------------";
}

void lab7(){
	

}
