#include "Stack.h"

Stack::Stack(): pHead(nullptr) {}

Stack::~Stack()
{
    freeStack();
}

Stack::Stack(const Stack &rS)
{
    copyStack(rS);
}

Stack & Stack::operator=(const Stack &rS)
{
    if (this == &rS)
        return *this;

    freeStack();
    copyStack(rS);
    return *this;
}

int Stack::peek() const
{
    return pHead->data;
}

void Stack::insert(const int &rK)
{
    Node *pNew = new Node;
    pNew->data = rK;
    pNew->pNext = pHead;
    pHead = pNew;
}

void Stack::remove()
{
    Node *pTemp = pHead->pNext;
    delete pHead;
    pHead = pTemp;
}

void Stack::copyStack(const Stack &rS)
{
    if (rS.pHead == nullptr)
        return;

    Stack reverse;
    Node *pCurrent = rS.pHead;
    while (pCurrent != nullptr)
    {
        reverse.insert(pCurrent->data);
        pCurrent = pCurrent->pNext;
    }

    pCurrent = reverse.pHead;
    while (pCurrent != nullptr)
    {
        insert(pCurrent->data);
        pCurrent = pCurrent->pNext;
    }
}

void Stack::freeStack()
{
    if (pHead == nullptr)
        return;

    Node *pTemp;
    while (pHead->pNext != nullptr)
    {
        pTemp = pHead->pNext;
        delete pHead;
        pHead = pTemp;
    }
    delete pHead;
    pHead = nullptr;
}

