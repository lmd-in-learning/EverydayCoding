//
//  DepthFirstSearch.hpp
//  DailyCoding
//
//  Created by limingding on 11/13/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DepthFirstSearch_h
#define DepthFirstSearch_h

#include <stdio.h>
#include <vector>

using std::vector;
class Graph;

class DepthFirstSearch {
    
public:
    DepthFirstSearch(Graph graph, int s);
    ~DepthFirstSearch();
    
    bool IsMarked(int w);
    
    int Count();
    
private:
    
    vector<bool> m_vMarked;
    
    int m_nCount;
    
    void Dfs(Graph graph, int v);
};
#endif /* DepthFirstSearch_h */
