#include "DeckOfCards.h"
#include "MWP.hpp"
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

DeckOfCards::DeckOfCards() : currentCard(0){
    //Add a card of each type for each suit to the deck
    for(int i{0}; i < 4; i++){
        for(int j{0}; j < 13; j++){
            deck.push_back(Card(static_cast<Face>(j),static_cast<Suit>(i)));
        }
    }
}

//While there are more cards to deal, allow the dealing of cards, otherwise, throw out of range error
Card DeckOfCards::dealCard(){
    if(moreCards() == true){
        //Deal the current card and increment currentCard
        return deck.at(currentCard++);
    }
    else {
        throw std::out_of_range("No More Cards!");
    }
}

//Return a vector of five card objects
std::vector<Card> DeckOfCards::dealHand() {
    vector<Card> hand;

    //Add 5 cards to the hand vector
    for (int i{ 0 }; i < 5; i++) {
        hand.push_back(dealCard());
    }

    return hand;

}

//Function that checks if your hand won anything, and returns the strength of the hand  
int DeckOfCards::checkHand(std::vector<Card> hand) {
    //Make two arrays that increment based on the corresponding enum from the cards in the hand
    int suits[] = { 0,0,0,0 };
    int faces[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

    //Increment the arrays based on the type of card, as well as print what card it is
    for (int i{ 0 }; i < hand.size(); i++) {
        suits[static_cast<int>(hand[i].getSuit())]++;
        faces[static_cast<int>(hand[i].getFace())]++;
        cout << setw(20) << left << hand[i].toString();
    }

    cout << endl;


    int faceFlag = sizeof(faces) / sizeof(faces[0]);
    int suitFlag = sizeof(suits) / sizeof(suits[0]);
    int twoCount = count(faces, faces + faceFlag, 2);

    //If any of the suits tally equals 5, return highest number and print Flush
    if (count(suits, suits + suitFlag, 5) == 1) {
        cout << "You've got a Flush!" << endl;
        return 6;
    }
    //If TwoCount equals 1, signifying a single pair was found, return lowest number and print Pair
    else if (twoCount == 1) {
        cout << "You've got a Pair!" << endl;
        return 1;
    }
    //Else if twocount equals 2, print two pair and return 2
    else if (twoCount == 2) {
        cout << "You've got a Two Pair!" << endl;
        return 2;
    }
    //Else if there are three of the same faces, print three of a kind and return 3
    else if (count(faces, faces + faceFlag, 3) == 1) {
        cout << "You've got Three of a Kind!" << endl;
        return 3;
    }
    //Else if four of a kind, print so, and return 4
    else if (count(faces, faces + faceFlag, 4) == 1) {
        cout << "You've got Four of a Kind!" << endl;
        return 4;
    }
    //Else if there's a straight, print so, and return 5 (Checks by going 1 = 2-1, 1 = 3-2, 1 = 4-3, 1 = 5-4)
    else if (static_cast<int>(hand[0].getFace()) == static_cast<int>(hand[1].getFace()) - 1 && static_cast<int>(hand[0].getFace()) == static_cast<int>(hand[2].getFace()) - 2 && static_cast<int>(hand[0].getFace()) == static_cast<int>(hand[3].getFace()) - 3 && static_cast<int>(hand[0].getFace()) == static_cast<int>(hand[4].getFace()) - 4) {
        cout << "You've got a Straight!" << endl;
        return 5;
    }
    //Else if you got nothing, return 0
    else {
        cout << "You didn't get anything :(" << endl;
        return 0;
    }
}

//If currentCard is less than 52, there's still more cards
bool DeckOfCards::moreCards(){
    return(currentCard < 52);
}

//Shuffle the cards in the deck
void DeckOfCards::shuffle(){
    //For every card in the deck,
    for(int i{0}; i < deck.size(); i++){
        //Make a temp card object to hold the original values
        Card temp = deck[i];
        //Grab a random index in the array
        int randCard = mwp::randBetween(0,deck.size());
        //Set the first index to the value of the random card
        deck[i] = deck[randCard];
        //Set the random card to the value of the original card
        deck[randCard] = temp;
    }
}