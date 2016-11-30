//
//  DirectionGraph.hpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DirectionGraph_h
#define DirectionGraph_h

#include <vector>

using std::vector;

class DirectionGraph
{
    //constructor
public:
    //create a graph with n vertexes and without any edges
    DirectionGraph(int nVertexes);
    
    ~DirectionGraph();
    
    DirectionGraph(const DirectionGraph& graph);
    
    DirectionGraph& operator =(const DirectionGraph& graph);
    //public functions
public:
    //get vertexes count
    int GetVertexesCount();
    
    //get edge count
    int GetEdgesCount();
    
    //add a edge between v and w
    void AddEdge(int v, int w);
    
    //return the vertexes adjacent v
    vector<int> Adjacent(int v);
    
    //reverse the graph direction
    DirectionGraph Reverse();
    
private:
    //<#instance variables#>
    //the vertexes count
    int m_nVertexesNum;
    
    //the edges count
    int m_nEdges;
    
    //the adjacent table
    vector<vector<int>> m_VAdjacent;
};


#endif /* DirectionGraph_h */
