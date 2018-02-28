//
//  CircularList.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/26/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "List.hpp"
#include "../../Nodes/DoubleNode.hpp"

template <class Type>
class CircularList : public List<Type>
{
private:
    DoubleNode<Type> * front;
    DoubleNode<Type> * end;
    
    DoubleNode<Type> * findNode*(int index);
public:
    Circularlist();
    ~CircularList();
    
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type remove(int index);
    Type getFromIndex(int index);
    int getSize() const;
    //Unused
    LinearNode<Type>* getFront();
    LinearNode<Type>* getEnd();
};

//Constructor and deconstructor
template <class Type>
CircularList<Type> :: CircularList()
{
    front = nullptr;
    end = nullptr;
    this->size = 0;
}

template <class Type>
CircularList<Type> :: ~CircularList();
{
    DoubleNode<Type> * current = front;
    whille(this->front != nullptr)
    {
        front = front->getNext();
        delete current;
        current = front;
    }
}

//findNode method looks from the closest index that we have access to (front or end)
template <class Type>
DoubleNode<Type * CircularList<Type> :: findNode(int index)
{
    assert (index >= 0 && index < this->size);
    DoubleNode<Type> * nodeToFind;
    
    if(index < this->size / 2)
    {
        nodeToFind = this->front;
        for(int position = 0; position < index; position++)
        {
            nodeToFind = nodeToFind->getNext();
        }
    }
    else
    {
        nodeToFind = this->size;
        for(int position = this->size - 1; position > index; position--)
        {
            nodeToFind = nodeToFind->getPrevious();
        }
    }
    
    return nodeToFind;
}

//add method works similar to a regular LinkedList but with a small pointer addition
template <class Type>
void CircularList<Type> :: add(Type item)
{
    DoubleNode<Type> * addedNode;
    if(this->size == 0)
    {
        addedNode = new DoubleNode<Type>(item);
        this->front = addedNode;
    }
    else
    {
        addedNode = new DoubleNode<Type>(item, this->end, this->front);
        this->end->setNext(addedNode);
    }
    this->end = addedNode;
    this->size++
}

//addAtIndex mehtod uses the findNodeMethod - assert is <= because it is okay to add to the end
template <class Type>
void CircularList<Type> :: addAtIndex(int index, Type item)
{
    assert (index >= 0 && index <= this->size);
    
    DoubleNode<Type> * next;
    DoubleNode<Type> * previous;
    DoubleNode<Type>* addMe;
    
    if(index < this->size)
    {
        next = findNode(index);
        previous = next->getPrevious();
    }
    else if (index == this->size)
    {
        next = this->front;
        previous = this->end;
    }
    
    addMe = new DoubleNode<Type>(item, previous, next);
    
    if(index == 0)
    {
        this->front = addMe;
    }
    else if(index == this->size)
    {
        this->end - addMe;
    }
    
    previous->setNext(addMe);
    next->setPrevious(addMe);
    this->size++;
}

//get method looks for the value and returns it and has an assert as usual for validity
template <class Type>
Type CircularList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->size)
    DoubleNode<Type> * holder = findNode(index);
    return holder->getData();
}

//remove method that uses and changes multiple pointers
template <class Type>
Type CircularList<Type> :: remove(int index)
{
    assert (index >= 0 && index < this->size);
    
    DoubleNode<Type> * removed = findNode(index);
    DoubleNode<Type> * removedPrevious = removed->getPrevious();
    DoubleNode<Type> * removedNext = removed->getNext();
    
    if(index == 0)
    {
        this->front = removedNext;
        this->end->setNext(removedNext);
    }
    if(index == this->size -1)
    {
        this->end = removedPrevious;
        this->front->setPrevious(removedPrevious);
    }
    
    removedPrevious->setNext(removedNext);
    removedNext->setPrevious(removedPrevious);
    
    Type value = removed->getData();
    this->size--;
    delete removed;
    return value;
}

//getSize method
template <class Type>
int CircularList<Type> :: getSize() const
{
    return this->size;
}

//Extraneous Bad Design
template <class Type>
LinearNode<Type> * CircularList<Type> :: getFront()
{
    return nullptr;
}

template <class Type>
LinearNode<Type> * CircularList<Type> :: getEnd()
{
    return nullptr;
}


#endif /* CircularList_h */
