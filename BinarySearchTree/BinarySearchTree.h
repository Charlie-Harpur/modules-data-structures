#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <iostream>
/// @brief Simple AVL binary tree
class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &rT);
        BinarySearchTree & operator=(const BinarySearchTree &rT);

        /// @brief Inserts rK into the tree
        /// @param rK Value to be inserted
        void insert(const int &rK);

        /// @brief Removes rK from tree
        /// @param rK Value to be removed
        void remove(const int &rK);

        /// @brief Searches tree for value rK
        /// @param rK Value to search for
        /// @return True if rK is in the tree, false if not
        bool search(const int &rK) const;

        /// @brief Finds value of predecessor of rK
        /// @param rK Value to find predecessor of
        /// @return Value of predecessor, or rK if no predecessor in the list
        int predecessor(const int &rK) const;

        /// @brief Finds value of successor of rK
        /// @param rK Value to find successor of
        /// @return Value of successor, or rK if it has no successor, or NULL
        /// if rK is not in tree
        int successor(const int &rK) const;

    private:
        struct Node
        {
            int height = 1;     //Height from bottom of largest subtree
            int data = 0;
            Node *pLeft = nullptr; //Child that is less than node
            Node *pRight = nullptr;//Child that is greater than node
        };

        Node *pRoot;

        /// @brief Rotates pN clockwise with its left child
        /// @param pN Node to rotate
        /// @return Root of new rotated tree
        Node * rotateRight(Node *pN);

        /// @brief Rotates pN anti-clockwise with its right child
        /// @param pN Node to rotate
        /// @return Root of new rotated tree
        Node * rotateLeft(Node *pN);

        /// @brief Balances tree with root pN
        /// @param pN Tree to be balanced
        /// @return Root of balanced tree
        Node * balanceTree(Node *pN);

        /// @brief Finds node that is closest to and greater than pN
        /// @param pN Node to find successor of
        /// @return Successor, or if no successor pN
        Node * getSuccessor(Node *pN) const;

        /// @brief Finds node that is closest to and less than pN
        /// @param pN Node to find predecessor of
        /// @return Predecessor, or if no predecessor pN
        Node * getPredecessor(Node *pN) const;

        /// @brief Inserts rK into tree with root pN and balances new tree
        /// @param pN Root of tree to insert into
        /// @param rK Value to insert
        /// @return Root of sorted tree
        Node * insertNode(Node *pN, const int &rK);

        /// @brief Removes rK from tree with root pN and balances new tree
        /// @param pN Root of tree to remove from
        /// @param rK Value to remove from tree
        /// @return Root of rebalanced tree with rK removed
        Node * removeNode(Node *pN, const int &rK);

        /// @brief Finds node with value rK in tree with root pN
        /// @param pN Tree to find in
        /// @param rK Value to look for
        /// @return Node with value rK in pN or NULL if no node exists
        Node * find(Node *pN, const int &rK) const;

        /// @brief Finds parent of node pN in the tree
        /// @param pN Node to find parent of
        /// @return Parent of pN or NULL if pN has no parent in the tree
        Node * findParent(Node *pN) const;

        /// @brief Copies tree with root pN
        /// @param pN Root of tree to be copied
        /// @return Root of copy
        Node * copyTree(Node *pN);

        /// @brief Deletes tree with root pN
        /// @param pN Root of tree to be deleted
        void freeTree(Node *pN);

        /// @brief Calculates and sets height of pN
        /// @param pN Node to set height
        void setHeight(Node *pN);

        /// @brief Gets height of pN;
        /// @param pN Node to get Height
        /// @return Height of pN or NULL if pN is NULL;
        int getHeight(Node *pN) const;

        /// @brief Calculates balance factor of pN;
        /// @param pN Node to calculate balance factor
        /// @return Balance factor of pN
        int getBalanceFactor(Node *pN) const;
};

#endif
