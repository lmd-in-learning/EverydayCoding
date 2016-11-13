//
//  Graph.h
//  DailyCoding
//
//  Created by limingding on 10/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <vector>
#include <string.h>

using std::vector;
using std::string;

class Graph {
    
public:
    //create a graph with n vertexes and without any edges
    Graph(int nVertexes);
    
    ~Graph();
    
    //get vertexes count
    int GetVertexesCount();
    
    //get edge count
    int GetEdgesCount();
    
    //add a edge between v and w
    void AddEdge(int v, int w);
    
    //return the vertexes adjacent v
    vector<int> Adjacent(int v);
    
private:
    //<#instance variables#>
    //the vertexes count
    int m_nVertexesNum;
    
    //the edges count
    int m_nEdges;
    
    //the adjacent table
    vector<vector<int>> m_VAdjacent;
};

#endif /* Graph_h */
