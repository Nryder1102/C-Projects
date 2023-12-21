#include "Monopoly.h"
#include "MWP.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace Monopoly {
	
	int Monopoly::rollDice(){
		int roll = mwp::randBetween(1,6);
		return roll;
	}

	vector<string> getNames(int l) {
		string line;
		int lineFlag = 0;
		ifstream file("Property Names.txt");
		if (file.is_open()) {
			while (getline(file, line)) {
				lineFlag++;
				if (lineFlag == l) {
					break;
				}
			}
			file.close();
		}
		
		vector<string> names = mwp::splitString(line, ':');
		names[0].erase();

		return names;

	}

	//I can use this to randomize tile names for everything if I really wanted to. I was going to, but then I realized I'd rather not, so this'll only be used for railroads and utilities
	void genSet(Set set, vector<Tile>& tiles, Entity& b) {
		vector<string> names = getNames(static_cast<int>(set));
		switch (set) {
			case Set::Utility: {

				for (int i{ 0 }; i < names.size(); i++) {
					string temp = names[i];
					int randName = mwp::randBetween(0, names.size());
					names[i] = names[randName];
					names[randName] = temp;
				}

				for (int i{ 0 }; i < 2; i++) {
					tiles.push_back(Tile(names[i], Set::Utility, 150, &b));
				}

				break;
			}
			case Set::Railroad: {
				for (int i{ 0 }; i < names.size(); i++) {
					string temp = names[i];
					int randName = mwp::randBetween(0, names.size());
					names[i] = names[randName];
					names[randName] = temp;
				}
				for (int i{ 0 }; i < 4; i++) {
					tiles.push_back(Tile(names[i], Set::Railroad, 200, &b));
				}
				break;
			}
		}
	}

}