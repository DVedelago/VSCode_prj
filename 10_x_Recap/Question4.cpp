#include <iostream>

void printCString(const char* str)
{

    while (*str != '\0')
    {
        std::cout << *str <<'\n';
        ++str;
    } 
}

int main()
{
    printCString("Hello world");
    std::cout <<'\n';

    return 0;
}