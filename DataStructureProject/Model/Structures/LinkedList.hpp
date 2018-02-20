//
//  LinkedList.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/14/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "List.hpp"

using namespace std;    //Used for keyword access. Use this to make sure your pointers are pointing to the right things

#ifndef LinkedList_h
#define LinkedList_h

template <class Type>
class LinkedList : public List<Type>
{
protected:
    LinearNode<Type> * front;
    LinearNode<Type> * end;
public:
    //Constructors
    LinkedList();
    //Destructor
    virtual ~LinkedList(); //Virtual so it can be overridden.
    //Helper methods
    int getSize() const;
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
    
    //Structure Methods
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type getFromIndex(int index);
    Type remove(int index);
    // Type setAtIndex(int index, Type item);
    // bool contains(Type item);
};

template <class Type>
LinkedList<Type> :: LinkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}

template <class Type>
LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while (front != nullptr)
    {
        front = destroyStructure->getNextNode();
        delete destroyStructure;
        destroyStructure = front;
    }
}

template <class Type>
void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if(this->size == 0)
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData);
    }
    
    this->end = newData;
    
    this->size += 1;
}

template <class Type>
void LinkedList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= this->size);  //checks if the index is valid
    if(index == this->size)
    {
        add(item);  //adds the item to the "this" position
    }
    else
    {
        LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
        if(index == 0)
        {
            toBeAdded->setNextNode(front);  //sets the new value to the front
            front = toBeAdded;      //changes front to now be the new value
        }
        else
        {
            LinearNode<Type> * previous = nullptr;      //makes the previous pointer a nullptr value
            LinearNode<Type> * current = front;
            for(int position = 0; position < index; position++)
            {
                previous = current;
                current = current->getNextNode();
            }
            previous->setNextNode(toBeAdded);
            toBeAdded->setNextNode(current);
        }
        this->size++;
    }
}

template <class Type>
Type LinkedList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->size);
    
    LinearNode<Type> * current = front;
    LinearNode<Type> * toBeRemoved = nullptr;   //creates a pointer to be removed that is set to null
    LinearNode<Type> * previous = nullptr;      //creates a pointer called previous that is set to null
    
    Type removedData;
    
    if(index == 0)
    {
        toBeRemoved = front;    //sets the value of what needs to be removed to the front value
        this->front = this->front->getNextNode();   //makes the front be the next pointer since the current one is no more
    }
    else
    {
        for(int position = 0; position < index; position++)
        {
            previous = current; //all previous nodes get shifted to become the current node in the loop
            current = current->getNextNode();   //the new current is the value after the old current (next one)
        }
        
        toBeRemoved = current;
        
        if(index == this->size - 1)
        {
            previous->setNextNode(nullptr);
            end = previous;
        }
        else
        {
            current = toBeRemoved->getNextNode();
            previous->setNextNode(current);
        }
    }
    this->size -= 1;
    
    removedData = toBeRemoved->getData();
    delete toBeRemoved;
    return removedData;
}

////Extra method to solve the error with "vTable and referenced from..." - Code from Derek Vawdry
//template <class Type>
//Type LinkedList<Type> :: getFromIndex(int index)
//{
//    assert(index >= 0 && index < this->size);
//
//    LinearNode<Type> * current = front;
//    LinearNode<Type> * nodeToGet = nullptr;
//    LinearNode<Type> * previous = nullptr;
//
//    Type data;
//
//    if(index == 0)
//    {
//        nodeToGet = front;
//    }
//    else
//    {
//        for(int position = 0; position < index; position++)
//        {
//            previous = current;
//            current = current->getNextNode();
//        }
//
//        nodeToGet = current;
//        if(index == this->size-1)
//        {
//            end = previous;
//        }
//        else
//        {
//            current = nodeToGet->getNextNode();
//        }
//    }
//    data = nodeToGet->getData();
//    return data;
//}

template <class Type>
Type LinkedList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->size);
    Type data;
    
    LinearNode<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNextNode();
    }
    
    data = current->getData();
    
    return data;
}

//#Basic methods
template <class Type>
LinearNode<Type> * LinkedList<Type> :: getEnd()
{
    return this->end;
}

template <class Type>
LinearNode<Type> * LinkedList<Type> :: getFront()
{
    return this->front;
}

template <class Type>
int LinkedList<Type> :: getSize() const
{
    return this->size;
}

#endif /* LinkedList_h */
