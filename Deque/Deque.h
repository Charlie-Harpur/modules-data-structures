#ifndef DEQUE_H
#define DEQUE_H

class Deque
{
    public:
        Deque();
        ~Deque();
        Deque(const Deque &rD);
        Deque & operator=(const Deque &rD);

        /// @brief Peeks head of Deque
        /// @return pHead value
        int peekHead() const;

        /// @brief Peeks tail of Deque
        /// @return pTail value
        int peekTail() const;

        /// @brief Peeks either head or tail of Deque
        /// @param head Chooses whether to look at head or tail
        /// @return pHead value if head is true otherwise pTail value
        int peek(bool head = true) const;

        /// @brief Inserts value at head of Deque
        /// @param rK Value to be inserted
        void insertHead(const int &rK);

        /// @brief Inserts value at tail of Deque
        /// @param rK Value to be inserted
        void insertTail(const int &rK);

        /// @brief Inserts value at either head or tail of Deque
        /// @param rK Value to be inserted
        /// @param head Chooses whether to insert at head or tail
        void insert(const int &rK, bool head = true);

        /// @brief Removes head of Deque
        void removeHead();

        /// @brief Removes tail of Deque
        void removeTail();

        /// @brief Removes either head or tail of Deque
        /// @param head Chooses whether to remove head or tail
        void remove(bool head = true);

    private:
        struct Node
        {
            int data;
            Node *pNext = nullptr;
            Node *pPrevious = nullptr;
        };

        Node *pHead;
        Node *pTail;

        void copyDeque(const Deque &rD);
        void freeDeque();
};

#endif
