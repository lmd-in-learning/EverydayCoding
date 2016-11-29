//
//  TestGraph.hpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestGraph_h
#define TestGraph_h

#include <stdio.h>

class Graph;

class TestGraph
{
    //constructor
public:
    TestGraph();
    ~TestGraph();

    //public functions
public:
    void Tests();
    
    void TestGetVertexesCount();
    
    void TestGetEdgeCount();
    
    void TestAddEdge();
    
    void TestAdjacent();
    
    //private funtions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    Graph* m_pGraph;
};
#endif /* TestGraph_h */
