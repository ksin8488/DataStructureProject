//
//  Array.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <assert.h>    //Used for validating user supplied data
#include <iostream>     //Used for tracing and debug statements

using namespace std;    //Used for keyword access

template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
public:
    //Constructor
    Array<Type>(int size);
    
    //Copy Constructor
    Array<Type>(const Array<Type> & toCopy);
    //Destructor
    ~Array<Type>();
    
    //Operators
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //Methods
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
};

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);           //To make sure that you can't store a negative number or 0
    this -> size = size;        //same as this.size in Java and self.size in Swift (Selector means it's related to pointers)
    
    internalArray = new Type[size];
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)    //Makes a copy of an array - const is used so you can't "hurt it" (accidentally change or destroy data) but still get the data
{
    this->size = toCopy.getSize();      //new pointer made to get the size with no assert needed due to previous check
    
    //Build Data Structure
    internalArray = new Type[size];
    
    for(int index = 0; index < size; index++)
    {
        internalArray[index] = toCopy[index];
    }
}

template <class Type>
Array<Type> :: ~Array()
{
    //About to delete the structure
    delete [] internalArray;    //THIS IS NOT CALLED BY YOU!!! NEVER CALL IT!
}

//Overloads
template <class Type>
Array<Type> & Array<Type> :: operator = (const Array<Type> & toAssign)      //Assignment operator is changed. Can't do this in Java. "Type Something operator" should make you read the section carefully
{
   if (&toAssign != this)       //Make sure the addresses are not the same
   {
       if (size != toAssign.getSize())
       {
           delete [] internalArray;
           size = toAssign.getSize();
           internalArray = new Type [size]; //creates a new array of the needed size
       }
       
       for (int index = 0; index < size; index++)
       {
           internalArray[index] = toAssign[index];  //fills the new array
       }
   }
    return *this;
}
    
template <class Type>
Type & Array<Type> :: operator [] (int index)   //(Left hand of = sign) Type& lefthand side operator (of the equal sign) Because it returns a reference you can change the value.
{
    assert(index >= 0 && index < size); //checks if the int is betwwen the index and size
    return internalArray[index];
}
    
template <class Type>
Type Array<Type> :: operator [] (int index) const   //(Right hand of = sign -- copy) Type is just the righthand part because it has no reference operator
{
    assert(index >= 0 && index < size);
    return internalArray[index];
}
    
//Methods
//#Basic getter
template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}
    
template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    
    Type value = internalArray[index];
    
    return value;
}
    
template <class Type>
void Array<Type> :: setAtIndex(int pos, Type item)
{
    assert(pos >= 0 && pos < size);
    internalArray[pos] = item;
}


#endif /* Array_h */
