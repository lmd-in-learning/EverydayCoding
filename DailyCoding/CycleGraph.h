//
//  CycleGraph.hpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef CycleGraph_h
#define CycleGraph_h

#include <stdio.h>
#include <vector>

class Graph;
using std::vector;

class CycleGraph
{
    //constructor
public:
    CycleGraph(Graph& graph);
    ~CycleGraph();
    
    //public functions
public:
    bool HasCycle() const;
    
    //private functions
private:
    void Dfs(Graph& graph, int v, int u);
    
    //private members
private:
    vector<int> m_vMarked;
    
    bool m_bHasCycle;
};
#endif /* CycleGraph_h */
