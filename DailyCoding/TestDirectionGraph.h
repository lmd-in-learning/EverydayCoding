//
//  TestDirectionGraph.hpp
//  DailyCoding
//
//  Created by limingding on 12/4/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestDirectionGraph_h
#define TestDirectionGraph_h

#include <stdio.h>

class DirectionGraph;

class TestDirectionGraph
{
    //constructor
public:
    TestDirectionGraph();
    ~TestDirectionGraph();
    
    //public functions
public:
    char* Tests();
    
    char* TestGetVertexesCount();
    
    char* TestGetEdgeCount();
    
    char* TestAddEdge();
    
    char* TestAdjacent();
    
    char* TestReverse();
    
    //private funtions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    DirectionGraph* m_pDirectionGraph;
};

#endif /* TestDirectionGraph_h */
