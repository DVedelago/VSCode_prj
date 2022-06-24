#include <iostream>
#include <iterator>
//#include <algorithm> // std::find

auto* find( int* start, int* end, int test )
{
    for (int* p{start}; p != end; ++p)
    {
        if (*p == test)
        {
            return p;
        }
        
    }
    
    return end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ find(std::begin(arr), std::end(arr), 20) };

    //implemented using std::find
    //auto found{ std::find(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}