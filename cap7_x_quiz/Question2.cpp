#include <iostream>
#include <cassert>
#include <cmath> // for std::sqrt

bool isPrime(int x)
{
    // if x is negative, 0, or 1, the number is not prime
    if (x <= 1)
        return false;

    // If the number is 2 or higher, we need to see if we can find a divisor
    // We only need to test the numbers between 2 and sqrt(x)
    // since a non-prime number must have at least one divisor
    // less than or equal to its square root.
    // It's fine (just less efficient) if you used test <= x for this exercise

    for (int test{ 2 }; test <= std::sqrt(x); ++test)
    {
        if (x % test == 0) // if x is evenly divisible
            return false; // then this number isn't prime
    }

    return true; // if we didn't find any divisors, then x must be prime
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}