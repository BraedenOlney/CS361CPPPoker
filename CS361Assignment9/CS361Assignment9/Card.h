/*
Braeden Olney
CS 361
Assignment # 9
Card.h
header file of the outline for the class Card
Also has the enumerated types and arrays of suits and values with joker
*/
#pragma once
#include <vector>;
#include <iostream>;
namespace cardDeck {

    // suits
    enum class suits {
        Spade,
        Heart,
        Club,
        Diamond,
        noSuit
    };

    // values
    enum class values {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Joker
    };

    // arrays for suits, values, numValues, and card multiples
    static const suits suitArray[4]{ suits::Spade,suits::Heart,suits::Club,suits::Diamond};
    static const values valuesArray[13]{ values::Ace, values::Two,values::Three, values::Four, values::Five,values::Six,values::Seven,values::Eight,values::Nine,values::Ten,values::Jack,values::Queen,values::King };
    static const int numValuesArray[13]{ 2,3,4,5,6,7,8,9,10,11,12,13,14 };
    static const int highCardMultiples[5]{ 3583, 512, 64, 8 , 1 };

}

class Card {
public:

    //constructors
    Card(cardDeck::values changeValue, cardDeck::suits changeSuit);
    Card(cardDeck::suits changeSuit, cardDeck::values changeValue);
    Card();

    // getters and setters
    // set value
    void setValue(cardDeck::values changeValue);
    // set suit
    void setSuit(cardDeck::suits changeSuit);
    // get value
    cardDeck::values getValue();
    // get suit
    cardDeck::suits getSuit();

    // other members
    // print card information 
    std::ostream& printCard(std::ostream& os);

    // overload  << for card
    friend std::ostream& operator << (std::ostream& os, Card& myCard);

private:

    // cards values and suit
    cardDeck::values value;
    cardDeck::suits suit;
};