/*
Braeden Olney
CS 361
Assignment # 9
Hand.cpp
Same as Assignment 8 but adds joker hand values
*/
#include "Hand.h"
#include "Card.h"
#include <iostream>;

// defalut constructor do nothing
Hand::Hand() {

}

// Hand constructor with parameter put card into hand
void Hand::addCardToHand(Card cardToHand) {

    hand.push_back(cardToHand);

}

std::ostream& operator << (std::ostream& os, Hand& myHand) {

    // Print Hand
    // return out stirng
    return myHand.printHand(os);
}


// print the hand
std::ostream& Hand::printHand(std::ostream& os) {
    // print each card in hand
    os << "These cards are in the hand: ";
    //for the current card number
    int cardCounter = 1;
    for (Card cardItt : hand) {
        os << std::endl << "Card " << cardCounter << " " << cardItt;
        cardCounter++;
        //cardItt.printCard(os);
        os << " ";
    }
    return os;
}

// return hand size
int Hand::handSize() {

    return hand.size();

}

// change the card in the index with the passed card
void Hand::discard(int index, Card newCard) {

    Hand::hand[index] = newCard;

}

std::vector<int> Hand::getHandValues() {

    //indexes: Two = 0, ... , Ace = 12
    std::vector<int> returnVector{ 0,0,0,0,0,0,0,0,0,0,0,0,0 };

    // for all the cards in the hand fill the vector
    for (Card currCard : Hand::hand) {
        switch (currCard.getValue()) {
        case cardDeck::values::Ace:
            returnVector[12]++;
            break;
        case cardDeck::values::Two:
            returnVector[0]++;
            break;
        case cardDeck::values::Three:
            returnVector[1]++;
            break;
        case cardDeck::values::Four:
            returnVector[2]++;
            break;
        case cardDeck::values::Five:
            returnVector[3]++;
            break;
        case cardDeck::values::Six:
            returnVector[4]++;
            break;
        case cardDeck::values::Seven:
            returnVector[5]++;
            break;
        case cardDeck::values::Eight:
            returnVector[6]++;
            break;
        case cardDeck::values::Nine:
            returnVector[7]++;
            break;
        case cardDeck::values::Ten:
            returnVector[8]++;
            break;
        case cardDeck::values::Jack:
            returnVector[9]++;
            break;
        case cardDeck::values::Queen:
            returnVector[10]++;
            break;
        case cardDeck::values::King:
            returnVector[11]++;
            break;
        /*case cardDeck::values::Joker:
            returnVector[13]++;
            break;*/
        }
    }

    // return filled vector
    return returnVector;
}

// list all suits present in a vector
std::vector<int> Hand::getHandSuits() {

    // indexes : 0 = clubs, 1 = diamonds, 2 = hearts, 3 = spades , 4 = noSuit
    std::vector<int> returnVector = { 0,0,0,0 };

    // for all the cards in the hand increment if the suit is the current card
    for (Card currCard : Hand::hand) {
        switch (currCard.getSuit()) {
        case cardDeck::suits::Club:
            returnVector[0]++;
            break;
        case cardDeck::suits::Diamond:
            returnVector[1]++;
            break;
        case cardDeck::suits::Heart:
            returnVector[2]++;
            break;
        case cardDeck::suits::Spade:
            returnVector[3]++;
            break;
        /*case cardDeck::suits::noSuit:
            returnVector[4]++;
            break;*/
        }
    }

    // return filled vector
    return returnVector;

}

