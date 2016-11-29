//
//  TestDepthFirstPaths.cpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "TestDepthFirstPaths.h"
#include "Graph.h"
#include "DepthFirstPaths.h"

TestDepthFirstPaths::TestDepthFirstPaths()
{
    
}

TestDepthFirstPaths::~TestDepthFirstPaths()
{
    
}

void TestDepthFirstPaths::PrepareData()
{
    m_pGraph = new Graph(6);
    m_pGraph->AddEdge(0, 5);
    m_pGraph->AddEdge(2, 4);
    m_pGraph->AddEdge(2, 3);
    m_pGraph->AddEdge(1, 2);
    m_pGraph->AddEdge(0, 1);
    m_pGraph->AddEdge(3, 4);
    m_pGraph->AddEdge(3, 5);
    m_pGraph->AddEdge(0, 2);
    m_pDepthFirstPaths = new DepthFirstPaths(*m_pGraph, 0);
}

void TestDepthFirstPaths::DeleteData()
{
    if (NULL != m_pDepthFirstPaths)
    {
        delete m_pDepthFirstPaths;
        m_pDepthFirstPaths = NULL;
    }
    if (NULL != m_pGraph)
    {
        delete m_pGraph;
        m_pGraph = NULL;
    }
}

void TestDepthFirstPaths::Tests()
{
    TestHasPathTo();
    TestPathTo();
}

void TestDepthFirstPaths::TestHasPathTo()
{
    PrepareData();
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(0)));
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(1)));
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(2)));
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(3)));
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(4)));
    assert(m_pDepthFirstPaths->HasPathTo(m_pDepthFirstPaths->HasPathTo(5)));
    DeleteData();
}

void TestDepthFirstPaths::TestPathTo()
{
    PrepareData();
    vector<int> vPaths;
    vPaths = m_pDepthFirstPaths->PathTo(0);
    assert(vPaths.size() == 1);
    assert(vPaths[0] == 0);
    vPaths = m_pDepthFirstPaths->PathTo(1);
    assert(vPaths.size() == 5);
    assert(vPaths[0] == 1);
    assert(vPaths[1] == 2);
    assert(vPaths[2] == 3);
    assert(vPaths[3] == 5);
    assert(vPaths[4] == 0);
    vPaths = m_pDepthFirstPaths->PathTo(2);
    assert(vPaths.size() == 4);
    assert(vPaths[0] == 2);
    assert(vPaths[1] == 3);
    assert(vPaths[2] == 5);
    assert(vPaths[3] == 0);
    vPaths = m_pDepthFirstPaths->PathTo(3);
    assert(vPaths.size() == 3);
    assert(vPaths[0] == 3);
    assert(vPaths[1] == 5);
    assert(vPaths[2] == 0);
    vPaths = m_pDepthFirstPaths->PathTo(4);
    assert(vPaths.size() == 5);
    assert(vPaths[0] == 4);
    assert(vPaths[1] == 2);
    assert(vPaths[2] == 3);
    assert(vPaths[3] == 5);
    assert(vPaths[4] == 0);
    vPaths = m_pDepthFirstPaths->PathTo(5);
    assert(vPaths.size() == 2);
    assert(vPaths[0] == 5);
    assert(vPaths[1] == 0);
    DeleteData();
}

//test main
int main()
{
    TestDepthFirstPaths test;
    test.Tests();
    return 0;
}
















