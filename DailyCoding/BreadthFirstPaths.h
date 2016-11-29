//
//  BreadthFirstPaths.hpp
//  DailyCoding
//
//  Created by limingding on 11/23/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef BreadthFirstPaths_h
#define BreadthFirstPaths_h

#include <stdio.h>
#include "Paths.h"

class Graph;
class BreadthFirstPaths : public Paths
{
    //public funtions
public:
    //find all the edges begin with s
    BreadthFirstPaths(Graph& graph, int s);
    
    virtual ~BreadthFirstPaths();
    
    //return true if s and v are connected
    virtual bool HasPathTo(int v);
    
    //return the edges between s and v
    virtual vector<int> PathTo(int v);
    
    //private funtions
private:
    void Bfs(Graph& graph, int s);
    
    //private variable
private:
    vector<bool> m_vMarked;
    
    vector<int> m_vEdgeTo;
    
    const int m_nS;
};
#endif /* BreadthFirstPaths_h */
