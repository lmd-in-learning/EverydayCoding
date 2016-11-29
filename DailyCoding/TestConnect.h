//
//  TestConnect.hpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestConnect_h
#define TestConnect_h

#include <stdio.h>

class Graph;
class Connect;

class TestConnect
{
    //constructor
public:
    TestConnect();
    ~TestConnect();
    
    //public functions
public:
    void Tests();
    
    void TestConnected();
    
    void TestCount();
    
    void TestId();
    
    //private functions
private:
    void PrepareData();
    
    void DeleteData();
    
private:
    Graph* m_pGraph;
    
    Connect* m_pConnect;
    
};

#endif /* TestConnect_h */
