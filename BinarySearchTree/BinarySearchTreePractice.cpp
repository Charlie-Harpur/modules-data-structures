#include "BinarySearchTree.h"
#include <iostream>

using std::cout, std::endl;

int main()
{
    BinarySearchTree testTree;
    for (int i = 0; i < 10; i++)
    {
        testTree.insert(i);
    }
    cout << "TEST" << endl;
    return 0;
}
