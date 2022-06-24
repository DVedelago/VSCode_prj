#include <iostream>

struct User_Operation
{
    int num1{};
    int num2{};
    char op{};
};

User_Operation math_user_input()
{
    User_Operation elements{};

    std::cout << "Please enter the 1st integer: ";
    std::cin >> static_cast<int>(elements.num1);
    
    std::cout << "Please enter the 1st integer: ";
    std::cin >> static_cast<int>(elements.num2);
    
    
    bool check_operation{false};
    
    while (!check_operation)
    {
        std::cout << "Please enter a valid operator (+, -, *, /): ";
        std::cin >> elements.op;

        switch (math_operator)
        {
            case '+':
            case '-':
            case '*':
            case '/': check_operation = true;
    
            break;
        
        default: check_operation = false;
            break;
        }
    }

    return elements;
}

auto calculator(User_Operation& porcodio)
{
    switch (porcodio.op)
    {
        case '+':   return porcodio.num1 + porcodio.num2; 
        case '-':   return porcodio.num1 - porcodio.num2;
        case '*':   return porcodio.num1 * porcodio.num2;
        case '/':   return porcodio.num1 / porcodio.num2;
            
    default:
        break;
    }   
}

using ArithmeticFunction = std::function<int(int, int)>;


int main()
{

    
    
}