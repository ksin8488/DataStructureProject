//
//  Tree.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "../../Nodes/BinaryTreeNode.hpp"
template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //Informational Methods
    virtual int getSize() = 0;  //virtual & = 0 makes it abstract
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*Data Methods*
    virtual void insert(Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //*Traversals*
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
};

#endif /* Tree_h */
