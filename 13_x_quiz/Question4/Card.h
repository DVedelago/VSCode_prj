#pragma once

#include <iostream>
#include <cassert>
#include <cassert>



class Card
{
public:
	
	enum Suit
	{
		spades,
		hearts,
		clubs,
		diamonds,

		max_suits,
	};
	
	enum Rank
	{
		r_2,
		r_3,
		r_4,
		r_5,
		r_6,
		r_7,
		r_8,
		r_9,
		r_10,
		r_Jack,
		r_Queen,
		r_King,
		r_Ace,

		max_ranks,
	};

	//constructors
	Card() = default;
	Card(Rank rank, Suit suit)
		: m_rank{rank}, m_suit{suit}
	{
	}

	//public fncts
	void print() const;
    int value() ;

    


private:

	Suit m_suit{};
	Rank m_rank{};

};


