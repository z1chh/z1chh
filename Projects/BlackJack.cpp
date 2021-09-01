/*
=======================================
Name          : BlackJack.cpp
Author        : Zi Chen Hu
Description   : BlackJack Game
=======================================
 */


/**
 * 
 * Welcome to the BlackJack Table!
 * Run this program to start playing!
 * 
 */

#include <iostream>

using namespace std;
/**
 * Notes on Classes:
 * 
 * Card Class:
 * The 52 standard Cards are being initialized as global variables (declared after the Card class).
 * As required, Rank::ACE is attributed the value 1. Nothing was specified for the Type enums, so I set the first enum to value 1 as well.
 * The getValue method sets Aces to be worth 11 points by default.
 * 
 * 
 * 
 * Hand Class:
 * The Hand constructor creates an array of Card pointers (size of 12).
 * This array is set to static so it doesnt get destroyed at the end of the initialization of a Hand object.
 * The getTotal method sets the value of Aces to 1 (instead of the default 11) ONLY if the Hand is currently busting.
 * 
 * 
 * 
 * Deck Class:
 * The Deck constructor creates an array of Card pointers (size of 52).
 * This array is set to static so it doesnt get destroyed at the end of the initialization of a Deck object.
 * 
 * The deal() method takes the Card on top of the Deck (last element of the array), but does not actually remove it.
 * In fact, from now on, we consider the previous Card as the last Card of the Deck.
 * 
 * The shuffle() method swaps two randomly selected Cards until all Cards (or 1 Card is left, if the Deck has odd size) are swapped.
 * 
 * 
 * 
 * HumanPlayer Class:
 * The isDrawing method() makes sure the user entered a valid input (y/n). Otherwise, we ask the question again (instead of assuming no).
 * However, if the user enters an invalid input 10 times in a row, THEN we assume they stop drawing.
 * 
 * 
 * 
 * 
 * 
 * Other Notes:
 * Encapsulation of Data:
 * To avoid any form of cheating from the user, Card fields are private and no methods are provided to change them.
 * Furthermore, the Hand and Deck classes only use Card objects that have been created beforehand.
 * Thus, the only way for the user to introduce new Cards is by creating new Card objects, but the Hand and Deck classes will never use the newly created Card objects.
 * Such immutability allows the preservation of encapsulation and avoids information leaking.
 * 
 * 
 * Proper Calculation of the Ace Value:
 * I set the default value of the Ace to 11 since it allows the Player to get a bigger number (closer to 21).
 * However, if this causes the Player to bust, I set its value down to 1 point (Hand::getTotal() method).
 * This is, in my opinion, the best way to attribute a value to Aces to suit the Player best.
 * 
 * Differences Between Provided main() and Expected Output:
 * The provided main() and the expected output are different (for example, main() couts "Blackjack game" instead of "Blackjack table" and main() couts more "\n"s and "\t").
 * Thus, I slightly modified the main() so that it matches the expected output.
 */



// Enums for the fields of a Card (Rank and Type)
enum Rank // The Rank of a Card.
{
    ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13
};
enum Type // The Suit of a Card.
{
    CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4
};



/**
 * Class Card
 * 
 * @param aRank the Rank of the Card.
 * @param aType the Suit of the Card.
 * 
 */
class Card
{
public:
    // Constructors
    Card(): // Default Constructor
    aRank(Rank::ACE),
    aType(Type::SPADES)
    {
        //cout << "Default constructor for Card got called." << endl;
    }
    
    Card(Rank pRank, Type pType): // Personalized Constructor
    aRank(pRank),
    aType(pType)
    {
        //cout << "Personalized constructor for Card got called." << endl;
    }


    // Destructor
    ~Card()
    {
        // No memory allocated dynamically, nothing to destroy manually.
        //cout << "Destructor for Card got called." << endl;
    }

    // Methods for Card:
    Rank getRank();
    Type getType();
    int getValue();
    void displayCard();

private:
    // Fields - Set to private to avoid the client from modifying the values of a Card.
    Rank aRank; // Rank of the Card (field).
    Type aType; // Suit of the Card (field).
};



/**
 * Card method: getRank
 * 
 * Card method to get the Rank of a Card.
 * @pre pCard.Rank != NULL && pCard.Rank != VOID_RANK
 * @pre pCard.Type != NULL && pCard.Type != VOID_TYPE
 * @return Rank the rank of the Card.
 * 
 */
Rank Card::getRank()
{
    return this->aRank;
}