// return true if an ace is in the hand
bool Hand::Ace() {

    // return value
    bool toReturn = false;

    // for all the cards in the hand
    for (Card currCard : hand) {

        // if current card is an ace set return
        if (currCard.getValue() == cardDeck::values::Ace) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// returns true if hand has a king
bool Hand::hasKing() {

    // return value
    bool toReturn = false;

    // for all the cards in teh hand
    for (Card currCard : hand) {

        // if the current cards value is a king set  true
        if (currCard.getValue() == cardDeck::values::King) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// returns true if hand has a Joker
bool Hand::hasJoker() {

    // return value
    bool toReturn = false;

    // for all the cards in teh hand
    for (Card currCard : hand) {

        // if the current cards value is a king set  true
        if (currCard.getValue() == cardDeck::values::Joker) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// returns true if hand has a Joker
bool Hand::hasQueen() {

    // return value
    bool toReturn = false;

    // for all the cards in teh hand
    for (Card currCard : hand) {

        // if the current cards value is a king set  true
        if (currCard.getValue() == cardDeck::values::Queen) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// gets the high card of a given vector
int Hand::getHighCard(std::vector<int> handValues) {

    // return the highest cards value
    int toReturn = 0;

    // position in vector
    int vectorPos = 0;

    // for all the values in the vector
    for (int currValue : handValues) {

        // if the current vaule is higher than the current highest set new highest
        if (currValue > 0 && cardDeck::numValuesArray[vectorPos] > toReturn) {
            toReturn = cardDeck::numValuesArray[vectorPos];
        }

        // increment counter
        vectorPos++;
    }

    // return highest card
    return toReturn;
}

// check for flush
bool Hand::isFlush(std::vector<int> handSuits) {
    // return value
    bool toReturn = false;

    // loop through the suits vector
    for (int currSuit : handSuits) {
        // if suits vector has a 5 all cards are same suit thus the hand is a flush
        if (currSuit == 5) {

            // return true
            toReturn = true;
            break;

        } // check for flush with a joker
        else if (currSuit == 4 && hasJoker()) {

            // return true
            toReturn = true;
            break;

        }
    }

    // return status
    return toReturn;
}

// checks for straight
bool Hand::isStraight(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // if hand has ace and not king 
    // make vector with just the wheel straight to check for the wheel straight
    
    // counts current consecitive
    int currConsecitive = 0;

    // gap index (ex. 1, 0, 1, 1, 1  zero is the gap)
    int gapIndex = 0;

    // one consecitve
    int oneCon = 0; 

    // two consecitve
    int twoCon = 0;

    // three consecitve
    int threeCon = 0;

    // check straight conditions for Joker 
    if (hasJoker()) {

        // check for wheel straight
        if (Ace() && !(hasKing() || hasQueen())) {
            
            int wheelCounter = 0; // Counter to get the first 4 (2,3,4,5)
            int wheelConsecitive = 0; //counter for consecitves in the wheel
            for (int currCard : handValues) {
                if (wheelCounter == 4) {
                    break; //just check the first few indexes
                }
                if (currCard == 1) {
                    wheelConsecitive++;
                }
                wheelCounter++;
            }

            if (wheelConsecitive == 3) { // is a wheel straight
                toReturn = true;
            }
        }

        // Check other cases
        for (int currCard : handValues) {

            // if there is one of the current card in the hand increment the consecitive counter
            if (currCard == 1) {
                currConsecitive++;

                // if there are 4 comsecitive cards then it will be a straight
                if (currConsecitive == 4) {
                    toReturn = true;
                    break;
                }
            } // if current card is a gap in consecitive cards
            else if (currCard == 0 && currConsecitive > 0) {

                // increment for first gap
                gapIndex++;

                // incrememt the correct counter for the number of consecitive cards
                if (currConsecitive == 1) {
                    oneCon++;
                }else if (currConsecitive == 2) {
                    twoCon++;
                }else if (currConsecitive == 3) {
                    threeCon++;
                }

                // reset the consecitive counter
                currConsecitive = 0;
            }
            else if (currCard > 1) { // if not a one or not a zero in a gap not a straight thus break
                break;
            } // if second gap break 
            else if (currCard == 0 && gapIndex == 1){
                break;
            }
        }

        if (currConsecitive > 0) {
            // incrememt the correct counter for the number of consecitive cards
            if (currConsecitive == 1) {
                oneCon++;
            }
            else if (currConsecitive == 2) {
                twoCon++;
            }
            else if (currConsecitive == 3) {
                threeCon++;
            }
        }
        // if the hand had a one consecitive and a three consecitive then its a straight return true
        // ex. [1,0,1,1,1] or [1,1,1,0,1]
        if (oneCon == 1 && threeCon == 1) {
            toReturn = true;
        }// if there are 2 two consecitives then its a straight return true ex. [1,1,0,1,1] 
        else if (twoCon == 2) {
            toReturn = true;
        }
        
    }
    else { // Check for with no joker
        if (Ace() && !hasKing()) {
                // indexes: A = 0, 2 = 1, ... , 5 = 4 
                handValues = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
                for (Card currCard : Hand::hand) {
                    switch (currCard.getValue()) {
                    case cardDeck::values::Ace:
                        handValues[0]++;
                        break;
                    case cardDeck::values::Two:
                        handValues[1]++;
                        break;
                    case cardDeck::values::Three:
                        handValues[2]++;
                        break;
                    case cardDeck::values::Four:
                        handValues[3]++;
                        break;
                    case cardDeck::values::Five:
                        handValues[4]++;
                        break;
                    case cardDeck::values::Six:
                        handValues[5]++;
                        break;
                    case cardDeck::values::Seven:
                        handValues[6]++;
                        break;
                    case cardDeck::values::Eight:
                        handValues[7]++;
                        break;
                    case cardDeck::values::Nine:
                        handValues[8]++;
                        break;
                    case cardDeck::values::Ten:
                        handValues[9]++;
                        break;
                    case cardDeck::values::Jack:
                        handValues[10]++;
                        break;
                    case cardDeck::values::Queen:
                        handValues[11]++;
                        break;
                    case cardDeck::values::King:
                        handValues[12]++;
                        break;
                    }
                }
            }

            // consecitive counter 
            int consecitive = 0;

            // for all the values in the vector
            for (int currCard : handValues) {

                // if there is a consecitive line going and the current value is a zero break and return false because hand is not a straight
                if (consecitive > 0 && currCard == 0) {
                    break;
                }// if the currCard value is greater than 1 there are two card in the hand thus not a straight return false
                else if (currCard > 1) {
                    break;
                } // if 1 increment the consecitive counter
                else if (currCard == 1) {
                    consecitive++;
                }
            }

            // after the loop if the counter is equal to 5 set return to true
            if (consecitive == 5) {
                toReturn = true;
            }
    }
    

    // reutrn status
    return toReturn;
}

// checks if its a four of a kind
bool Hand::isFourOfKind(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // for all the values in the hand
    for (int currCard : handValues) {

        // if four 
        if (currCard == 4) {

            // set true
            toReturn = true;
            break;
        }
    }

    // return status
    return toReturn;
}

// checks if its a 3 of a kind
bool Hand::isThreeOfKind(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // for all the values in the vector
    for (int currCard : handValues) {
        // if three
        if (currCard == 3) {

            // set true
            toReturn = true;
            break;
        }
    }

    // return status
    return toReturn;
}

// checks if hand is a pair
bool Hand::isPair(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // for all the values in the vector
    for (int currCard : handValues) {

        // if pair
        if (currCard == 2) {

            // set status to true
            toReturn = true;
            break;
        }
    }

    // return status
    return toReturn;
}

// checks if its two pair
bool Hand::isTwoPair(std::vector<int> handValues) {
    // return value
    bool toReturn = false;

    // number of pairs in hand
    int numPairs = 0;


    //for all the values in the vector
    for (int currCard : handValues) {

        // if pair add to the number of pairs
        if (currCard == 2) {
            numPairs++;
        }
                
    }

    // if num pairs is 2 then the hand has two pairs
    if (numPairs == 2) {

        // set return value to true
        toReturn = true;

    }

    // return status
    return toReturn;
}

// gets value of the hand from 1,100,000 to 0
int Hand::getHandValue() {

    // int to return
    int returnValue = 0;

    // Normal Royal Flush
    // 1,000,000
    if (Hand::isFlush(getHandSuits()) && Hand::isStraight(getHandValues()) && Hand::Ace() && Hand::hasKing()) {
        // value for royal flush
        returnValue = 1'000'000;

    }// Joker Royal Flush
    else if (Hand::isStraight(getHandValues()) && Hand::isFlush(getHandSuits()) && hasJoker() && ((Ace() && hasKing()) || (Ace() && Hand::hasQueen()))) {
        // value for royal flush
        returnValue = 1'000'000;
    }// straight flush
    // 900,000 + highCard Value
    else if (Hand::isFlush(getHandSuits()) && Hand::isStraight(getHandValues())) {

        //base value for straight flush
        returnValue = 900'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // if card has been placed
        bool gapFilled = false;

        // if the straight is not a broadway straight then get rid of the ace for the highcard
        if (Ace() && !(hasKing() || hasQueen())) {

            // so ace wont be the high card
            currVector.at(12) = 0;

            // if hand has a straight and the two isnt in the hand fill the 2 because then the gap can be filled
            if (currVector.at(0) != 1) {
                gapFilled = true;
                currVector.at(0) = 1;
            }
        }



        // if the straight is made of a joker fill the spot of the gap or card after the chunck of the straight
        if (hasJoker() && !gapFilled) {

            // if there are previous cards; used to find the gap in the straight
            bool prevCards = false;


            // position in the vector
            int vectorPos = 0;

            // For all the cards in the card vector
            for (int currCard : currVector) {

                // if there are previous cards and the current card is not in the hand
                if (!gapFilled && prevCards && (currCard == 0)) {
                    // Add the current card because its the joker in the straight
                    currVector.at(vectorPos) = 1;
                    gapFilled = true;
                    break;
                }

                // if a card has been reached set the previous card to true
                if (currCard == 1) {
                    prevCards = true;
                }

                // increment card position
                vectorPos++;
            }
        }

        // add the highest card value to the hand value
        returnValue += getHighCard(currVector);

    }// Five of a Kind
    // 1,000,000 + Kind Value
    else if (isFourOfKind(getHandValues()) && hasJoker()) {

        // base return value
        returnValue = 1'000'000;

        // current positon in vector
        int cardPosition = 0;
        for (int vectorValue : getHandValues()) {

            // if four of a kind multiply card value by primary multiply
            if (vectorValue == 4) {

                returnValue += cardDeck::numValuesArray[cardPosition];

            }

            // increment counter
            cardPosition++;

        }

    }// Four of a Kind
    // 800,000 + highCard of the 4 of a kind * 3583 + single card value
    else if (isFourOfKind(getHandValues()) || (isThreeOfKind(getHandValues()) && hasJoker())) {

        // base return value
        returnValue = 800'000;
        // current positon in vector
        int cardPosition = 0;

        for (int vectorValue : getHandValues()) {

            // if four of a kind multiply card value by primary multiply
            if (vectorValue == 4) {

                returnValue += (cardDeck::highCardMultiples[0] * cardDeck::numValuesArray[cardPosition]);

            } //if single card add value to returnValue
            else if (vectorValue == 1) {

                returnValue += cardDeck::numValuesArray[cardPosition];

            }
            else if (vectorValue == 3 && hasJoker()) {

                returnValue += (cardDeck::highCardMultiples[0] * cardDeck::numValuesArray[cardPosition]);

            }

            // increment counter
            cardPosition++;

        }
        
    }// Full House
    // 700,000 + Triple value * 3583 + double value * 512
    else if (isThreeOfKind(getHandValues()) && isPair(getHandValues())) {

        // base value to return
        returnValue = 700'000;

        // card position in vector
        int cardPosition = 0;

        // loop for each value in the vector
        for (int vectorValue : getHandValues()) {

            // if three of a kind
            if (vectorValue == 3) {

                // priority value
                returnValue += cardDeck::highCardMultiples[0] * cardDeck::numValuesArray[cardPosition];

            }
            else if (vectorValue == 2) {

                // secondary value
                returnValue += cardDeck::highCardMultiples[1] * cardDeck::numValuesArray[cardPosition];

            }
            // increment position
            cardPosition++;
        }

    }// Full House: Two pair Joker 
    // 700,000 + 1st highest pair value * 3583 + 2nd pair value * 512
    else if (isTwoPair(getHandValues()) && hasJoker()) {

        //base value
        returnValue = 700'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // card position in vector
        int cardPosition = 0;

        // current multiply value for hand Value for after pairs
        int currMulti = 2;

        // current high card
        int currHighCard = 0;

        // loop for all the card values
        for (int currIndex : getHandValues()) {

            // if the current vector index is a pair
            if (currIndex == 2) {

                // if the first pair is found multiply by first multi value because the pair is higher
                if (returnValue > 700'000) {
                    returnValue += ((cardPosition + 2) * cardDeck::highCardMultiples[0]);
                }
                else { // else the pair is the smaller pair in the hand thus multiply by the second multi value
                    returnValue += ((cardPosition + 2) * cardDeck::highCardMultiples[1]);
                }

                // set the pairs vectors location to 0;
                currVector.at(cardPosition) = 0;

            }

            // increment the card position
            cardPosition++;

        }

    }// Flush
    // 600,000 + 1st Highest Card * 3583 + 2nd * 512 + 3rd * 64 + 4th * 8 + 5th value
    // if Joker is in the hand then the highest card will be the next highest card posible of the ones that arent taken
    else if (isFlush(getHandSuits())) {

        // base value
        returnValue = 600'000;

        // current high card value
        int currHighCard = 0;

        // number of cards looped through
        int numHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // If Joker add the next highest to the cards vector
        if (hasJoker()) {

            // card counter to get to ninth empty spot then add
            int emptyCards = 0;

            // Counter for current position in the vector
            int currPosition = 0;

            // loop through the hand
            for (int currCard : currVector) {
                if (currCard == 0) {
                    emptyCards++;
                }
                if (emptyCards == 9) {
                    currVector.at(currPosition)++;
                }
                currPosition++;
            }
        }

        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[numHighCard] * currHighCard;

            //increment high card counter
            numHighCard++;

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2)=0;

        }

    }// Straight
    // 500,000 + high card value
    else if (isStraight(getHandValues())) {

        // base straight value
        returnValue = 500'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // if card has been placed
        bool gapFilled = false;

        // if the straight is not a broadway straight then get rid of the ace for the highcard
        if (Ace() && !(hasKing() || hasQueen())) {

            // so ace wont be the high card
            currVector.at(12) = 0;

            // if hand has a straight and the two isnt in the hand fill the 2 because then the gap can be filled
            if (currVector.at(0) != 1) {
                gapFilled = true;
                currVector.at(0) = 1;
            }
        }

        

        // if the straight is made of a joker fill the spot of the gap or card after the chunck of the straight
        if (hasJoker() && !gapFilled) {

            // if there are previous cards; used to find the gap in the straight
            bool prevCards = false;

            
            // position in the vector
            int vectorPos = 0;

            // For all the cards in the card vector
            for (int currCard : currVector) {

                // if there are previous cards and the current card is not in the hand
                if (!gapFilled && prevCards && (currCard == 0)) {
                    // Add the current card because its the joker in the straight
                    currVector.at(vectorPos)=1;
                    gapFilled = true;
                    break;
                }

                // if a card has been reached set the previous card to true
                if (currCard == 1) {
                    prevCards = true;
                }

                // increment card position
                vectorPos++;
            }
        }

        // add the highest card value to the hand value
        returnValue += getHighCard(currVector);

    }// Three of a kind
    // 400,000 + triple * 3583 + 1st high card * 512 + 2nd high card * 64
    else if (isThreeOfKind(getHandValues()) || (isPair(getHandValues())) && hasJoker()) {

        // Base value
        returnValue = 400'000;

        // position in the vector
        int cardPosition = 0;

        // num single high cards
        int numSingle = 0;

        // current multiply value for hand Value for after pairs
        int currMulti = 0;

        // current high card
        int currHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // for each value in the values vector
        for (int vectorValue : getHandValues()) {

            // if three of a kind
            if (vectorValue == 3) {

                // mulitply card value by first multiple and set vector index to zero
                returnValue += (cardDeck::numValuesArray[cardPosition] * cardDeck::highCardMultiples[currMulti]);
                currMulti++;
                currVector.at(cardPosition) = 0;

            } // if three of a kind with joker
            else if (vectorValue == 2 && hasJoker()) {

                // mulitply card value by first multiple and set vector index to zero
                returnValue += (cardDeck::numValuesArray[cardPosition] * cardDeck::highCardMultiples[currMulti]);
                currMulti++;
                currVector.at(cardPosition) = 0;

            }
            cardPosition++;
        }

        // for the rest of the cards that arnt paired
        while (getHighCard(currVector) != 0) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += (cardDeck::highCardMultiples[currMulti] * currHighCard);

            //increment high card counter multiplier
            currMulti++;

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }

    } // Two pair
    // 300,000 + 1st highest pair value * 3583 + 2nd pair value * 512 + single value * 64
    else if (isTwoPair(getHandValues())) {

        //base value
        returnValue = 300'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        
        // card position in vector
        int cardPosition = 0;

        // current multiply value for hand Value for after pairs
        int currMulti = 2;

        // current high card
        int currHighCard = 0;

        // loop for all the card values
        for (int currIndex : getHandValues()) {

            // if the current vector index is a pair
            if (currIndex == 2) {

                // if the first pair is found multiply by first multi value because the pair is higher
                if (returnValue > 300'000) {
                    returnValue += ((cardPosition + 2) * cardDeck::highCardMultiples[0]);
                }
                else { // else the pair is the smaller pair in the hand thus multiply by the second multi value
                    returnValue += ((cardPosition + 2) * cardDeck::highCardMultiples[1]);
                }

                // set the pairs vectors location to 0;
                currVector.at(cardPosition) = 0;

            }

            // increment the card position
            cardPosition++;

        }

        // for the rest of the cards that arnt paired
        while (getHighCard(currVector) != 0) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += (cardDeck::highCardMultiples[currMulti] * currHighCard);

            //increment high card counter multiplier
            currMulti++;

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }
    


    }// Pair
    // 200,000 + pair * 3583 + 1st single highest * 512 + 2nd * 64 + 3rd * 8
    else if (isPair(getHandValues()) || hasJoker()) {
        // base value for pair
        returnValue = 200'000;

        // current multiply value for hand Value
        int currMulti = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // number of times looped
        int cardPosition = 0;

        // current high card for the values of the rest of the cards
        int currHighCard = 0;

        // if hand has a joker make the highest card a pair
        if (hasJoker()) {
            currVector.at(getHighCard(currVector) - 2) = 2;
        }

        // loop through the vector
        for (int currIndex : getHandValues()) {

            // for the pair multiple the multi coefficent by the current cards value
            if (currIndex == 2) {
                returnValue += (cardPosition + 2) * cardDeck::highCardMultiples[currMulti];
                currVector.at(cardPosition) = 0;
                currMulti=1;
                break;
            }
            // increment the card position
            cardPosition++;
        }

        // for the rest of the cards that arnt paired
        while (getHighCard(currVector) > 0) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += (cardDeck::highCardMultiples[currMulti] * currHighCard);

            //increment high card counter multiplier
            currMulti = currMulti + 1;

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }

    } // High Card
    // 100,000 + 1st highest * 3583 + 2nd * 512 + 3rd * 64 + 4th * 8 + 5th
    else {

        // base value for High Card
        returnValue = 100'000;

        // current high card value
        int currHighCard = 0;

        // number of cards looped through
        int numHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += (cardDeck::highCardMultiples[numHighCard] * currHighCard);

            //increment high card counter
            numHighCard++;

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }

    }
    // return value of hand
    return returnValue;
}

// overloading <=>
std::strong_ordering Hand::operator<=>(Hand& hand1) {
    return hand1.getHandValue() <=> this->getHandValue();
}

