#include <iostream>
#include <iterator>

int main() 
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    for(int index{0}; index <= (static_cast<int>(std::size(array))); ++index)
        std::cout << array[index] << "   ";
    
    std::cout<<'\n';

    return 0;
}