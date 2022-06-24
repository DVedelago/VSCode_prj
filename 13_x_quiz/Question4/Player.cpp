#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Player.h>


// Card Player::drawCard(Deck& deck) const
// {
//     return ( deck.dealCard() );
// }
void Player::drawCard(Deck& deck) 
{
    Card c{deck.dealCard()};
    m_playerScore += c.value();
    c.print();
    std::cout << ' ';
}

// int Player::addScore(Card& card_dealt) 
// {
//     return( m_playerScore += card_dealt.value() );
// }

bool Player::isBust() const
{
    return ( m_playerScore>g_maximumScore );
}

int Player::handScore() const
{
    return m_playerScore;
}