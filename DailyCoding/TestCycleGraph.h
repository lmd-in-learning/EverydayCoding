//
//  TestCycleGraph.hpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestCycleGraph_h
#define TestCycleGraph_h

#include <stdio.h>

class Graph;
class CycleGraph;

class TestCycleGraph
{
    //constructor
public:
    TestCycleGraph();
    ~TestCycleGraph();
    
    //public functions
public:
    void Tests();
    
    void TestHasCycle();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    Graph* m_pGraph;
    
    CycleGraph* m_pCycleGraph;
    
};

#endif /* TestCycleGraph_h */
