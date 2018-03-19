//
//  Graph.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 3/19/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];        //pre-defining the data structure's size
    int weightCostMatrix [MAXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> & graph, int vertex, bool markedVertices[])        //Recursive helper method w/ 3 parameters
public:
    Graph()     //constructor
    //Graph operations
    
    void addVertex(const Type& value)   //builds the vertexes
    
    //Conenct vertices
    void addEdge(int source, int target);                    //makes a one-way connection from source to target
    void addEdgeUndirected(int source, int target);         //makes a 2-way connection from source to target and back
    void addEdgeCost(int source, int target, int cost);
    //Disconnect vertices
    void removeEdge(int source, int target);
    void removeEdgeUndirected(int source, int target);
    void removeEdgeCost(int source, int target);
    
    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    
    //Check connections
    bool hasUndirectedConnection(int source, int target) const;
    bool areConnected(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    
    //Traversals
    void depthFirstTraversal(Graph<Type> & graph, int vertex);
    void breadthFirstTraversal(Graph<Type> & graph, int vertex);
    int costTraversal(Graph<Type> & graph, int vertex);
};

#endif /* Graph_h */