/**
 * Card method: getType
 * 
 * Card method to get the Type of a Card.
 * @pre pCard.Rank != NULL && pCard.Rank != VOID_RANK
 * @pre pCard.Type != NULL && pCard.Type != VOID_TYPE
 * @return Rank the Type of the Card.
 * 
 */
Type Card::getType()
{
    return this->aType;
}



/**
 * Card method: getValue
 * 
 * Card method to get the value of a Card.
 * @pre pCard.Rank != NULL
 * @pre pCard.Type != NULL
 * @return int the value of the Card.
 * 
 */
int Card::getValue()
{
    // Identify the Rank of the Card.
    if(this->aRank == 1)
    {
        // Rank::ACE can be worth 1 or 11 points. By default, we set it to 11.
        // The Hand::getTotal() method will automitically set its value to 1 if the Hand busted.
        return 11;
    }
    else if(this->aRank == 2)
    {
        return 2;
    }
    else if(this->aRank == 3)
    {
        return 3;
    }
    else if(this->aRank == 4)
    {
        return 4;
    }
    else if(this->aRank == 5)
    {
        return 5;
    }
    else if(this->aRank == 6)
    {
        return 6;
    }
    else if(this->aRank == 7)
    {
        return 7;
    }
    else if(this->aRank == 8)
    {
        return 8;
    }
    else if(this->aRank == 9)
    {
        return 9;
    }
    else // this->aRANK == TEN, JACK, QUEEN or KING (10, 11, 12, 13)
    {
        return 10;
    }
}



/**
 * Card method: displayCard
 * 
 * Card method to print the Rank and Type of the Card to the screen.
 * @pre pCard.Rank != NULL
 * @pre pCard.Type != NULL
 * 
 */
void Card::displayCard()
{
    // Print out the Rank first.
    if(this->aRank == 1)
    {
        cout << "1";
    }
    else if(this->aRank == 2)
    {
        cout << "2";
    }
    else if(this->aRank == 3)
    {
        cout << "3";
    }
    else if(this->aRank == 4)
    {
        cout << "4";
    }
    else if(this->aRank == 5)
    {
        cout << "5";
    }
    else if(this->aRank == 6)
    {
        cout << "6";
    }
    else if(this->aRank == 7)
    {
        cout << "7";
    }
    else if(this->aRank == 8)
    {
        cout << "8";
    }
    else if(this->aRank == 9)
    {
        cout << "9";
    }
    else if(this->aRank == 10)
    {
        cout << "10";
    }
    else if(this->aRank == 11)
    {
        cout << "J";
    }
    else if(this->aRank == 12)
    {
        cout << "Q";
    }
    else if(this->aRank == 13)
    {
        cout << "K";
    }
    
    // Print out the Type second.
    if(this->aType == 1)
    {
        cout << "C";
    }
    else if(this->aType == 2)
    {
        cout << "D";
    }
    else if(this->aType == 3)
    {
        cout << "H";
    }
    else if(this->aType == 4)
    {
        cout << "S";
    }
}



// 52 Cards of a standard Deck (global variables used for the game - only Card objects used by the game).
// As explained above, once created, these Cards are immutable. Furthermore, the Blackjack game only uses these Cards, to avoid any form of cheating (encapsulation).
Card cAC = Card(Rank::ACE, Type::CLUBS); // Ace of Clubs
Card cAD = Card(Rank::ACE, Type::DIAMONDS); // Ace of Diamonds
Card cAH = Card(Rank::ACE, Type::HEARTS); // Ace of Hearts
Card cAS = Card(Rank::ACE, Type::SPADES); // Ace of Spades

Card c2C = Card(Rank::TWO, Type::CLUBS); // Two of Clubs
Card c2D = Card(Rank::TWO, Type::DIAMONDS); // Two of Diamonds
Card c2H = Card(Rank::TWO, Type::HEARTS); // Two of Hearts
Card c2S = Card(Rank::TWO, Type::SPADES); // Two of Spades

Card c3C = Card(Rank::THREE, Type::CLUBS); // Three of Clubs
Card c3D = Card(Rank::THREE, Type::DIAMONDS); // Three of Diamonds
Card c3H = Card(Rank::THREE, Type::HEARTS); // Three of Hearts
Card c3S = Card(Rank::THREE, Type::SPADES); // Three of Spades

Card c4C = Card(Rank::FOUR, Type::CLUBS); // Four of Clubs
Card c4D = Card(Rank::FOUR, Type::DIAMONDS); // Four of Diamonds
Card c4H = Card(Rank::FOUR, Type::HEARTS); // Four of Hearts
Card c4S = Card(Rank::FOUR, Type::SPADES); // Four of Spades

