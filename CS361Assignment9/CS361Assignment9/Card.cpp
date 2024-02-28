/*
Braeden Olney
CS 361
Assignment # 9
Card.cpp
Class for Card setting the methods to use in main for the objects
*/
#include "Card.h"
#include <string>
#include <iostream>

// defalut constructor do nothing
Card::Card() {};

// when the value and suit of the card is passes with parameter set the vars
Card::Card(cardDeck::values changeValue, cardDeck::suits changeSuit) {

    value = changeValue;
    suit = changeSuit;

}

Card::Card(cardDeck::suits changeSuit, cardDeck::values changeValue) {
    value = changeValue;
    suit = changeSuit;
}

// over load card <<
std::ostream& operator << (std::ostream& os, Card& myCard) {

    return myCard.printCard(os);
}




// set value
void Card::setValue(cardDeck::values changeValue) {
    value = changeValue;
}
// set suit
void Card::setSuit(cardDeck::suits changeSuit) {
    suit = changeSuit;
}
// get value
cardDeck::values Card::getValue() {
    return value;
}
// get suit
cardDeck::suits Card::getSuit() {
    return suit;
}
// print card information 
std::ostream& Card::printCard(std::ostream& os) {

    // initialize the value and suit to print
    std::string cardValue = " ";
    int cardSuit;

    // switch to get cards suit
    switch (suit) {
    case cardDeck::suits::Heart:
        cardSuit = 0;
        break;
    case cardDeck::suits::Diamond:
        cardSuit = 1;
        break;
    case cardDeck::suits::Club:
        cardSuit = 2;
        break;
    case cardDeck::suits::Spade:
        cardSuit = 3;
        break;
    case cardDeck::suits::noSuit:
        cardSuit = 4;
        break;
    }

    // get card value
    switch (value) {
    case cardDeck::values::Ace:
        cardValue = "A";
        break;
    case cardDeck::values::Two:
        cardValue = "2";
        break;
    case cardDeck::values::Three:
        cardValue = "3";
        break;
    case cardDeck::values::Four:
        cardValue = "4";
        break;
    case cardDeck::values::Five:
        cardValue = "5";
        break;
    case cardDeck::values::Six:
        cardValue = "6";
        break;
    case cardDeck::values::Seven:
        cardValue = "7";
        break;
    case cardDeck::values::Eight:
        cardValue = "8";
        break;
    case cardDeck::values::Nine:
        cardValue = "9";
        break;
    case cardDeck::values::Ten:
        cardValue = "10";
        break;
    case cardDeck::values::Jack:
        cardValue = "J";
        break;
    case cardDeck::values::Queen:
        cardValue = "Q";
        break;
    case cardDeck::values::King:
        cardValue = "K";
        break;
    case cardDeck::values::Joker:
        cardValue = "Jo";
        break;
    }

    // letter array for the suit of the card
    char letter[] = { 'H','D', 'C', 'S', 'N'};

    // print card
    os << cardValue << letter[cardSuit];

    return os;
}