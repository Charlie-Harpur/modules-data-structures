#ifndef STACK_H
#define STACK_H

class Stack
{
    public:
        Stack();
        ~Stack();
        Stack(const Stack &rS);
        Stack & operator=(const Stack &rS);

        /// @brief Peeks head of queue
        /// @return Key in head
        int peek() const;

        /// @brief Inserts rK at head of queue
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

        /// @brief Inserts rS at head of list
        /// @param rS Stack to add
        void copyStack(const Stack &rS);

        /// @brief Frees all elements in queue
        void freeStack();

};

#endif
