/*
Braeden Olney
CS 361
Assignment # 9
Hand.h
header file of the outline for the class hand
and operator overide
*/
#pragma once
#include "Card.h"
#include <vector>;

class Hand {

public:

    // constructor
    Hand();

    // other members
    void addCardToHand(Card cardToHand);
    std::ostream& printHand(std::ostream& os);
    int handSize();
    void discard(int index, Card newCard);
    bool Ace();
    int getHandValue();
    // overload  << for hand
    friend std::ostream& operator << (std::ostream& os, Hand& myCard);
    // overload  <=> for hand
    //auto operator<=>(Hand&);
    std::strong_ordering operator<=>(Hand& hand1);

private:

    // private property

    std::vector<Card> hand{};
    std::vector<int> getHandSuits();
    std::vector<int> getHandValues();
    bool hasKing();
    bool hasJoker();
    bool hasQueen();
    int getHighCard(std::vector<int> handValues);
    bool isFlush(std::vector<int> handSuits);
    bool isStraight(std::vector<int> handValues);
    bool isFourOfKind(std::vector<int> handValues);
    bool isThreeOfKind(std::vector<int> handValues);
    bool isTwoPair(std::vector<int> handValues);
    bool isPair(std::vector<int> handValues);
};