Card c5C = Card(Rank::FIVE, Type::CLUBS); // Five of Clubs
Card c5D = Card(Rank::FIVE, Type::DIAMONDS); // Five of Diamonds
Card c5H = Card(Rank::FIVE, Type::HEARTS); // Five of Hearts
Card c5S = Card(Rank::FIVE, Type::SPADES); // Five of Spades

Card c6C = Card(Rank::SIX, Type::CLUBS); // Six of Clubs
Card c6D = Card(Rank::SIX, Type::DIAMONDS); // Six of Diamonds
Card c6H = Card(Rank::SIX, Type::HEARTS); // Six of Hearts
Card c6S = Card(Rank::SIX, Type::SPADES); // Six of Spades

Card c7C = Card(Rank::SEVEN, Type::CLUBS); // Seven of Clubs
Card c7D = Card(Rank::SEVEN, Type::DIAMONDS); // Seven of Diamonds
Card c7H = Card(Rank::SEVEN, Type::HEARTS); // Seven of Hearts
Card c7S = Card(Rank::SEVEN, Type::SPADES); // Seven of Spades

Card c8C = Card(Rank::EIGHT, Type::CLUBS); // Eight of Clubs
Card c8D = Card(Rank::EIGHT, Type::DIAMONDS); // Eight of Diamonds
Card c8H = Card(Rank::EIGHT, Type::HEARTS); // Eight of Hearts
Card c8S = Card(Rank::EIGHT, Type::SPADES); // Eight of Spades

Card c9C = Card(Rank::NINE, Type::CLUBS); // Nine of Clubs
Card c9D = Card(Rank::NINE, Type::DIAMONDS); // Nine of Diamonds
Card c9H = Card(Rank::NINE, Type::HEARTS); // Nine of Hearts
Card c9S = Card(Rank::NINE, Type::SPADES); // Nine of Spades

Card cTC = Card(Rank::TEN, Type::CLUBS); // Ten of Clubs
Card cTD = Card(Rank::TEN, Type::DIAMONDS); // Ten of Diamonds
Card cTH = Card(Rank::TEN, Type::HEARTS); // Ten of Hearts
Card cTS = Card(Rank::TEN, Type::SPADES); // Ten of Spades

Card cJC = Card(Rank::JACK, Type::CLUBS); // Jack of Clubs
Card cJD = Card(Rank::JACK, Type::DIAMONDS); // Jack of Diamonds
Card cJH = Card(Rank::JACK, Type::HEARTS); // Jack of Hearts
Card cJS = Card(Rank::JACK, Type::SPADES); // Jack of Spades

Card cQC = Card(Rank::QUEEN, Type::CLUBS); // Queen of Clubs
Card cQD = Card(Rank::QUEEN, Type::DIAMONDS); // Queen of Diamonds
Card cQH = Card(Rank::QUEEN, Type::HEARTS); // Queen of Hearts
Card cQS = Card(Rank::QUEEN, Type::SPADES); // Queen of Spades

Card cKC = Card(Rank::KING, Type::CLUBS); // King of Clubs
Card cKD = Card(Rank::KING, Type::DIAMONDS); // King of Diamonds
Card cKH = Card(Rank::KING, Type::HEARTS); // King of Hearts
Card cKS = Card(Rank::KING, Type::SPADES); // King of Spades



/**
 * Class Hand
 * 
 * @param numCards the number of Cards in the Hand.
 * @param aListOfCards the set of Cards in the Hand.
 * 
 */
