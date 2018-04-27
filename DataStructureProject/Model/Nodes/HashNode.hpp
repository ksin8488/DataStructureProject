//
//  HashNode.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 4/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include "Node.hpp"
template <class Type>
class HashNode : public Node<Type>  //note there are no pointers at all in HashNode
{
private:
    long key;
public:
    HashNode();
    HashNode(Type data);
    
    long geetKey() const;   //const makes it so that you cannot change the type or value. It is a constant
};

template <class Type>
HashNode<Type> :: HashNode()
{
    this->key = 0;
}

template <class Type>
HashNode<Type> :: HashNode(Type data) : Node<Type>(data)
{
    this->key = (long) &data;
}

template <class Type>
long HashNode<Type> :: getKey() const
{
    return this->key;
}

#endif /* HashNode_h */
