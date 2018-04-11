//
//  Controller.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "Tools/Timer.hpp"  //Need to give the file directory
#include "FileController.hpp"
#include "../Testers/ArrayTester.hpp"
#include "../Model/Structures/Linear/Array.hpp"
#include "../Testers/LinkedListTester.hpp"
#include "../Model/Structures/Linear/List.hpp"
#include "../Testers/RecursionTester.hpp"
#include "../Testers/SortingTester.hpp"
#include "../Testers/GraphTester.hpp"
#include "../Testers/BinaryTreeTester.hpp"

class Controller
{
public:
    void start();
    void testArray();
private:
    void findMaxAndMin();
};

#endif /* Controller_hpp */
