//
//  TestBreadFirstPaths.cpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//
#include <stdlib.h>
#include <assert.h>
#include "TestBreadFirstPaths.h"
#include "Graph.h"
#include "BreadthFirstPaths.h"
using std::vector;

TestBreadFirstPaths::TestBreadFirstPaths()
{
    
}

TestBreadFirstPaths::~TestBreadFirstPaths()
{
    
}

void TestBreadFirstPaths::PrepareData()
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
    m_pBredthFirstPaths = new BreadthFirstPaths(*m_pGraph, 0);
}

void TestBreadFirstPaths::DeleteData()
{
    if (NULL != m_pBredthFirstPaths)
    {
        delete m_pBredthFirstPaths;
        m_pBredthFirstPaths = NULL;
    }
    if (NULL != m_pGraph)
    {
        delete m_pGraph;
        m_pGraph = NULL;
    }
}

void TestBreadFirstPaths::Tests()
{
    TestHasPathTo();
    TestPathTo();
}

void TestBreadFirstPaths::TestPathTo()
{
    PrepareData();
    vector<int> vPaths;
    vPaths = m_pBredthFirstPaths->PathTo(0);
    assert(vPaths.size() == 1);
    assert(vPaths[0] == 0);
    vPaths = m_pBredthFirstPaths->PathTo(1);
    assert(vPaths.size() == 2);
    assert(vPaths[0] == 1);
    assert(vPaths[1] == 0);
    vPaths = m_pBredthFirstPaths->PathTo(2);
    assert(vPaths.size() == 2);
    assert(vPaths[0] == 2);
    assert(vPaths[1] == 0);
    vPaths = m_pBredthFirstPaths->PathTo(3);
    assert(vPaths.size() == 3);
    assert(vPaths[0] == 3);
    assert(vPaths[1] == 5);
    assert(vPaths[2] == 0);
    vPaths = m_pBredthFirstPaths->PathTo(4);
    assert(vPaths.size() == 3);
    assert(vPaths[0] == 4);
    assert(vPaths[1] == 2);
    assert(vPaths[2] == 0);
    vPaths = m_pBredthFirstPaths->PathTo(5);
    assert(vPaths.size() == 2);
    assert(vPaths[0] == 5);
    assert(vPaths[1] == 0);
    DeleteData();
}

void TestBreadFirstPaths::TestHasPathTo()
{
    PrepareData();
    assert(m_pBredthFirstPaths->HasPathTo(0));
    assert(m_pBredthFirstPaths->HasPathTo(1));
    assert(m_pBredthFirstPaths->HasPathTo(2));
    assert(m_pBredthFirstPaths->HasPathTo(3));
    assert(m_pBredthFirstPaths->HasPathTo(4));
    assert(m_pBredthFirstPaths->HasPathTo(5));
    DeleteData();
}

//test main
//int main()
//{
//    TestBreadFirstPaths test;
//    test.Tests();
//    return 0;
//}









