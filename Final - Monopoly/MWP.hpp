#pragma once
#include <vector>
#include <string>
#include <fstream>


namespace mwp {
	int randBetween(int, int);
	bool probability(int);
	void cls();
	std::vector<std::string> splitString(std::string,char);
	std::string getfile(std::ifstream&);
	void wait(double);
	bool confirm();
	void displayTextOnCenter(const std::string&, int);
}
