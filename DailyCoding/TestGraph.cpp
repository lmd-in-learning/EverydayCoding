//
//  TestGraph.cpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include "TestGraph.h"
#include "Graph.h"

using std::vector;

TestGraph::TestGraph()
{
    
}

TestGraph::~TestGraph()
{
    
}

void TestGraph::PrepareData()
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
}

void TestGraph::DeleteData()
{
    if (NULL != m_pGraph)
    {
        delete m_pGraph;
        m_pGraph = NULL;
    }
}

void TestGraph::Tests()
{
    TestGetVertexesCount();
    TestGetEdgeCount();
    TestAddEdge();
    TestAdjacent();
}

void TestGraph::TestGetVertexesCount()
{
    PrepareData();
    assert(m_pGraph->GetVertexesCount() == 6);
    DeleteData();
}

void TestGraph::TestGetEdgeCount()
{
    PrepareData();
    assert(m_pGraph->GetEdgesCount() == 8);
    DeleteData();
}

void TestGraph::TestAddEdge()
{
    PrepareData();
    assert(m_pGraph->GetEdgesCount() == 8);
    m_pGraph->AddEdge(1, 3);
    assert(m_pGraph->GetEdgesCount() == 9);
    DeleteData();
}

void TestGraph::TestAdjacent()
{
    PrepareData();
    vector<int> vAdjacents;
    vAdjacents = m_pGraph->Adjacent(0);
    assert(vAdjacents.size() == 3);
    assert(vAdjacents[0] == 5);
    assert(vAdjacents[1] == 1);
    assert(vAdjacents[2] == 2);
    DeleteData();
}

//test main
//int main()
//{
//    TestGraph testGraph;
//    testGraph.Tests();
//    return 0;
//}











