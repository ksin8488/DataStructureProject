//
//  N_AryTreeNode.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 4/23/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef N_AryTreeNode_h
#define N_AryTreeNode_h

#include <vector>
#include "Node.hpp"
using namespace std;

template <class Type>
class N_AryTreeNode : public Node<Type>
{
private:
    vector<N_AryTreeNode<Type>*> nodes;
    N_AryTreeNode<Type> * root;
    
public:
    N_AryTreeNode<Type>();
    ~N_AryTreeNode<Type();
    N_AryTreeNode<Type>(Type data);
    
    vector<N_AryTreeNode<Type>*> getNodes();
    N_AryTreeNode<Type> * getRoot();
    int getChildCount();
    
    void setRoot(N_AryTreeNode<Type> * root);
    void addChild(Type data);
};
    
    template <class Type>
    N_AryTreeNode<Type> :: N_AryTreeNode()  //constructor so no code within it
    { //unused
        
    }

    template <class Type>
    N_AryTreeNode<Type> :: N_AryTreeNode(Type data) : Node<Type>(data)
    {
        //nothing because vector is already initialized when it is created
    }
    
    template <class Type>
    N_AryTreeNode<Type> :: ~N_AryTreeNode()
    {
        for(int index = nodes.size() - 1; index >= 0; index --)
        {
            delete nodes[index];
        }
    }
    
    template <class Type>
    N_AryTreeNode<Type> * N_AryTreeNode<Type>b :: getRoot()
    {
        return root;
    }
    
    template <class Type>
    N_AryTreeNode<Type> N_AryTreeNode<Type> :: getNodes()
    {
        return nodes;
    }
    
    template <class Type>
    int N_AryTreeNode<Type> :: getChildCount()
    {
        return nodes.size();
    }
    
    template <class Type>
    void N_AryTreeNode<Type> :: setRoot(N_AryTreeNode<Type> * root)
    {
        this->root = root;
    }
    
    template <class Type>
    void N_AryTreeNode<Type> :: addChild(Type data)
    {
        N_AryTreeNode<Type> * node = new N_AryTreeNode<Type>(data);
        nodes.push_back(node);
    }
    
#endif /* N_AryTreeNode_h */
