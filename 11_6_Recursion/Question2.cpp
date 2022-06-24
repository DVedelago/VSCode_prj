#include <iostream>

int summation(int n)
{
    if(n<=10) return n;
    else return summation(n/10) + n % 10;
}

int main()
{
    std::cout << summation(112);
}