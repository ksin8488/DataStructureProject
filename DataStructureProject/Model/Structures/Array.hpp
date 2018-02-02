//
//  Array.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Array_h
#define Array_h

#includes <assert.h>    //Used for validating user supplied data
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
    Array<Type> & operator = ()const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //Methods
    int getSize() const;
    Type get FromIndex(int index);
    void setAtIndex(int index, Type data);
}

#endif /* Array_h */