class Hand
{
    // Suppose we have a Hand with 4 ACES, 4 TWOS and 3 THREEs. Then, we have a Hand with total value of 21, with 11 Cards.
    // Hence, the most Cards one can have in their Hand without busting is 11 Cards.
    // This implies that a Hand of 12 Cards must have busted, hence cannot continue to draw Cards.
public:
    // Constructor
    Hand(): // Default Constructor
    numCards(0)
    {
        // Recall the Hand can have at most 12 Cards - and if it has 12 Cards, it must have busted.
        Card **pListOfCards = new Card*[12]{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
        this->aListOfCards = pListOfCards;

        //cout << "Default constructor for Hand got called." << endl;
    }

    // Destructor
    ~Hand()
    {
        delete [] aListOfCards;
        //cout << "Destructor for Hand got called." << endl;
    }

    // Methods for Hand:
    int getNumCards();
    void setNumCards(int newSize);
    Card** getListOfCards();
    void add(Card *pCard);
    void clear();
    int getTotal();

private:
    // Fields - Set to private to avoid the client from modifying the Hand.
    int numCards; // The number of Cards in the Hand.
    Card **aListOfCards; // Set of Cards in the Hand.
};



/**
 * Hand method: getNumCards
 * 
 * Hand method to return the number of Cards in the Hand.
 * @return int the number of Cards.
 * 
 */
int Hand::getNumCards()
{
    return this->numCards;
}



/**
 * Hand method: setNumCards
 * 
 * Hand method to set the number of Cards in the Hand to the given int.
 * 
 */
void Hand::setNumCards(int newSize)
{
    this->numCards = newSize;
}



/**
 * Hand method: getListOfCards
 * 
 * Hand method to get the pointer to the array of Cards in Hand.
 * 
 */
Card** Hand::getListOfCards()
{
    return this->aListOfCards;
}



/**
 * Hand method: add
 * 
 * Hand method to add a Card to the Hand.
 * @pre pCard.Rank != NULL
 * @pre pCard.Type != NULL
 * @pre this->numCards < 12
 * 
 */
void Hand::add(Card *pCard)
{
    int numCards = this->getNumCards();
    this->getListOfCards()[numCards] = pCard;
    this->setNumCards(numCards + 1);
}



/**
 * Hand method: clear
 * 
 * Hand method to clear all Cards from the Hand.
 * 
 */
void Hand::clear()
{
    // Set every pointer to a nullptr.
    this->aListOfCards[0] = nullptr;
    this->aListOfCards[1] = nullptr;
    this->aListOfCards[2] = nullptr;
    this->aListOfCards[3] = nullptr;
    this->aListOfCards[4] = nullptr;
    this->aListOfCards[5] = nullptr;
    this->aListOfCards[6] = nullptr;
    this->aListOfCards[7] = nullptr;
    this->aListOfCards[8] = nullptr;
    this->aListOfCards[9] = nullptr;
    this->aListOfCards[10] = nullptr;
    this->aListOfCards[11] = nullptr;

    // Set the number of Cards in the Hand to 0.
    this->numCards = 0;
}



/**
 * Hand method: getTotal
 * 
 * Hand method to compute the total sum of the Cards' numerical values.
 * @return int totalValue the value of the Hand.
 * 
 */
int Hand::getTotal()
{
    int totalValue = 0; // The total value of the Hand.
    int totalAces = 0; // Number of Aces.

    // Loop through every Card to find its value.
    for(int i = 0; i < 12; i++)
    {
        if(this->aListOfCards[i] != nullptr)
        {
            totalValue += aListOfCards[i]->getValue();

            // We check if the Card is an Ace.
            if(aListOfCards[i]->getRank() == Rank::ACE)
            {
                totalAces++;
            }
        }
    }

    // We set the value of ONE Ace to 1 if the Hand busted (until there are no more Aces or the Hand is not busting anymore).
    // For example, a Hand with four Aces has 44 points. Since it is busting, one Ace is set to 1 point. The Hand now has 34 points.
    // Since the Hand is still busting AND there are still 3 more Aces worth 11 points, we set one more Ace to 1 point. The Hand now has 24 points.
    // Since the Hand is still busting AND there are still 2 more Aces worth 11 points, we set one more Ace to 1 point. The Hand now has 14 points.
    // The Hand is not busting anymore (one of the conditions not met). Loop ends, and the Hand has 3 Aces worth 1 point, and 1 Ace worth 11 points.
    while((totalValue > 21) && (totalAces > 0))
    {
        totalValue -= 10; // The value of one Ace goes from 11 to 1, hence it decrements by 10.
        totalAces--;
    }

    // Return the total value of the Hand.
    return totalValue;
}



/**
 * Class Deck
 * 
 * @param numCards the number of Cards in the Deck.
 * @param aListOfCards the set of Cards in the Deck.
 * 
 */
class Deck
{
public:
    // Constructor
    Deck(): // Default Constructor
    numCards(0)
    {

        static Card *pListOfCards[52] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
        this->aListOfCards = pListOfCards;

        //cout << "Default constructor for Deck got called." << endl;
    }

    // Destructor
    ~Deck()
    {
        // No memory allocated dynamically, nothing to destroy manually.
        //cout << "Destructor for Deck got called." << endl;
    }

