#include "Queue.h"

Queue::Queue(): pHead(nullptr), pTail(nullptr) {}

Queue::~Queue()
{
    freeQueue();
}

Queue::Queue(const Queue &rQ)
{
    copyQueue(rQ);
}

Queue & Queue::operator=(const Queue &rQ)
{
    if (this == &rQ)
        return *this;
    freeQueue();
    copyQueue(rQ);
    return *this;
}

int Queue::peek() const
{
    return pHead->data;
}

void Queue::insert(const int &rK)
{
    Node *pNew = new Node;
    pNew->data = rK;

    if (pHead == nullptr)
    {
        pHead = pNew;
        pTail = pHead;
        return;
    }
    pTail->pNext = pNew;
    pTail = pNew;
}

void Queue::remove()
{
    if (pHead == nullptr)
        return;

    if (pHead->pNext == nullptr)
    {
        delete pHead;
        pHead = nullptr;
        pTail = nullptr;
        return;
        pTail = nullptr;
    }

    Node *pTemp = pHead;
    pHead = pHead->pNext;
    delete pTemp;
}

void Queue::copyQueue(const Queue &rQ)
{
    Node *pCurrent = rQ.pHead;

    while (pCurrent != nullptr)
    {
        insert(pCurrent->data);
        pCurrent = pCurrent->pNext;
    }
}

void Queue::freeQueue()
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
    pTail = nullptr;
}
