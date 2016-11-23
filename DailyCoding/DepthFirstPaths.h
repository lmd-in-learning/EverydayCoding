//
//  DepthFirstPaths.hpp
//  DailyCoding
//
//  Created by limingding on 11/16/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DepthFirstPaths_h
#define DepthFirstPaths_h

#include <stdio.h>
#include "Paths.h"

class Graph;
class DepthFirstPaths : public Paths
{
    
public:
    DepthFirstPaths(Graph graph, int s);
    virtual ~DepthFirstPaths();
    
    //return true if s and v are connected
    virtual bool HasPathTo(int v);
    
    //return the edges between s and v
    virtual vector<int> PathTo(int v);
    
private:
    void Dfs(Graph graph, int v);
    
    vector<bool> m_vMarked;
    
    vector<int> m_vEdgeTo;
    
    int m_nS;
};
#endif /* DepthFirstPaths_h */
