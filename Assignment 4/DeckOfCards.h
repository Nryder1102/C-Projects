#include <vector>
#include "Card.h"

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards{
public:
    DeckOfCards();

    void shuffle();

    bool moreCards();

    Card dealCard();

    std::vector<Card> dealHand();

    int checkHand(std::vector<Card>);

private:
    std::vector<Card> deck;
    int currentCard;
};
#endif
