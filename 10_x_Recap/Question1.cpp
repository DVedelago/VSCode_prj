#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

enum TypeOFItems
{
    healthPotions,
    torches,
    arrows,
    max_items,
};

//aliasing inventory_t to instantiate array of {TypeOFItems::max_items} size
using inventory_t = std::array<int, TypeOFItems::max_items>;

int countTotalItems(const inventory_t& arr)
{
    return std::reduce(arr.begin(), arr.end());
}

int main()
{

    inventory_t playerItems{2, 5, 10};

    std::cout << "The Player has " << countTotalItems(playerItems) << " item(s) in total. \n";

    std::cout << "The player has " << playerItems[TypeOFItems::torches] << " Torch(es). \n";

    return 0;
}