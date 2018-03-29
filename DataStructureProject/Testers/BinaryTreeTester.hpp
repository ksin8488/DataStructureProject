//
//  BinaryTreeTester.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include "../Model/Nodes/BinaryTreeNode.hpp"
#include "../Model/Structures/NonLinear/BinarySearchTree.hpp"
#include <iostream>

class BinaryTreeTester
{
private:
    BinarySearchTree<int> testTree;   //is an abstract class
public:
    void doTreeStuff();
};

#endif /* BinaryTreeTester_hpp */
