#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    public:
        Queue();
        ~Queue();
        Queue(const Queue &rQ);
        Queue & operator=(const Queue &rQ);

        /// @brief Peeks head of queue
        /// @return Key in Head
        int peek() const;

        /// @brief Inserts rK at tail of queue
        /// @param rK Value to insert
        void insert(const int &rK);

        /// @brief Removes value at head of queue
        void remove();


    private:
        struct Node
        {
            int data = 0;
            Node *pNext = nullptr;
        };

        Node *pHead;
        Node *pTail;

        /// @brief Inserts rQ at end of list
        /// @param rQ Queue to add
        void copyQueue(const Queue &rQ);

        /// @brief Frees all elements in this queue
        void freeQueue();
};

#endif