    // Methods for Deck:
    int getNumCards();
    void setNumCards(int newSize);
    Card** getListOfCards();
    void populate();
    void shuffle();
    void deal(Hand *pHand);

private:
    // Fields - Set to private to avoid the client from modifying the Deck.
    int numCards; // The number of Cards in the Deck.
    Card **aListOfCards; // Set of Cards in the Deck.
};



/**
 * Deck method: getNumCards
 * 
 * Deck method to return the number of Cards in the Deck.
 * @return int the number of Cards.
 * 
 */
int Deck::getNumCards()
{
    return this->numCards;
}



/**
 * Deck method: setNumCards
 * 
 * Deck method to set the number of Cards in the Deck to the given int.
 * 
 */
void Deck::setNumCards(int newSize)
{
    this->numCards = newSize;
}



/**
 * Deck method: getListOfCards
 * 
 * Deck method to get the pointer to the array of Cards in Deck.
 * 
 */
Card** Deck::getListOfCards()
{
    return this->aListOfCards;
}



/**
 * Deck method: populate
 * 
 * Deck method create a standard Deck of 52 Cards.
 * 
 */
void Deck::populate()
{
    // Set every pointer to the corresponding Card.
    this->aListOfCards[0] = &cAC;
    this->aListOfCards[1] = &cAD;
    this->aListOfCards[2] = &cAH;
    this->aListOfCards[3] = &cAS;
    this->aListOfCards[4] = &c2C;
    this->aListOfCards[5] = &c2D;
    this->aListOfCards[6] = &c2H;
    this->aListOfCards[7] = &c2S;
    this->aListOfCards[8] = &c3C;
    this->aListOfCards[9] = &c3D;
    this->aListOfCards[10] = &c3H;
    this->aListOfCards[11] = &c3S;
    this->aListOfCards[12] = &c4C;
    this->aListOfCards[13] = &c4D;
    this->aListOfCards[14] = &c4H;
    this->aListOfCards[15] = &c4S;
    this->aListOfCards[16] = &c5C;
    this->aListOfCards[17] = &c5D;
    this->aListOfCards[18] = &c5H;
    this->aListOfCards[19] = &c5S;
    this->aListOfCards[20] = &c6C;
    this->aListOfCards[21] = &c6D;
    this->aListOfCards[22] = &c6H;
    this->aListOfCards[23] = &c6S;
    this->aListOfCards[24] = &c7C;
    this->aListOfCards[25] = &c7D;
    this->aListOfCards[26] = &c7H;
    this->aListOfCards[27] = &c7S;
    this->aListOfCards[28] = &c8C;
    this->aListOfCards[29] = &c8D;
    this->aListOfCards[30] = &c8H;
    this->aListOfCards[31] = &c8S;
    this->aListOfCards[32] = &c9C;
    this->aListOfCards[33] = &c9D;
    this->aListOfCards[34] = &c9H;
    this->aListOfCards[35] = &c9S;
    this->aListOfCards[36] = &cTC;
    this->aListOfCards[37] = &cTD;
    this->aListOfCards[38] = &cTH;
    this->aListOfCards[39] = &cTS;
    this->aListOfCards[40] = &cJC;
    this->aListOfCards[41] = &cJD;
    this->aListOfCards[42] = &cJH;
    this->aListOfCards[43] = &cJS;
    this->aListOfCards[44] = &cQC;
    this->aListOfCards[45] = &cQD;
    this->aListOfCards[46] = &cQH;
    this->aListOfCards[47] = &cQS;
    this->aListOfCards[48] = &cKC;
    this->aListOfCards[49] = &cKD;
    this->aListOfCards[50] = &cKH;
    this->aListOfCards[51] = &cKS;


    // Set the number of Cards in the Deck to 52.
    this->numCards = 52;
}


/**
 * Deck method: shuffle
 * 
 * Deck method to shuffle the Cards of the Deck.
 * This method takes two random Cards in the Deck and swaps them until every Card is swapped (or only 1 Card left if the Deck has an odd number of Cards - cannot swap it).
 * 
 */
void Deck::shuffle()
{
    // Number of Cards in the Deck.
    int numCards = this->getNumCards();

    // Initialize the array with 0s for every Card in the Deck, and with -1s for other elements of the array.
    int shuffleArray[52] = {0};
    for(int i = 0; i < 52; i++)
    {
        if(i >= numCards)
        {
            shuffleArray[i] = -1; // Value attributed to a Card that is either out of range (not in Deck), or shuffled.
        }
    }

    // Shuffle the Deck.
    int ShuffledCards = 0; // Number of Cards shuffled so far.
    int randomCard1ToShuffle = rand() % 52; // Random number from 0 to 52 (included).
    int randomCard2ToShuffle = rand() % 52; // Random number from 0 to 52 (included).
    Card **pListOfCards = this->getListOfCards(); // Pointer to the Deck of Cards.
    Card *tempCard; // Used to swap Cards.

    // If numCards is odd, we decrement it by 1.
    // This is due to the fact that we swap two cards at a time, hence ShuffledCards will always be even.
    // If numCards is odd, we will have an infinite loop.
    if((numCards % 2) == 1)
    {
        numCards--;
    }
    while(ShuffledCards != numCards) // Shuffle until all Cards have been shuffled.
    {
        // We check if the random Cards are in range (part of the Deck).
        if(shuffleArray[randomCard1ToShuffle] == -1)
        {
            // Card out of range.
            randomCard1ToShuffle = rand() % 52; // Get another random Card to shuffle.
            continue; // We go to the next iteration.
        }
        if(shuffleArray[randomCard2ToShuffle] == -1)
        {
            // Card out of range.
            randomCard2ToShuffle = rand() % 52; // Get another random Card to shuffle.
            continue; // We go to the next iteration.
        }

        // Otherwise, the Cards are in the Deck. We want to swap them.
        tempCard = pListOfCards[randomCard1ToShuffle];
        pListOfCards[randomCard1ToShuffle] = pListOfCards[randomCard2ToShuffle];
        pListOfCards[randomCard2ToShuffle] = tempCard;

        // Update variables for next iteration.
        shuffleArray[randomCard1ToShuffle] = -1; // Card now shuffled - "-1" represents a shuffled Card.
        shuffleArray[randomCard2ToShuffle] = -1; // Card now shuffled - "-1" represents a shuffled Card.
        randomCard1ToShuffle = rand() % 52; // Get another random Card to shuffle for the next iteration.
        randomCard2ToShuffle = rand() % 52; // Get another random Card to shuffle for the next iteration.
        ShuffledCards += 2; // Increment the number of Cards shuffled by 2.
    }
    //cout << "Deck shuffled! Shuffled " << ShuffledCards << " Cards." << endl;
}



/**
 * Deck method: deal
 * 
 * Deck method to draw a Card from the Deck.
 * 
 */
void Deck::deal(Hand *pHand)
{
    // Decrement the number of Cards by one.
    int numCards = this->getNumCards() - 1;
    this->setNumCards(numCards);

    // Add the last Card of the Deck ("top of the Deck") to pHand.
    pHand->add(this->getListOfCards()[numCards]);
}



/**
 * Class AbstractPlayer
 * 
 * @param aHand The Hand of the Player.
 * 
 */
class AbstractPlayer
{
public:
    // Constructor
    AbstractPlayer(): // Default Constructor
    aHand(new Hand())
    {
        //cout << "Default constructor for AbstractPlayer got called." << endl;
    }

