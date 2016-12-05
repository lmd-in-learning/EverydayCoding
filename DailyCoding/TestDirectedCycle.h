//
//  TestDirectedCycle.hpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestDirectedCycle_h
#define TestDirectedCycle_h

#include <stdio.h>

class DirectionGraph;
class DirectedCycle;

class TestDirectedCycle
{
    //constructor
public:
    TestDirectedCycle();
    ~TestDirectedCycle();
    
    //public functions
public:
    char* Tests();
    
    char* TestHasCycle();
    
    char* TestCycle();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    DirectionGraph* m_pDirectionGraph;
    
    DirectedCycle* m_pDirectedCycle;
    
};

#endif /* TestDirectedCycle_h */
