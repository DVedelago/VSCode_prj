#include <iostream>

constexpr double Gravity = 9.81;

int getHeight()
{
    std::cout << "Type in the Height:";
    
    int height{};
    std::cin >> height;

    return height;
}


void HeightAfterTime(int h, int s)
{
    // 1/2(g*(t^2))

    float distanceFromGround = h-((Gravity*(s*s))/2);
    
    if(distanceFromGround<0)
    {
        distanceFromGround = 0;
    }
    std::cout << "The Height of the ball after " << s << "second(s) is: " << distanceFromGround << " meters from the ground.\n";

}


int main()
{
    int TowerHeight = getHeight();

    for(int i = 0; i < 5; i++)
    {
        HeightAfterTime(TowerHeight, i+1);
    }
    
}