    // Destructor
    virtual ~AbstractPlayer()
    {
        delete this->aHand;
        //cout << "Destructor for AbstractPlayer got called." << endl;
    }

    // Methods for AbstractPlayer:
    virtual bool isDrawing() const = 0;
    bool isBusted();
    Hand* getPlayerHand();

protected:
    // Fields - Set to protected to avoid the client from modifying the AbstractPlayer.
    Hand *aHand; // The Hand of the Player.
};



/**
 * AbstractPlayer method: isBusted
 * 
 * AbstractPlayer method to return whether the Hand of the AbstractPlayer exceeds a total of 21 points.
 * @return true if the total value of the Hand exceeds 21 points.
 * @return false otherwise.
 * 
 */
bool AbstractPlayer::isBusted()
{
    return(this->aHand->getTotal() > 21);
}



/**
 * AbstractPlayer method: getPlayerHand
 * 
 * AbstractPlayer method to return a pointer to the Player's Hand.
 * @return Hand* a pointer to the Player's Hand.
 * 
 */
Hand* AbstractPlayer::getPlayerHand()
{
    return this->aHand;
}



/**
 * Class HumanPlayer
 * 
 * Inherits from AbstractPlayer (which has protected fields).
 * 
 */
class HumanPlayer: public AbstractPlayer
{
public:
    // Constructor
    HumanPlayer() // Default Constructor
    {
        //cout << "Default constructor for HumanPlayer got called." << endl;
    }

    // Destructor
    virtual ~HumanPlayer()
    {
        // No memory allocated dynamically, nothing to destroy manually.
        //cout << "Destructor for HumanPlayer got called." << endl;
    }

