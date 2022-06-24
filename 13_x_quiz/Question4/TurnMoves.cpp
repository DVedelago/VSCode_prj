#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\TurnMoves.h>


// Returns true if the dealer went bust. False otherwise.
bool TurnMoves::dealerTurn(Player& dealer, Deck& deck)
{
    // Draw cards until we reach the minimum value.
	while (dealer.handScore() < g_minimumDealerScore)
    {
        std::cout << "The dealer turned up a ";
        dealer.drawCard(deck);

        std::cout << " and now has " << dealer.handScore() << '\n';
        
    }

    // If the dealer's score is too high, they went bust.
	if (dealer.handScore() > g_maximumScore)
	{
		std::cout << "The dealer busted!\n";
		return true;
	}

	return false;
}



bool TurnMoves::playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        while(ch != 'h' && ch != 's')
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



bool TurnMoves::playerTurn(Player& player, Deck& deck)
{
    if(player.handScore() > g_maximumScore)
	{
		std::cout << "You busted!\n";
        return true;
	}
	else
	{
		if (TurnMoves::playerWantsHit())
		{
            std::cout << "You were dealt a " ;
			player.drawCard(deck);
            std::cout << " and now have " << player.handScore() << " in hand. \n";
            return false;
		}
		else
            return false;		
	}
}



bool TurnMoves::playBlackjack(Deck& deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.

    // Create the dealer and give them 1 card.
    Player dealer;
    //Dealer Draw
    dealer.drawCard(deck);
    
    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.handScore() << '\n';



    // Create the player and give them 2 cards.
    Player player;
    std::cout << "( You Were dealt a ";
    player.drawCard(deck);
    std::cout << "). \n";
    //1st Card
    
    std::cout << "( You Were dealt a ";
    player.drawCard(deck);
    std::cout << "). \n";
    //2nd Card

    std::cout << "You have: " << player.handScore() << '\n';

    
    
    if (playerTurn(player, deck))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(dealer, deck))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    //return (player.handScore() > dealer.handScore());



}
