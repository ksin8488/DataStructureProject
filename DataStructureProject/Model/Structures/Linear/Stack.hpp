//
//  Stack.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/22/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "LinkedList.hpp"

template <class Type>
class Stack : public LinkedList<Type>
{
public:
    Stack();    //constructor
    ~Stack();   //deconstructor
    
    //Stack specific methods
    void push(Type data);       //puts a value on top of the stack
    Type pop();                  //returns and removes the value from the top of the stack
    Type peek();                 //retrieves the top value without removing it
    
    //Overridden LinkedList methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
};

template <class Type>
Stack<Type> :: Stack() : LinkedList<Type>() //Just used to call the LinkedList constructor
{
    //Empty
}

template <class Type>
Stack<Type> :: ~Stack() //Destroys the stack data structure using pop()
{
    while(this->size > 0)
    {
        pop();
    }
}

template <class Type>
void Stack<Type> :: push(Type data)
{
    LinearNode<Type> * add = new LinearNode<Type>(data);
    
    if(this->size == 0)
    {
        this->end = add;
    }
    else
    {
        add->setNextNode(this->front);
    }
    
    this->front = add;
    this->size++;
}

//Push Methods
template <class Type>
void Stack<Type> :: add(Type data)
{
    push(data);
}

template <class Type>
void Stack<Type> :: addAtIndex(int index, Type data)
{
    assert(index == 0);
    push(data);
}

//Pop Methods
template <class Type>
Type Stack<Type> :: pop()
{
    assert (this->size > 0);
    Type removed = this->front->getData();
    
    LinearNode<Type> * removedNode = this->getFront();
    this->front = removedNode->getNextNode();
    delete removedNode;
    
    this->size--;
    
    return removed;
}

template <class Type> Type Stack<Type> :: remove(int index)
{
    assert(index == 0);
    return pop();
}

//Peek Methods
template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->size > 0);
    return this->getFront()->getData();
}

template <class Type>
Type Stack<Type> :: getFromIndex(int index)
{
    assert(index == 0);
    return peek();
}


#endif /* Stack_h */
