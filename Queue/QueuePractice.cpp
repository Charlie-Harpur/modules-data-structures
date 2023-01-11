#include "Queue.h"
#include <iostream>

using std::cout, std::endl;

int main()
{
    Queue test;

    for (int i = 0; i < 15; i++)
        test.insert(i);

    for (int i = 0; i < 15; i++)
    {
        cout << test.peek() << endl;
        test.remove();
    }

    return 0;
}

