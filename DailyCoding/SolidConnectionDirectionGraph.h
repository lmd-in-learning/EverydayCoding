//
//  SolidConnectionDirectionGraph.hpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef SolidConnectionDirectionGraph_h
#define SolidConnectionDirectionGraph_h

#include <stdio.h>
#include <vector>

using std::vector;

class DirectionGraph;

class SolidConnectionDirectionGraph
{
    //constructor
public:
    SolidConnectionDirectionGraph(DirectionGraph& graph);
    ~SolidConnectionDirectionGraph();
    
    //public functions
public:
    //return true if v and w are strongly connected
    bool StronglyConnected(int v, int w) const;
    
    //return the num of strongly connections
    int Count() const;
    
    //return the id of the v's strongly connections
    int Id(int v) const;
    
    //private functions
private:
    void Dfs(DirectionGraph& graph, int v);
    
    //private members
private:
    vector<bool> m_vMarked;
    
    vector<int> m_vIds;
    
    int m_nCount;
};

#endif /* SolidConnectionDirectionGraph_h */
