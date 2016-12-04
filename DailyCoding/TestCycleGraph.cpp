//
//  TestCycleGraph.cpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include "TestCycleGraph.h"
#include "Graph.h"
#include "CycleGraph.h"

TestCycleGraph::TestCycleGraph()
{
    
}

TestCycleGraph::~TestCycleGraph()
{
    
}

void TestCycleGraph::PrepareData()
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
    m_pCycleGraph = new CycleGraph(*m_pGraph);
}

void TestCycleGraph::DeleteData()
{
    if (NULL != m_pCycleGraph)
    {
        delete m_pCycleGraph;
        m_pCycleGraph = NULL;
    }
    if (NULL != m_pGraph)
    {
        delete m_pGraph;
        m_pGraph = NULL;
    }
}

void TestCycleGraph::Tests()
{
    TestHasCycle();
}

void TestCycleGraph::TestHasCycle()
{
    assert(!m_pCycleGraph->HasCycle());
}

//test main
//int main()
//{
//    TestCycleGraph test;
//    test.Tests();
//    return 0;
//}











