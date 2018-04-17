//
//  AVLTree.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 4/17/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    
    BinaryTreeNode<Type> * leftRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree (BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * insertNode(BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode(BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifferentce(BinaryTreeNode<Type> * parent);
    
public:
    AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
    
};

/*
 A negative value means the riht is reater than the left
 */
template <class Type>
int AVLTree<Type> :: heightDifferentce(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateheigght(node->getLeftNode());
    int rightHeight = this->calculateHeight(node->geRightNode());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation (BinaryTreeNode<Type> * parent)   //For left-only unbalanced
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeftNode();
    
    parent->setLeftChild(changedNode->getLeftNode());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation(BinaryTreeNode<Type> * parent)    //For right-only unbalanced
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRightNode;
    
    parent->setRightChild(changedNode->getLeftNode());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinaryTreeNode<Type> * parent) //right to lefft rotation
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRightNode();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinaryTreeNode<Type> * parent) //left to right rotation
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeftNode();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree (BinaryTreeNode<Type> * parent)  //checks if the tree is balenced
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)   //if it's positive, do left based rotations
    {
        if(heightDifference(parent->getLeftNode()) > 0)
        {
            parent = leftRotation(parent);  //if the height difference is greater than 0 for the left node...
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1) //if it's negatiive, do right based rotations
    {
        if(heightDifference(parent->getRightNode()) > 0)    //if the hight difference is greater than 0 for the right node...
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    
    return parent;
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        return parent;
    }
    if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(removeNdoe(parent->getLEftNode(), inserted));
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(removeNode(parent->getRightNode(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLeftNode() == nullptr && parent->getRightNode() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if(parent->getRightNode() == nullptr)
        {
            *parent = *parent->getRightNode();  //taking the value of a pointer and setting/shoving a new value into it
        }
        else if(parent->getRightNode() == nullptr)
        {
            *parent - *parent->getLeftNode();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRightNode());
            parent->setNodeData(leftMost->getNodeData());
            parent->setRightChild(removeNode(parent->getRightNode(), leftMost->getNodeData()));
        }
    }
    
    if(parent == nullptr)
    {
        return parent;
    }
    
    return balanceSubTree(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLEftChild(insertNode(parent -> getLeftNode(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightNode(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);   //just calls the method that does the actual work. Sort of like how we call the frame in the panel to use make the GUI in Java
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNopde(this->getRoot(), item);
}

#endif /* AVLTree_h */
