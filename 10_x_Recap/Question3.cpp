#include <array>
#include <iostream>

using twointarray = std::array<int, 2>;

void swap(twointarray& arr)
{
    int tempvalue{arr[0]};

    arr[0]=arr[1];
    arr[1]=tempvalue;
}

int main()
{
    twointarray myarray1 {0, 1};

    for (auto &i : myarray1)
    {
        std::cout << i << '\n';
    }
    
    std::cout << '\n';

    swap(myarray1);

    for (auto &i : myarray1)
    {
        std::cout << i << '\n';
    }
    
    return 0;
}