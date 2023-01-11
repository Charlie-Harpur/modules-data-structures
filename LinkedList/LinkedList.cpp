#include "LinkedList.h"
#include <iostream>

using std::cout, std::endl;

LinkedList::LinkedList(): pHead(NULL), pTail(pHead) {}

LinkedList::~LinkedList()
{
    freeList();
}

LinkedList::LinkedList(const LinkedList &rL)
{
    pTail = pHead = copyList(rL.pHead);
}

LinkedList & LinkedList::operator=(const LinkedList &rL)
{
    if (this == &rL)
        return *this;

    freeList();
    pTail = pHead = copyList(rL.pHead);
    return *this;
}

bool LinkedList::operator==(const LinkedList &rL) const
{
    if (this == &rL)
        return true;
    
    ListNode *pCurrent = pHead, *pCompare = rL.pHead;
    while (pCurrent->data == pCompare->data)
    {
        if(pCurrent == NULL)
            return true;
        pCurrent = pCurrent->pNext;
        pCompare = pCompare->pNext;
    }
    return false;
}

void LinkedList::insert(const int &rK, bool head)
{
    ListNode *tmp = new ListNode;
    tmp->data = rK;

    if(pHead == NULL)
    {
        pHead = pTail = tmp;
        return;
    }

    if (head)
    {
        tmp->pNext = pHead;
        pHead->pPrevious = tmp;
        pHead = tmp;
    }
    else
    {
        tmp->pPrevious = pTail;
        pTail->pNext = tmp;
        pTail = tmp;
    }
}

void LinkedList::print(bool reverse) const
{
    ListNode *pRead;
    if(reverse)
        pRead = pTail;
    else
        pRead = pHead;

    cout << "[ ";
    while(pRead != NULL)
    {
        cout << pRead->data << " ";
        if (reverse)
            pRead = pRead->pPrevious;
        else
            pRead = pRead->pNext;
    }
    cout << "]" << endl;
}

LinkedList::ListNode * LinkedList::copyList(const ListNode *pN)
{
    if (pN == NULL) return NULL;
    const ListNode *pCurrent;
    ListNode *pHead, *pCurrentCopy, *pPreviousCopy = NULL;
    pCurrent = pN;
    pCurrentCopy = new ListNode;
    pHead = pCurrentCopy;

    while (pCurrent != NULL)
    {
        pCurrentCopy->pPrevious = pPreviousCopy;
        pCurrentCopy->data = pCurrent->data;
        pPreviousCopy = pCurrentCopy;
        pCurrent = pCurrent->pNext;
        pCurrentCopy = new ListNode;
        pPreviousCopy->pNext = pCurrentCopy;
    }
    delete pCurrentCopy;
    pPreviousCopy->pNext = NULL;

    return pHead;
}

void LinkedList::freeList()
{
    if (pHead == NULL)
        return;
    
    while (pHead->pNext != NULL)
    {
        ListNode *tmp;
        tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    delete pHead;
    pHead = NULL;
}