    // Methods for HumanPlayer:
    virtual bool isDrawing() const;
    void announce(int computerScore);
};



/**
 * HumanPlayer method: isDrawing
 * 
 * HumanPlayer method to indicate if the HumanPlayer wants to draw a Card.
 * @return true if the Player wants to draw.
 * @return false otherwise.
 * 
 */
bool HumanPlayer::isDrawing() const
{
    // Prompt the user to check if they want to draw a Card or not.
    char drawAgain = 'y';
    cout << "Do you want to draw? (y/n): ";
    cin >> drawAgain;

    // Make sure the input is correct. If not, ask the question again.
    int repeatQuestion = 0;
    while((drawAgain != 'y') && (drawAgain != 'n'))
    {
        repeatQuestion++;

        // If we asked the user 10 times already and we still have an invalid input, assume the user stops drawing.
        if(repeatQuestion > 9)
        {
            return false;
        }

        // Otherwise, ask again.
        cout << "error: Invalid input." << endl << "Do you want to draw? (y/n): ";
        cin >> drawAgain;
    }

    // Return the appropriate boolean.
    if(drawAgain == 'y')
    {
        return true;
    }
    else // drawAgain == 'n'
    {
        return false;
    }
}



/**
 * HumanPlayer method: announce
 * 
 * HumanPlayer method to announce if the HumanPlayer won, lost or had a push situation.
 * 
 */
void HumanPlayer::announce(int computerScore)
{
    // We check if the Player has busted.
    if(this->isBusted())
    {
        cout << "Player busts." << endl << "Casino wins." << endl << endl;
    }
    else if(computerScore > 21)
    {
        cout << "Casino busts." << endl << "Player wins." << endl << endl;
    }
    else
    {
        // Else, we check who has the highest score.
        int humanScore = this->getPlayerHand()->getTotal();
        if(humanScore > computerScore)
        {
            cout << "Player wins." << endl << endl;
        }
        else if(humanScore < computerScore)
        {
            cout << "Casino wins." << endl << endl;
        }
        else
        {
            cout << "Push: No one wins." << endl << endl;
        }
    }
}



/**
 * Class ComputerPlayer
 * 
 * Inherits from AbstractPlayer (which has protected fields).
 * 
 */
class ComputerPlayer: public AbstractPlayer
{
public:
    // Constructor
    ComputerPlayer() // Default Constructor
    {
        //cout << "Default constructor for ComputerPlayer got called." << endl;
    }

    // Destructor
    virtual ~ComputerPlayer()
    {
        // No memory allocated dynamically, nothing to destroy manually.
        //cout << "Destructor for ComputerPlayer got called." << endl;
    }

    // Methods for ComputerPlayer:
    virtual bool isDrawing() const;
};



/**
 * ComputerPlayer method: isDrawing
 * 
 * ComputerPlayer method to indicate if the ComputerPlayer wants to draw a Card.
 * @return true if the ComputerPlayer should continue to draw.
 * @return false otherwise.
 * 
 */
bool ComputerPlayer::isDrawing() const
{
    // Return true if the Computer has less than 17 points, false otherwise.
    return (this->aHand->getTotal() <= 16) ? true : false;
}



/**
 * Class BlackJackGame
 * 
 * @param m_deck the Deck used to play the game.
 * @param m_casino the ComputerPlayer.
 * @param m_user the HumanPlayer.
 * 
 */
class BlackJackGame
{
public:
    // Constructor
    BlackJackGame() // Default Constructor
    {
        static Deck deck = Deck();
        this->m_deck = &deck;

        static ComputerPlayer casino = ComputerPlayer();
        this->m_casino = &casino;

        static HumanPlayer user = HumanPlayer();
        this->m_user = &user;
        //cout << "Default constructor for BlackJackGame got called." << endl;
    }

    // Destructor
    ~BlackJackGame()
    {
        //cout << "Destructor for BlackJackGame got called." << endl;
    }

