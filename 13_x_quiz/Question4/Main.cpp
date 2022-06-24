

#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\TurnMoves.h>

int main()
{
    Deck deck;

    deck.shuffleDeck();


    if (TurnMoves::playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}