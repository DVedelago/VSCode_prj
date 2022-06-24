#pragma once


#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Deck.h>


// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };



class Player
{
public:

	//Card drawCard(Deck& deck) const;
	void drawCard(Deck& deck);
	//int addScore(Card& card_dealt);
	int handScore() const;
	bool isBust() const;


	Player(int score =0) : m_playerScore{score} {}
	~Player() = default;

private:

	int m_playerScore{};

};