    // Method for BlackJackGame:
    void play();


private:
    // Fields - Set to private to avoid the client from modifying the BlackJackGame.
    Deck *m_deck; // The Deck used to play the game.
    ComputerPlayer *m_casino; // The ComputerPlayer.
    HumanPlayer *m_user; // The HumanPlayer.
};



/**
 * BlackJackGame method: play
 * 
 * BlackJackGame method to play a game of BlackJack.
 * 
 */
void BlackJackGame::play()
{
    // We first populate and shuffle the Deck.
    this->m_deck->populate(); // Note that populate also resets the Deck (if it was previously used).
    this->m_deck->shuffle();
    this->m_deck->shuffle(); // Shuffle twice - no cheating >:(.
    this->m_deck->shuffle(); // Actually... third time's the charm :)

    // Pointer variables
    Hand *humanHand = this->m_user->getPlayerHand(); // Hand of the Player.
    Card** humanListOfCards = humanHand->getListOfCards(); // Cards of the Player.

    Hand *computerHand = this->m_casino->getPlayerHand(); // Hand of the Casino.
    Card** computerListOfCards = computerHand->getListOfCards(); // Cards of the Casino.

    // We make sure the Hands of both Players are empty - no cheating >:(.
    humanHand->clear();
    computerHand->clear();

    // Deal 2 Cards to the user.
    this->m_deck->deal(humanHand);
    this->m_deck->deal(humanHand);

    // Deal 1 Card to the casino.
    this->m_deck->deal(computerHand);

    // Display the casino's Card.
    cout << "Casino: ";
    computerListOfCards[0]->displayCard();
    cout << " [" << computerHand->getTotal() << "]" << endl;

    // Display the user's Cards.
    cout << "Player: ";
    humanListOfCards[0]->displayCard();
    cout << " ";
    humanListOfCards[1]->displayCard();
    cout << " [" << humanHand->getTotal() << "]" << endl;

    // Prompt the user to draw until they don't want to draw anymore.
    bool keepOnDrawing = this->m_user->isDrawing(); // If the current Player still wants to draw.
    bool humanBusted = false; // If the Player has busted (score over 21).
    int cardsDrawed = 0; // Total Cards drawed by the current Player.
    while(keepOnDrawing)
    {
        // Deal a Card.
        this->m_deck->deal(humanHand);

        // Increment cardsDrawed.
        cardsDrawed++;

        // Display the user's Hand.
        cout << "Player: ";
        humanListOfCards[0]->displayCard(); // Initial Card #1.
        cout << " ";
        humanListOfCards[1]->displayCard(); // Initial Card #2.
        for(int i = 0; i < cardsDrawed; i++) // Cards drawed by the Player.
        {
            cout << " ";
            humanListOfCards[2 + i]->displayCard();
        }
        cout << " [" << humanHand->getTotal() << "]" << endl;

        // Check that the Player has not busted yet.
        humanBusted = this->m_user->isBusted();
        if(humanBusted)
        {
            this->m_user->announce(0); // We can provide any int since the Player busted anyway.
            break;
        }

        // Ask the user if they want to draw again.
        keepOnDrawing = this->m_user->isDrawing();
    }

    // If the Player has not busted (decided to stop drawing), the casino plays.
    // Note that otherwise, the Player has already busted (announce method already called), and the game is already over.
    if(!humanBusted)
    {
        int playerScore = humanHand->getTotal();
        cardsDrawed = 0;
        keepOnDrawing = (computerHand->getTotal() < playerScore);
        bool computerBusted = this->m_casino->isBusted(); // If the Casino has busted (score over 21).

        // The casino draws as long as its Hand is weaker than the user's.
        while(keepOnDrawing)
        {
            // Deal a Card.
            this->m_deck->deal(computerHand);

            // Increment cardsDrawed.
            cardsDrawed++;

            // Display the user's Hand.
            cout << "Casino: ";
            computerListOfCards[0]->displayCard(); // Initial Card #1.
            for(int i = 0; i < cardsDrawed; i++) // Cards drawed by the casino.
            {
                cout << " ";
                computerListOfCards[1 + i]->displayCard();
            }
            cout << " [" << computerHand->getTotal() << "]" << endl;

            // Check that the casino has not busted yet.
            computerBusted = this->m_casino->isBusted();
            if(computerBusted)
            {
                break;
            }

            // Check if the casino should draw again.
            keepOnDrawing = (computerHand->getTotal() < playerScore);
        }

        // Display the results.
        int computerTotalScore = computerHand->getTotal();
        cout << "Casino has " << computerTotalScore << " points." << endl << "Player has " << humanHand->getTotal() << " points." << endl;
        this->m_user->announce(computerTotalScore);
    }
}



// Main function
int main()
{
    cout << "Welcome to the Comp322 Blackjack table!" << endl;
    BlackJackGame game;
    // The main loop of the game
    bool playAgain = true;
    char answer = 'y';
    while (playAgain)
    {
        game.play();
        // Check whether the player would like to play another round
        cout << "Would you like another round? (y/n): ";
        cin >> answer;
        //cout << endl << endl;
        playAgain = (answer == 'y' ? true : false);
    }
    cout << "Gave over!";
    return 0;
}

