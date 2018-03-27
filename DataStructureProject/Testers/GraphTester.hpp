//
//  GraphTester.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef GraphTester_hpp
#define GraphTester_hpp

#include <iostream>
#include "../Model/Structures/NonLinear/Graph.hpp"

class GraphTester
{
private:
    Graph<string> puzzle;
    void setup();
    void compareTraversals();
    void findCheapestTraversal();
public:
    void testGraphs();
};

#endif /* GraphTester_hpp */
