//
//  List.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/8/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include "../../Nodes/LinearNode.hpp"

template <class Type>
class List
{
public:
    //Structure
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(int index) = 0;
    virtual Type getFromIndex(int index) = 0;
    //Helper
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
    
protected:
    int size;
};

#endif /* List_h */
