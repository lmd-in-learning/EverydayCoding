//
//  TestMinPQ.hpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestMinPQ_h
#define TestMinPQ_h

#include <stdio.h>

class MinPQ;

class TestMinPQ
{
    //constructor
public:
    TestMinPQ();
    ~TestMinPQ();
    
    //public functions
public:
    char* Tests();
    
    char* TestInsert();
    
    char* TestMin();
    
    char* TestDelMin();
    
    char* TestIsEmpty();
    
    char* TestSize();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    MinPQ* m_pMinPQ;
};

#endif /* TestMinPQ_h */
