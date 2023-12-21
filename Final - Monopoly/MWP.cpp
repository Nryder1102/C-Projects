//Morgan Precanico, 2023
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
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

    //Simple function that returns true if within the bounds, false if not
    bool mwp::probability(int threshold) {
        return (rand() % 100) < threshold;
    }

    //Simple function to clear the screen
    void mwp::cls(){
        system("CLS");
    }

    //Simple function to make a program pause for a specified amount of time (in seconds)
    void mwp::wait(double seconds) {
        this_thread::sleep_for(chrono::duration<double>(seconds));
    }
    
    //Function to split strings according to a specified token
    vector<string> mwp::splitString(string str, char splitter) {
        vector<string> result;
        string current = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == splitter) {
                if (current != "") {
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

    string mwp::getfile(ifstream& is) {
        string contents;
        // Here is one way to read the whole file
        for (char ch; is.get(ch); contents.push_back(ch)) {}
        return contents;
    }

    //Simple function that checks to see if a yes or no answer if input
    bool mwp::confirm() {
        vector<string> yes = { "yes","yeah","y","Y","sure","confirm" };
        vector<string> no = { "no", "nope", "nah", "n", "N", "-1", "cancel" };
        string choice = "";
        while (true) {
            cout << "> ";
            cin >> choice;
            if (!cin.fail()) {
                for (int i{ 0 }; i < yes.size(); i++) {
                    if (choice == yes[i]) {
                        return true;
                    }
                }
                for (int i{ 0 }; i < no.size(); i++) {
                    if (choice == no[i]) {
                        return false;
                    }
                }
                cout << "Not an Option!" << endl;
            }
            else {
                cout << "Not an Option!" << endl;
            }
        }
        return false;
    }

    //Found this online and thought it would be useful
    void mwp::displayTextOnCenter(const std::string& text, int stringWidth) {
        // Calculate the number of spaces needed to center the text
        int spaces = (stringWidth - text.length()) / 2;

        // Display the text with the appropriate number of spaces
        std::cout << std::setw(spaces) << "" << text << std::endl;
    }
}