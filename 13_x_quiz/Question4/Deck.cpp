#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Deck.h>

Deck::Deck()
{
    index_type index{ 0 };

    for (int suit{ 0 }; suit < static_cast<int>(Card::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Card::max_ranks); ++rank)
        {
            m_deck.at(index) = {static_cast<Card::Rank>(rank),static_cast<Card::Suit>(suit)};
            ++index;
        }
    }//ctor
}

void Deck::shuffleDeck() 
{
    static std::mt19937 mers_twist
        {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    
    std::shuffle(m_deck.begin(), m_deck.end(), mers_twist);

}

void Deck::printDeck() 
{
    for(const auto& card : m_deck)
    {
        card.print();
        std::cout <<' ';
    }

    std::cout <<'\n';
}

const Card& Deck::dealCard()
{
   	assert(m_cardIndex < m_deck.size());
    return m_deck.at(m_cardIndex++);
}