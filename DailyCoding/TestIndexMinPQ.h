//
//  TestIndexMinPQ.hpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestIndexMinPQ_h
#define TestIndexMinPQ_h

#include <stdio.h>

class IndexMinPQ;

class TestIndexMinPQ
{
    //construncor
public:
    TestIndexMinPQ();
    ~TestIndexMinPQ();
    
    //public functions
public:
    char* Tests();
    
    char* TestIsEmpty();
    
    char* TestSize();
    
    char* TestContains();
    
    char* TestInsert();
    
    char* TestChange();
    
    char* TestDeltete();
    
    char* TestMin();
    
    char* TestMinIndex();
    
    char* TestDelMin();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
    //private members
private:
    IndexMinPQ* m_pIndexMinPQ;
    
};

#endif /* TestIndexMinPQ_h */
