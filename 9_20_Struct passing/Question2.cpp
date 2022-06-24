#include <iostream>
#include <string_view>

struct Fraction
{
    int numerator;
    int denominator;
};

Fraction getFraction()
{
    Fraction frac{};
    std::cout << "Enter the numerator: ";
    std::cin >> frac.numerator;
    
    std::cout << "Enter the denominator: ";
    std::cin >> frac.denominator;
    
    return frac;
}

Fraction multiplyFractions(const Fraction& a, const Fraction& b)
{
    return {a.numerator*b.numerator , a.denominator*b.denominator};
}

void printFraction(Fraction f)
{
    std::cout << f.numerator << "/" << f.denominator;
}

int main()
{
    Fraction f1 {getFraction()};
    Fraction f2 {getFraction()};
    
    std::cout << "Your fractions multiplied together: ";

    printFraction( multiplyFractions(f1, f2) );
    

    return 0;
}
