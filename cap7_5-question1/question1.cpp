#include <iostream>

double calculate(int x, int y, char s)
{
    switch (s)
    {
    case '+':
        return (x + y);
        break;
    
    case '*':
        return (x * y);
        break;
    
    case '-':
        return (x - y);
        break;

    case '/':
        return (static_cast<double>(x) / static_cast<double>(y));
        break;

    default:
        std::cout << "Operazione non ammessa"; 
        return 0;
    }
}

int main()
{
    
    std::cout << "Enter an integer:" ;
    int a{};
    std::cin >> a;

    std::cout << "Enter another integer:";
    int b{};
    std::cin >> b;

    std::cout << "Enter the operator:";
    char c{};
    std::cin >> c;

    std::cout << a << ' ' << c << ' ' << b << " is " << calculate(a, b, c);

    return 0;
}