#include "BinarySearchTree.h"

using std::cout, std::endl;

BinarySearchTree::BinarySearchTree(): pRoot(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    freeTree(pRoot);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rT)
{
    pRoot = copyTree(rT.pRoot);
}

BinarySearchTree & BinarySearchTree::operator=(const BinarySearchTree &rT)
{
    if (this == &rT)
        return *this;

    freeTree(pRoot);
    pRoot = copyTree(rT.pRoot);
    return *this;
}

void BinarySearchTree::insert(const int &rK)
{
    pRoot = insertNode(pRoot, rK);
}

void BinarySearchTree::remove(const int &rK)
{
    pRoot = removeNode(pRoot, rK);
}

bool BinarySearchTree::search(const int &rK) const
{
    return (find(pRoot, rK) != nullptr);
}

int BinarySearchTree::predecessor(const int &rK) const
{
    Node *pCurrent = find(pRoot, rK);
    pCurrent = getPredecessor(pCurrent);
    if (pCurrent == nullptr)
        return rK;
    return pCurrent->data;
}

int BinarySearchTree::successor(const int &rK) const
{
    return getSuccessor(find(pRoot, rK))->data;
}

BinarySearchTree::Node * BinarySearchTree::rotateRight(Node *pN)
{
    if (pN->pLeft == nullptr)
        return pN;

    Node *pLess = pN->pLeft;
    pN->pLeft = pLess->pRight;
    pLess->pRight = pN;
    setHeight(pN);
    setHeight(pLess);
    return pLess;
}

BinarySearchTree::Node * BinarySearchTree::rotateLeft(Node *pN)
{
    if (pN->pRight == nullptr)
        return pN;

    Node *pMore = pN->pRight;
    pN->pRight = pMore->pLeft;
    pMore->pLeft = pN;
    setHeight(pN);
    setHeight(pMore);
    return pMore;
}

BinarySearchTree::Node * BinarySearchTree::balanceTree(Node *pN)
{
    if (pN == nullptr)
        return nullptr;

    setHeight(pN);
    int balanceFactor = getBalanceFactor(pN);

    if (balanceFactor > 1)
    {
        if (getBalanceFactor(pN->pLeft) == -1)
            pN = rotateLeft(pN->pLeft);
        pN = rotateRight(pN);
    }
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(pN->pRight) == 1)
            pN = rotateRight(pN->pRight);
        pN = rotateLeft(pN);
    }
    return pN;
}

BinarySearchTree::Node * BinarySearchTree::getSuccessor(Node *pN) const
{
    if (pN == nullptr)
        return nullptr;

    Node *pCurrent = pN->pRight;
    if (pCurrent != nullptr)
    {
        while (pCurrent->pRight != nullptr)
            pCurrent = pCurrent->pLeft;
    }
    else
    {
        pCurrent = findParent(pN);
        Node *pPrevious = pN;
        while (pCurrent != nullptr && pPrevious == pCurrent->pRight)
        {
            pPrevious = pCurrent;
            pCurrent = findParent(pCurrent);
        }
    }
    return pCurrent;
}

BinarySearchTree::Node * BinarySearchTree::getPredecessor(Node *pN) const
{
    if (pN == nullptr)
        return nullptr;

    Node *pCurrent = pN->pLeft;
    if (pCurrent != nullptr)
    {
        while (pCurrent->pLeft != nullptr)
            pCurrent = pCurrent->pRight;
    }
    else
    {
        pCurrent = findParent(pN);
        Node *pPrevious = pN;
        while (pCurrent != nullptr && pPrevious == pCurrent->pLeft)
        {
            pPrevious = pCurrent;
            pCurrent = findParent(pCurrent);
        }
    }
    return pCurrent;
}

BinarySearchTree::Node * BinarySearchTree::insertNode(Node *pN, const int &rK)
{
    if (pN == nullptr)
    {
        Node *pNewNode = new Node;
        pNewNode->data = rK;
        return pNewNode;
    }

    if (rK < pN->data)
        pN->pLeft = insertNode(pN->pLeft, rK);
    else if (rK > pN->data)
        pN->pRight = insertNode(pN->pRight, rK);
    else
        return pN;
    return balanceTree(pN);
}

BinarySearchTree::Node * BinarySearchTree::removeNode(Node *pN, const int &rK)
{
    if (pN == nullptr)
        return nullptr;

    if (rK < pN->data)
        pN->pLeft = removeNode(pN->pLeft, rK);
    else if (rK > pN->data)
        pN->pRight = removeNode(pN->pRight, rK);
    else
    {
        if (pN->pLeft == nullptr && pN->pRight == nullptr)
        {
            delete pN;
            return nullptr;
        }

        Node *pTemp;
        if (pN->pLeft == nullptr)
        {
            pTemp = pN->pRight;
            delete pN;
            pN = pTemp;
        }
        else if (pN->pRight == nullptr)
        {
            pTemp = pN->pLeft;
            delete pN;
            pN = pTemp;
        }
        else
        {
            pTemp = getPredecessor(pN);
            pN->data = pTemp->data;
            pN->pLeft = removeNode(pN->pLeft, pTemp->data);
            pTemp = nullptr;
        }
    }
    return balanceTree(pN);
}

BinarySearchTree::Node * BinarySearchTree::find(Node *pN, const int &rK) const
{
    Node *pCurrent = pN;
    while (pCurrent != nullptr)
    {
        if (rK < pCurrent->data)
            pCurrent = pCurrent->pLeft;
        else if (rK > pCurrent->data)
            pCurrent = pCurrent->pRight;
        else
            return pCurrent;
    }
    return nullptr;
}

BinarySearchTree::Node * BinarySearchTree::findParent(Node *pN) const
{
    Node *pCurrent = pRoot;
    while (pCurrent != nullptr)
    {
        if (pCurrent->pLeft == pN || pCurrent->pRight == pN)
            return pCurrent;

        if (pN->data < pCurrent->data)
            pCurrent = pCurrent->pLeft;
        else
            pCurrent = pCurrent->pRight;
    }
    return nullptr;
}

BinarySearchTree::Node * BinarySearchTree::copyTree(Node *pN)
{
    if (pN == nullptr)
        return nullptr;

    Node *pNewRoot = new Node;
    pNewRoot->data = pN->data;
    pNewRoot->pLeft = copyTree(pN->pLeft);
    pNewRoot->pRight = copyTree(pN->pRight);
    return pNewRoot;
}

void BinarySearchTree::freeTree(Node *pN)
{
    if (pN == nullptr)
        return;

    freeTree(pN->pLeft);
    freeTree(pN->pRight);
    delete pN;
}

void BinarySearchTree::setHeight(Node *pN)
{
    if (pN == nullptr)
        return;
    int maxChildHeight;
    int heightLeft = getHeight(pN->pLeft);
    int heightRight = getHeight(pN->pRight);
    if (heightLeft > heightRight)
        maxChildHeight = heightLeft;
    else
        maxChildHeight = heightRight;

    pN->height = maxChildHeight + 1;
}

int BinarySearchTree::getHeight(Node *pN) const
{
    if (pN == nullptr)
        return 0;
    return pN->height;
}

int BinarySearchTree::getBalanceFactor(Node *pN) const
{
    if (pN == nullptr)
        return 0;
    return getHeight(pN->pLeft) - getHeight(pN->pRight);
}
