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


template <class Type>
const int Graph<Type> :: MAXIMUM;   //constant so that it can be seen by the program

templace <class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0
}

/*
 Since we cannot "remove" from an array in C++,
 we only implement adding to a Graph.
 Java allows for all objects to be set to null but C++
 does not.
 */

template <class Type>
int Graph<Type> size() const
{
    return vertexCount;
}

//Left hand side operator - uses a reference to let us talk to and affect a stored value - lets you change the reference
template <class Type>
Type& Graph<Type> :: operator[](int vertex) //& gives you the memory address to talk to it
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

//Right hand side operator - is a copy of what is stored there - gives you a coopy
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(vertexCount < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)    //The only storage the data structure does - holds the vertex points so connections can be built between the points as needed
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    
    graphData[newVertexNumber] = value;
}

template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 target < vertexCount);
    adjacencyMatrix[source][target];
}

template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = 0;
    weightCostMatrix[target][source] = 0;
}

template <class Type>
void Graph<Type> :: adEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
}

template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = cost;
    weightCostMatrix[target][source] = cost;
}

template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) cosnt
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount)
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}

template <class type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target];
    
    return isAnEdge;
}

template <class type>
std::set<int> Graph<Type> :: neighbors(int vertex) cosnt
{
    assert(vertex < vertexCount);
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index++)
    {
        if(adjacencyMatrix[vertex][index])  //if there is a connection between the nodes...
        {
            vertexNeighbors.insert(index);  //The neighbors are set
        }
    }
    return vertexNeighbors;
}

//Traversals
template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    bool visitedVertices[MAXIMUM];
    assert(vertex < currentGraph.size());
    std::fill_n(visitedVertices, currentGraph.size(), false);
    depthFirstTraversal(currentGraph, vertex, visitedVertices);
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex, bool * visited)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;    //Iterator to be able to traverse a set
    
    visited[vertex] = true;
    cout << currentGraph[vertex] << ", " << endl;
    
    for(setIterator = connections.begin(); setIterator != connectionsend; setIterator++)    //recursive call and uses an Iterator to loop through the set
    {
        if(!visited[*setIterator])
        {
            depthFirstTraversal(currentGraph, *setIterator, visited);   //* gets the exact same value so multiple copies don't have to be made thus saving memory
        }
    }
}

template <class Type>
int Graph<Type> :: costTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    int cost = 0;
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited, currentGraph.size(), false);   //fill_n pre-populates the array with a given value
    visited[vertex] = true;
    
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setITerator != connections.end(); setIterator++)
        {
            if(!visited[*setITerator])
            {
                cost += weightCostMatrix[vertex][*setIterator];
                visited[*setIterator] = true;
                vertexQueue.push(*setIterator);
            }
        }
    }
    
    return cost
}

template <class Type>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited, currentGraph.size(), false);
    visited[vertex] = true;
    cout << curentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    while(!vertaxQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setITerator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setITerator])
            {
                visited[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}

#endif /* Graph_h */
