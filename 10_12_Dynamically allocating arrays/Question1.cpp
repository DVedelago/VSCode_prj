#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    std::cout << "How many names would you like to enter? \n";
    int length{};
    std::cin >> length;

    auto* names{ new std::string[length] };
    
    //get the names
    for (int i=0; i < length; ++i)
    {
        std::cout <<"Enter Name #" << i+1 << ": ";
        std::getline(std::cin >> std::ws, *(names+i));
    }
    
    //sort the names
    std::sort(names, names+length);
    
    //print the sorted names
    std::cout << "Here is the sorted list: \n";

    for (int i = 0; i < length; ++i)
    {
        std::cout << "Name #" << i+1 <<": " << *(names+i) << '\n';
    }    
}

