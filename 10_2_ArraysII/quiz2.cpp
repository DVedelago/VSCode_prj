#include <iostream>

namespace Animals
{
    enum Animals
    {
        chicken, 
        dog, 
        cat,
        elephant,
        duck,
        snake,
        num_of_animals
    };
}

int main()
{
    
    int legs[Animals::num_of_animals] {2, 4, 4, 4, 2, 0};

    std::cout << "An Elephant has " << legs[Animals::elephant] << " legs.\n ";

    return 0;

}