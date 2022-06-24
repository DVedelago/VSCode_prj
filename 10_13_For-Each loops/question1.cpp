#include <iostream>
#include <string_view>
#include <string>
#include <sstream>


int main()
{
    constexpr std::string_view namesPool[] {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";

    std::string username{};
    std::getline (std::cin, username);

    bool isFound {false};

    for (auto& name : namesPool)
    {
        if (username == name)
        {
            isFound = true;
            break;
        }

    }
    
    if (isFound)
    {
        std::cout << username << " was found.";
    }

    else std::cout << username << " was not found.";
    
}