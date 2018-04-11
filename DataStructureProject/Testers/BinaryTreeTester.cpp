//
//  BinaryTreeTester.cpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void  BinaryTreeTester :: doTreeStuff()
{
    testTree.insert(3);
    testTree.insert(1);
    testTree.insert(2);
    testTree.insert(-3246000);
    testTree.insert(-12);
    testTree.insert(7);
    testTree.insert(5);
    testTree.insert(6);
    testTree.insert(8);
    testTree.insert(5000);
    testTree.insert(9001);
    testTree.insert(10);
    testTree.insert(600);
    
  //  testTree.demo();
    testTree.inOrderTraversal();
    testTree.preOrderTraversal();
    testTree.postOrderTraversal();
}
