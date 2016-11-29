//
//  TestDepthFirstPaths.hpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestDepthFirstPaths_h
#define TestDepthFirstPaths_h

#include <stdio.h>

class Graph;
class DepthFirstPaths;

class TestDepthFirstPaths
{
    //constructor
public:
    TestDepthFirstPaths();
    ~TestDepthFirstPaths();
    
    //public functions
public:
    void Tests();
    
    void TestHasPathTo();
    
    void TestPathTo();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    Graph* m_pGraph;
    
    DepthFirstPaths* m_pDepthFirstPaths;
    
};


#endif /* TestDepthFirstPaths_h */
