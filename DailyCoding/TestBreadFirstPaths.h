//
//  TestBreadFirstPaths.hpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestBreadFirstPaths_h
#define TestBreadFirstPaths_h

#include <stdio.h>

class Graph;
class BreadthFirstPaths;

class TestBreadFirstPaths
{
public:
    TestBreadFirstPaths();
    
    ~TestBreadFirstPaths();
    
    //public funtions
public:
    void Tests();
    
    void TestHasPathTo();
    
    void TestPathTo();
    
    //private funtions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    Graph* m_pGraph;
    
    BreadthFirstPaths* m_pBredthFirstPaths;
};
#endif /* TestBreadFirstPaths_h */
