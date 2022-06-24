#include <iostream>
#include <C:\Users\vedelagod\Documents\VSCode_prj\13_x_quiz\Question1\Point2d.h>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.printPoint2d();
    second.printPoint2d();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}