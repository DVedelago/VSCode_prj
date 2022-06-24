// ASCII codes for alphabet letters
// 'a' = 97
// 'z' = 122

#include <iostream>

int main()
{
    int iii{97};
    while (iii<=122)
    {
        char lett{iii};
        std::cout << lett << ' ';

        iii++;
    }
    
}
