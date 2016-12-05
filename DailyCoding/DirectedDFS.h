//
//  DirectedDFS.hpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DirectedDFS_h
#define DirectedDFS_h

#include <stdio.h>
#include <vector>

class DirectionGraph;
using std::vector;

class DirectedDFS
{
    //constructor
public:
    //find all the vertexes which s can be arrived
    DirectedDFS(DirectionGraph& graph, int s);
    
    //find all the vertexes which s in sources can be arrived
    DirectedDFS(DirectionGraph& graph, vector<int> vSources);
    
    ~DirectedDFS();
    
    //public functions
public:
    //return true if v can be arrived
    bool Marked(int v) const;
    
    //private functions
private:
    void Dfs(DirectionGraph& graph, int v);
    
    //private members
private:
    vector<bool> m_vMarked;
};
#endif /* DirectedDFS_h */
