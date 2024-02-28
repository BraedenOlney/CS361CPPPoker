/*
Braeden Olney
CS 361
Assignment # 9
Main.cpp
Prints out the same output as assignment 8
*/

#include "Deck.h"
#include "Hand.h"
#include "Card.h"

using namespace std;

// initialize the method
bool goodDiscards(vector<int>, int);

int main() {

    // error status 
    int errorStatus = 0;
    bool playAgain = true;

    // constant for the size of hand
    const int sizeOfHand = 5;

    // while true
    while (playAgain) {

        //Hand 1
        // make a deck and hand
        std::unique_ptr<Deck> deck = std::make_unique<Deck>();
        std::unique_ptr<Hand> hand1 = std::make_unique<Hand>();
        std::unique_ptr<Hand> hand2 = std::make_unique<Hand>();



        
        // alternate adding cards to each hand from deck
        for (int handSize = 0; handSize < sizeOfHand; handSize++) {
            hand1->addCardToHand(deck->dealCard());
            hand2->addCardToHand(deck->dealCard());
        }
        



        /*
        // for testing
        hand1->addCardToHand(Card{ cardDeck::values::Ace, cardDeck::suits::Club });
        hand1->addCardToHand(Card{ cardDeck::values::Two, cardDeck::suits::Club });
        hand1->addCardToHand(Card{ cardDeck::values::Three, cardDeck::suits::Club });
        hand1->addCardToHand(Card{ cardDeck::values::Four, cardDeck::suits::Club });
        hand1->addCardToHand(Card{ cardDeck::values::Five, cardDeck::suits::Club });

        hand2->addCardToHand(Card{ cardDeck::values::Ace, cardDeck::suits::Spade });
        hand2->addCardToHand(Card{ cardDeck::values::Two, cardDeck::suits::Spade });
        hand2->addCardToHand(Card{ cardDeck::values::Three, cardDeck::suits::Spade });
        hand2->addCardToHand(Card{ cardDeck::values::Joker, cardDeck::suits::noSuit });
        hand2->addCardToHand(Card{ cardDeck::values::Five, cardDeck::suits::Spade });
        */

        // how many cards the user can replace with current hand based on if an ace is in the hand
        int numAbleRemove = 3;
        if (hand1->Ace()) {
            numAbleRemove = 4;
        }

        // print out hand1 size, hand1, and deck size
        cout << endl << "Player 1s Turn" << endl;
        cout << "There are " << hand1->handSize() << " cards in hand1" << endl;
        cout << "These cards are in  hand1: ";
        cout << *hand1 << endl;
        cout << endl << hand1->getHandValue() << endl;
        cout << endl << "There are " << deck->deckSize() << " cards remaining in the deck" << endl;
        cout << "You may replace three cards in your hand, four if you have an ace" << endl;
        cout << "Please enter the card numbers of card(s) you wish to discard, followed by 0: ";

        // initialize a vector for user input
        std::vector<int> removeIndexes{};

        // user input to put into the vector for index values to remove
        int nextIndex;

        // get all user input until 0
        while (true) {
            if (cin >> nextIndex) {
                if (nextIndex == 0) {
                    break;
                }
                removeIndexes.push_back(nextIndex - 1);
            }
            else {
                cerr << endl << endl << "Invalid User Input" << endl << endl;
                errorStatus = 1;
                break;
            }
        }

        // if error end program
        if (errorStatus == 1) {
            break;
        }

        // if the values in the vector are not duplicates and are from 0-4
        if (goodDiscards(removeIndexes, numAbleRemove)) {

            // counter for number of cards able to discard
            int discardCounter = 0;

            // change the cards for all the index
            for (int currIndexRemove : removeIndexes) {

                // check for correct number of discards
                if (discardCounter >= numAbleRemove) {
                    break;
                }
                // discard the card user wants removed
                hand1->discard(currIndexRemove, deck->dealCard());

                // increment the counter
                discardCounter++;
            }

            //reprint the hand
            // print out hand size, hand, and deck size
            cout << endl << "There are " << hand1->handSize() << " cards in the hand1" << endl;
            cout << "These cards are in the hand1: " << endl;
            cout << *hand1;
            cout << endl << hand1->getHandValue() << endl;
        }
        else { // if invalid 
            cerr << endl << "Invalid Discard";
            errorStatus = 1;
        }

        // if invalid discard end program
        if (errorStatus == 1) {
            break;
        }



        // hand 2
        // print out hand2 size, hand2, and deck size
        cout << endl << "Player 2s Turn" << endl;
        cout << endl << "There are " << hand2->handSize() << " cards in hand2" << endl;
        cout << "These cards are in  hand2: ";
        cout << *hand2;
        cout << endl << endl;
        cout << hand2->getHandValue() << endl;
        cout << "There are " << deck->deckSize() << " cards remaining in the deck" << endl << endl;
        cout << "You may replace three cards in your hand, four if you have an ace" << endl;
        cout << "Please enter the card numbers of card(s) you wish to discard, followed by 0: ";

        // how many cards the user can replace with current hand based on if an ace is in the hand
        numAbleRemove = 3;
        if (hand2->Ace()) {
            numAbleRemove = 4;
        }

        // reset vector
        removeIndexes = {};

        // get all user input until 0
        while (cin >> nextIndex) {
            if (nextIndex == 0) {
                break;
            }
            removeIndexes.push_back(nextIndex - 1);

        }

        // if the values in the vector are not duplicates and are from 0-4
        if (goodDiscards(removeIndexes, numAbleRemove)) {

            // counter for number of cards able to discard
            int discardCounter = 0;

            // change the cards for all the index
            for (int currIndexRemove : removeIndexes) {

                // check for correct number of discards
                if (discardCounter >= numAbleRemove) {
                    break;
                }
                // discard the card user wants removed
                hand2->discard(currIndexRemove, deck->dealCard());

                // increment the counter
                discardCounter++;
            }

            //reprint the hand
            // print out hand size, hand, and deck size
            cout << "There are " << hand2->handSize() << " cards in the hand2" << endl;
            cout << "These cards are in the hand2: " << endl;
            cout << *hand2;
            cout << endl << hand2->getHandValue() << endl;
        }
        else { // if invalid 
            cerr << "Invalid Discard";
            errorStatus = 1;
        }

        // if discard error dont loop and end program
        if (errorStatus == 1) {
            playAgain = false;
        }
        else {

            // prints what hand is greater or equal using the <=> operator
            auto check = *hand1 <=> *hand2;

            if (check == strong_ordering::less) {
                cout << "Hand 1 is better than Hand 2";
            }
            else if (check == strong_ordering::greater) {
                cout << "Hand 2 is better than Hand 1";
            }
            else {
                cout << "The Hands have the same value";
            }

            // print play again message
            cout << endl << endl << "Enter '1' to play again and or '0' to exit program:";

            // input varible
            char userInput;

            // take input
            cin >> userInput;

            // if the user input equals 1 play again else set loop var to false to not play again
            if (userInput != '1') {
                playAgain = false;
            }
        }

        // Pushes to "Clear Screen"
        cout << "\033[2J\033[1;1H";
    }

    // return status
    return errorStatus;
}

// checks discard indexes for valid indexes and duplicates 
bool goodDiscards(vector<int> indexesVector, int numAbleRemove) {

    // Array for duplicate check, if a number is 1 the index is in the vector
    int duplicateCheck[5] = { 0,0,0,0,0 };

    // return value
    bool toReturn = true;

    // counter for number of cards able to discard
    int discardCounter = 0;

    // loop through the vector
    for (int currIndex : indexesVector) {

        // if the index value is out of the hand indexing return false because the card cannot be indexed
        if (currIndex < 0 || currIndex > 4) {
            toReturn = false;
            break;
        }
        // takes in the first number of discards depending on ace
        if (numAbleRemove < discardCounter) {
            break;
        }

        // if the current index is not zero then the index is already in the vector thus its a duplicate return false
        if (duplicateCheck[currIndex] != 0) {
            toReturn = false;
            break;
        }
        else { // else the index isnt in the vector thus mark that it is in the array check
            duplicateCheck[currIndex] = 1;
        }

        discardCounter++;
    }

    // if all conditions passed return true
    return toReturn;

}