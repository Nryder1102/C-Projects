#include <string>

#ifndef CARD_H
#define CARD_H

//Make a suit enum
enum class Suit{
        SPADES,
        CLUBS,
        HEARTS,
        DIAMONDS
    };

//Make a face enum
enum class Face{
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };


class Card{
public:
    //Constructor, that takes a face and a suit enum
    explicit Card(Face f, Suit s);

    //Initialize suits and faces arrays
    const static std::string suits[];
    const static std::string faces[];

    //Make a toString
    std::string toString();

    Face getFace();
    Suit getSuit();

private:
    Face face;
    Suit suit;
};

#endif