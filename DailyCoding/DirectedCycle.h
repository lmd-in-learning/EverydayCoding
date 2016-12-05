//
//  DirectedCycle.hpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DirectedCycle_h
#define DirectedCycle_h

#include <stdio.h>
#include <vector>
#include <stack>

class DirectionGraph;
using std::vector;
using std::stack;

class DirectedCycle
{
    //constructor
public:
    DirectedCycle(DirectionGraph& graph);
    ~DirectedCycle();
    
    //public functions
public:
    bool HasCycle() const;
    
    stack<int> Cycle();
    
    //private functions
private:
    void Dfs(DirectionGraph& graph, int v);
    
    //private members
private:
    vector<bool> m_vMarked;
    
    vector<int> m_vEdgeTo;
    
    vector<bool> m_vOnStack;
    
    stack<int> m_stackCycle;
};

#endif /* DirectedCycle_h */
