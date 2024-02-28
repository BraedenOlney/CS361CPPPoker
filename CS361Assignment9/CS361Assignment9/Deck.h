/*
Braeden Olney
CS 361
Assignment # 9
Deck.h
header file of the outline for the class Deck
*/
#pragma once
#include "Card.h"
#include <vector>
class Deck {

public:

    // constructor
    Deck();

    // other members
    Card dealCard();
    int deckSize();

private:
    // deck
    std::vector<Card> deck{};
};