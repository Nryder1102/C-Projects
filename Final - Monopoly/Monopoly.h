#pragma once
#include <string>
#include <vector>
#include "Board.h"

namespace Monopoly {
	int rollDice();
	std::vector<std::string> getNames(int);
	void genSet(Set, std::vector<Tile>&, Entity&);
}