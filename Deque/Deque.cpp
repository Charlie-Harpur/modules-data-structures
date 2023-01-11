#include "Deque.h"

Deque::Deque(): pHead(nullptr), pTail(nullptr) {}

Deque::~Deque()
{
    freeDeque();
}

Deque::Deque(const Deque &rD)
{
    copyDeque(rD);
}

Deque & Deque::operator=(const Deque &rD)
{
    if (this == &rD)
        return *this;

    freeDeque();
    copyDeque(rD);
    return *this;
}

int Deque::peekHead() const
{
    return pHead->data;
}

int Deque::peekTail() const
{
    return pTail->data;
}

int Deque::peek(bool head) const
{
    if (head)
        return pHead->data;
    return pTail->data;
}

void Deque::insertHead(const int &rK)
{
    Node *pNew = new Node;
    pNew->data = rK;
    pNew->pNext = pHead;
    pHead->pPrevious = pNew;
    pHead = pNew;
}

void Deque::insertTail(const int &rK)
{
    Node *pNew = new Node;
    pNew->data = rK;
    pNew->pPrevious = pTail;
    pTail->pNext = pNew;
    pTail = pNew;
}

void Deque::insert(const int &k, bool head)
{
    Node *pNew= new Node;
    pNew->data = k;

    if (pHead == nullptr)
    {
        pHead = pNew;
        pTail = pNew;
        return;
    }

    if (head)
    {
        pNew->pNext = pHead;
        pHead->pPrevious = pNew;
        pHead = pNew;
        return;
    }

    pNew->pPrevious = pTail;
    pTail->pNext = pNew;
    pTail = pNew;
}

void Deque::removeHead()
{
    Node *pTemp = pHead->pNext;
    delete pHead;
    pHead = pTemp;
}

void Deque::removeTail()
{
    Node *pTemp = pTail->pPrevious;
    delete pTail;
    pTail = pTemp;
}

void Deque::remove(bool head)
{
    Node *pTemp;
    if (head)
    {
        pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        return;
    }

    pTemp = pTail;
    pTail = pTail->pPrevious;
    delete pTemp;
}

void Deque::copyDeque(const Deque &rD)
{
    Node *pCurrent = rD.pHead;

    while (pCurrent != nullptr)
    {
        insert(pCurrent->data);
        pCurrent = pCurrent->pNext;
    }
}

void Deque::freeDeque()
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
    return;
}
