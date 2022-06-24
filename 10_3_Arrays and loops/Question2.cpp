#include <iostream>
#include <iterator>
#include <limits>


int main()
{
    int num_test{};

    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> num_test;
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }

    } while (num_test<1 || num_test >9);
    
           
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)
    {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
           
    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)     
    {   
        if (num_test == array[i])
        {
            std::cout << "The number " << num_test << " has index " << i ;
            break;
        }
        
    }
    
    
    return 0;
}

