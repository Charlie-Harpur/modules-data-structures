#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList &rL);
        LinkedList & operator=(const LinkedList &rL);

        bool operator==(const LinkedList &rL) const;

        void insert(const int &rk, bool head = true);  //Adds new elemet with value rk as head of list if head is true, otherwise adds to tail
       
        //void insert(const ListNode *pN);

        void print(bool reverse = false) const;

    private:
        struct ListNode
        {
            int data;
            ListNode *pNext = NULL;
            ListNode *pPrevious = NULL;
        };
        
        ListNode *pHead;
        ListNode *pTail;

        ListNode *copyList(const ListNode *pN);
        void freeList();
};

#endif