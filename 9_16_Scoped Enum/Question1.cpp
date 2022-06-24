#include <iostream>
#include <string_view>


enum class Animal 
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    ostrich,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::pig:
            return "pig";
            break;
        case Animal::chicken:
            return "chicken";
            break;
        case Animal::goat:
            return "goat";
            break;
        case Animal::cat:
            return "cat";
            break;
        case Animal::dog:
            return "dog";
            break;
        case Animal::ostrich:
            return "ostrich";
            break;

        default:
            return "???";
            break;
    }
}

int numberOfLegs(Animal animal)
{
    switch (animal)
    {
        case Animal::chicken:
        case Animal::ostrich:
            return 2;
            break;

        case Animal::pig:      
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            return 4;
            break; 
            
        default:
            std::cout << "???";
            break;
    }   
}

int main()
{
    std::cout << "A " << getAnimalName(Animal::cat) << " has " << numberOfLegs(Animal::cat) << " legs. \n" ;
    
    std::cout << "A " << getAnimalName(Animal::chicken) << " has " << numberOfLegs(Animal::chicken) << "legs. \n" ;

    return 0;
}