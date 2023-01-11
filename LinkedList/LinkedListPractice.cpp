#include "LinkedList.h"

int main()
{
    LinkedList testList;

    for (int i = 0; i < 100; i++)
    {
        testList.insert(i);
    }

    testList.print();

    return 0;
}