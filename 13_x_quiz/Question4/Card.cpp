#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question4\Card.h>



void Card::print() const
{
    switch (m_rank)
    {
    case r_2:        std::cout << '2';   break;
    case r_3:        std::cout << '3';   break;
    case r_4:        std::cout << '4';   break;
    case r_5:        std::cout << '5';   break;
    case r_6:        std::cout << '6';   break;
    case r_7:        std::cout << '7';   break;
    case r_8:        std::cout << '8';   break;
    case r_9:        std::cout << '9';   break;
    case r_10:       std::cout << 'T';   break;
    case r_Jack:     std::cout << 'J';   break;
    case r_Queen:    std::cout << 'Q';   break;
    case r_King:     std::cout << 'K';   break;
    case r_Ace:      std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (m_suit)
    {
    case clubs:          std::cout << 'C';   break;
    case diamonds:       std::cout << 'D';   break;
    case hearts:         std::cout << 'H';   break;
    case spades:         std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}

int Card::value() 
{
    switch (m_rank)
    {
    case r_2:        return 2;
    case r_3:        return 3;
    case r_4:        return 4;
    case r_5:        return 5;
    case r_6:        return 6;
    case r_7:        return 7;
    case r_8:        return 8;
    case r_9:        return 9;
    case r_10:       return 10;
    case r_Jack:     return 10;
    case r_Queen:    return 10;
    case r_King:     return 10;
    case r_Ace:      return 11;

    default:
        assert(false && "should never happen");
        return 0;
    }
}