#include <iostream>

int factorial(int a)
{
    if (a==0)   
        return 1;
    else 
        return factorial(a-1)*a;
}

int main()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << factorial(i) << '\n';
    }
    
}