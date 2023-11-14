#include "Card.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <iostream>
using namespace std;

Card::Card(Face f, Suit s){
    face = f;
    suit = s;
}

const string Card::suits[] = { "Spades", "Clubs", "Hearts", "Diamonds" };
const string Card::faces[] = { "Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace" };

string Card::toString(){
    ostringstream output;
    output << faces[static_cast<int>(face)] + " of " + suits[static_cast<int>(suit)];
    return output.str();
}

Face Card::getFace() {
    return face;
}

Suit Card::getSuit() {
    return suit;
}

