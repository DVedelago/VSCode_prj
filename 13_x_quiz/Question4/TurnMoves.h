#pragma once


#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Player.h>



class TurnMoves
{
public:
	
	static bool dealerTurn(Player& dealer, Deck& deck);
	static bool playerWantsHit();
	static bool playerTurn(Player& player, Deck& deck);
	static bool playBlackjack(Deck& deck);
	
};
