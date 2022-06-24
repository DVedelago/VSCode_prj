#include<iostream>
#include<utility>
#include<iterator>

int main() 
{
    //int array []{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    int array [] { 9,8,7,6,5,4,3,2,1};

    constexpr int arr_length { static_cast<int>(std::size(array)) };
    
    //just print the array before sorting it

    std::cout << "The array before the sorting is: \n";

    for (int i = 0; i < arr_length; i++)
    {
        std::cout << array[i] << ' ';
    }
    
    std::cout << '\n';


    //bubble sort process

    for (int i = 0; i < arr_length - 1; i++)
    {
        bool swhappened { false };

        for (int j = 0; j < (arr_length - i -1); j++)
        {
            if (array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
                swhappened = true;
            }
        }     

        if (!swhappened)
        {
            std::cout << "Early termination on iteration " << i+1 <<'\n';
            break;
        }
        
    }
    


    //sorted array print
    
    std::cout << "The array after the sorting is: \n";

    for (int i = 0; i < static_cast<int>(std::size(array)); i++)
    {
        std::cout << array[i] << ' ';
    }
}