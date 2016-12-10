//
//  TestMaxPQ.hpp
//  DailyCoding
//
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestMaxPQ_h
#define TestMaxPQ_h

#include <stdio.h>

class MaxPQ;

class TestMaxPQ
{
    //constructor
public:
    TestMaxPQ();
    ~TestMaxPQ();
    
    //public functions
public:
    char* Tests();
    
    char* TestInsert();
    
    char* TestMax();
    
    char* TestDelMax();
    
    char* TestIsEmpty();
    
    char* TestSize();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    MaxPQ* m_pMaxPQ;
};

#endif /* TestMaxPQ_h */
