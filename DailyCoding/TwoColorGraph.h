//
//  TwoColorGraph.hpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TwoColorGraph_h
#define TwoColorGraph_h

#include <stdio.h>
#include <vector>

class Graph;
using std::vector;

class TwoColorGraph
{
    //constructor
public:
    TwoColorGraph(Graph& graph);
    ~TwoColorGraph();
    
    //public functions
public:
    bool IsBinaryPartities() const;
    
    //priivate functions
private:
    void Dfs(Graph& graph, int v);
    
    //private members
private:
    vector<int> m_vMarked;
    
    vector<bool> m_vColor;
    
    bool m_bIsTwoColorable;
};
#endif /* TwoColorGraph_h */
