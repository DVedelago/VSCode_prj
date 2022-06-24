/*
Here are the rules for our version of Blackjack:

    The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
    The player gets two cards to start.
    The player goes first.
    A player can repeatedly “hit” or “stand”.
    If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
    If the player “hits”, they get another card and the value of that card is added to their total score.
    An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, we’ll count it as an 11 here.
    If the player goes over a score of 21, they bust and lose immediately.
    The dealer goes after the player.
    The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
    If the dealer goes over a score of 21, they bust and the player wins immediately.
    Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses (we’ll consider ties as dealer wins for simplicity).

In our simplified version of Blackjack, we’re not going to keep track of which specific cards the player and the dealer have been dealt. We’ll only track the sum of the values of the cards they have been dealt for the player and dealer. This keeps things simpler.

Start with the code you wrote in quiz #6. Create a function named playBlackjack(). This function should:

    Accept a shuffled deck of cards as a parameter.
    Implement Blackjack as defined above (note: you can define other functions to help with this).
    Returns true if the player won, and false if they lost.

Also write a main() function to play a single game of Blackjack.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <cassert>



enum CardRanks
{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    Jack,
    Queen,
    King,
    Ace,

    max_ranks

};

enum CardSuits
{
    spades,
    hearts,
    clubs,
    diamonds,

    max_suits
};

struct Card
{
    CardRanks rank{};
    CardSuits suit{};
};

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case two:   std::cout << '2'; break;
    case three: std::cout << '3'; break;
    case four:  std::cout << '4'; break;
    case five:  std::cout << '5'; break;
    case six:   std::cout << '6'; break;
    case seven: std::cout << '7'; break;
    case eight: std::cout << '8'; break;
    case nine:  std::cout << '9'; break;
    case ten:   std::cout << 'T'; break;
    case Jack:  std::cout << 'J'; break;
    case Queen: std::cout << 'Q'; break;
    case King:  std::cout << 'K'; break;
    case Ace:   std::cout << 'A'; break;
        default:
            std::cout << '?';
            break;
    }
    
    switch (card.suit)
    {
    case spades:    std::cout << 'S'; break;
    case hearts:    std::cout << 'H'; break; 
    case clubs:     std::cout << 'C'; break;
    case diamonds:   std::cout << 'D'; break;
    default:
        std::cout << '?';
        break;
    }
}

//Alias for decks and index
using deck_t = std::array<Card, 52>;
using index_t = deck_t::size_type;


deck_t createDeck()
{
    deck_t newdeck{};
    index_t index{0};

    for (int suit{0}; suit < static_cast<int>(CardSuits::max_suits); ++suit)
    {
        for (int rank{0}; rank < static_cast<int>(CardRanks::max_ranks); ++rank)
        {
            newdeck[index].suit = static_cast<CardSuits>(suit);
            newdeck[index].rank = static_cast<CardRanks>(rank);
            ++index;
        }
        
    }
    
    return newdeck;
}

void printDeck(const deck_t& deck)
{
    for (const auto& i : deck)
    {
        printCard(i);
        std::cout << ' ';
    }

    std::cout << '\n';   
}

void shuffleDeck(deck_t& deck)
{
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(deck.begin(), deck.end(), g);
 
}

int getCardValue(const Card& card)
{
    switch (card.rank)
    {
    case Jack:  
    case Queen: 
    case King:  
    case ten:   return 10; break;

    case two:   return 2; break;
    case three: return 3; break;
    case four:  return 4; break;
    case five:  return 5; break;
    case six:   return 6; break;
    case seven: return 7; break;
    case eight: return 8; break;
    case nine:  return 9; break;

    case Ace:   return 11; break;    

    default:
        assert(false && "should never happen");
        break;
    }
}



// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };


struct Player
{
    int score{};
};


bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_t& deck, index_t& nextCardIndex, Player& player)
{
    while (true)
    {
        if (player.score > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
                player.score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_t& deck, index_t& nextCardIndex, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score < g_minimumDealerScore)
    {
        int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(const deck_t& deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    index_t nextCardIndex{ 0 };

    // Create the dealer and give them 1 card.
    Player dealer{ getCardValue(deck.at(nextCardIndex++)) };

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{ getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex + 1)) };
    nextCardIndex += 2;

    std::cout << "You have: " << player.score << '\n';

    if (playerTurn(deck, nextCardIndex, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score > dealer.score);
}



int main()
{
    auto deck1{createDeck()};

    printDeck(deck1);
    std::cout << '\n';

    shuffleDeck(deck1);
    //printDeck(deck1);

    if (playBlackjack(deck1))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}