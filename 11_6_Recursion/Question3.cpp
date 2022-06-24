#include <iostream>

int dec_to_bin(int n)
{
    if (n==0)
        return n;
    else 
        dec_to_bin(n/2);
        std::cout << n % 2 << ' ';
}

int main()
{
    int x{};
    std::cout << "Enter a positive integer number: ";
    std::cin >> x;

    dec_to_bin(x);
}

