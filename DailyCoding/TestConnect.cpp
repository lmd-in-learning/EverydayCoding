//
//  TestConnect.cpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "TestConnect.h"
#include "Graph.h"
#include "Connect.h"

TestConnect::TestConnect()
{
    
}

TestConnect::~TestConnect()
{
    
}

void TestConnect::PrepareData()
{
    m_pGraph = new Graph(13);
    m_pGraph->AddEdge(0, 6);
    m_pGraph->AddEdge(0, 2);
    m_pGraph->AddEdge(0, 1);
    m_pGraph->AddEdge(0, 5);
    m_pGraph->AddEdge(1, 0);
    m_pGraph->AddEdge(2, 0);
    m_pGraph->AddEdge(3, 5);
    m_pGraph->AddEdge(3, 4);
    m_pGraph->AddEdge(4, 5);
    m_pGraph->AddEdge(4, 6);
    m_pGraph->AddEdge(4, 3);
    m_pGraph->AddEdge(5, 3);
    m_pGraph->AddEdge(5, 4);
    m_pGraph->AddEdge(5, 0);
    m_pGraph->AddEdge(6, 0);
    m_pGraph->AddEdge(6, 4);
    m_pGraph->AddEdge(7, 8);
    m_pGraph->AddEdge(8, 7);
    m_pGraph->AddEdge(9, 11);
    m_pGraph->AddEdge(9, 10);
    m_pGraph->AddEdge(9, 12);
    m_pGraph->AddEdge(10, 9);
    m_pGraph->AddEdge(11, 9);
    m_pGraph->AddEdge(11, 12);
    m_pGraph->AddEdge(12, 11);
    m_pGraph->AddEdge(12, 9);
    m_pConnect = new Connect(*m_pGraph);
}

void TestConnect::DeleteData()
{
    if (NULL != m_pConnect)
    {
        delete m_pConnect;
        m_pConnect = NULL;
    }
    if (NULL != m_pGraph)
    {
        delete m_pGraph;
        m_pGraph = NULL;
    }
}

void TestConnect::Tests()
{
    TestConnected();
    TestCount();
    TestId();
}

void TestConnect::TestConnected()
{
    PrepareData();
    assert(m_pConnect->Connected(0, 1));
    assert(m_pConnect->Connected(0, 2));
    assert(m_pConnect->Connected(0, 3));
    assert(m_pConnect->Connected(0, 4));
    assert(m_pConnect->Connected(0, 5));
    assert(m_pConnect->Connected(0, 6));
    assert(m_pConnect->Connected(7, 8));
    assert(m_pConnect->Connected(9, 10));
    assert(m_pConnect->Connected(9, 11));
    assert(m_pConnect->Connected(9, 12));
    
    assert(!m_pConnect->Connected(7, 1));
    assert(!m_pConnect->Connected(7, 2));
    assert(!m_pConnect->Connected(7, 3));
    assert(!m_pConnect->Connected(7, 4));
    assert(!m_pConnect->Connected(7, 5));
    assert(!m_pConnect->Connected(7, 6));
    assert(!m_pConnect->Connected(9, 1));
    assert(!m_pConnect->Connected(9, 2));
    assert(!m_pConnect->Connected(9, 3));
    assert(!m_pConnect->Connected(9, 4));
    assert(!m_pConnect->Connected(9, 5));
    assert(!m_pConnect->Connected(9, 6));
    DeleteData();
    
}

void TestConnect::TestId()
{
    PrepareData();
    assert(m_pConnect->Id(0) == 0);
    assert(m_pConnect->Id(7) == 1);
    assert(m_pConnect->Id(9) == 2);
    DeleteData();
}

void TestConnect::TestCount()
{
    PrepareData();
    assert(m_pConnect->Count() == 3);
    DeleteData();
}

//test main
int main()
{
    TestConnect test;
    test.Tests();
    return 0;
}
