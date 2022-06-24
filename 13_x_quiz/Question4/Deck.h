#pragma once

#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Card.h>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>


using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;



class Deck
{
public:
	Deck();
	~Deck() = default;

	void shuffleDeck() ;
	void printDeck() ;
	const Card& dealCard();


private:

	deck_type m_deck{};
	index_type m_cardIndex {0};

};

