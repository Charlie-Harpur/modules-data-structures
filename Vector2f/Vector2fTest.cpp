#include <iostream>
#include "Vector2f.h"

void printVec(Vector2f test)
{
    std::cout << test.x << " " << test.y <<
    " " << test.getMagnitude() << std::endl;
}

int main()
{
    Vector2f test;
    test.x = 3;
    test.y = 4;

    printVec(test);

    test.normalize();

    printVec(test);

    return 0;
}
