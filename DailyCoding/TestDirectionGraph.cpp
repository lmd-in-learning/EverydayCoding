//
//  TestDirectionGraph.cpp
//  DailyCoding
//
//  Created by limingding on 12/4/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include <vector>
#include "UnitTest.h"
#include "TestDirectionGraph.h"
#include "DirectionGraph.h"

using std::vector;

TestDirectionGraph::TestDirectionGraph()
{
    
}

TestDirectionGraph::~TestDirectionGraph()
{
    
}

void TestDirectionGraph::PrepareData()
{
    m_pDirectionGraph = new DirectionGraph(6);
    m_pDirectionGraph->AddEdge(0, 1);
    m_pDirectionGraph->AddEdge(0, 2);
    m_pDirectionGraph->AddEdge(0, 3);
    m_pDirectionGraph->AddEdge(0, 4);
    m_pDirectionGraph->AddEdge(0, 5);
}

void TestDirectionGraph::DeleteData()
{
    if (NULL != m_pDirectionGraph)
    {
        delete m_pDirectionGraph;
        m_pDirectionGraph = NULL;
    }
}

char* TestDirectionGraph::Tests()
{
    mu_run_test(TestGetVertexesCount);
    mu_run_test(TestGetEdgeCount);
    mu_run_test(TestAddEdge);
    mu_run_test(TestAdjacent);
    mu_run_test(TestReverse);
    return NULL;
}

char* TestDirectionGraph::TestGetVertexesCount()
{
    PrepareData();
    mu_assert(" ", m_pDirectionGraph->GetVertexesCount() == 6);
    DeleteData();
    return NULL;
}

char* TestDirectionGraph::TestGetEdgeCount()
{
    PrepareData();
    mu_assert(" ", m_pDirectionGraph->GetEdgesCount() == 5);
    DeleteData();
    return NULL;
}

char* TestDirectionGraph::TestAddEdge()
{
    PrepareData();
    mu_assert(" ", m_pDirectionGraph->GetEdgesCount() == 5);
    m_pDirectionGraph->AddEdge(1, 2);
    mu_assert(" ", m_pDirectionGraph->GetEdgesCount() == 6);
    DeleteData();
    return NULL;
}

char* TestDirectionGraph::TestAdjacent()
{
    PrepareData();
    vector<int> vAdjacents;
    vAdjacents = m_pDirectionGraph->Adjacent(0);
    mu_assert(" ", vAdjacents.size() == 5);
    mu_assert(" ", vAdjacents[0] == 1);
    mu_assert(" ", vAdjacents[1] == 2);
    mu_assert(" ", vAdjacents[2] == 3);
    mu_assert(" ", vAdjacents[3] == 4);
    mu_assert(" ", vAdjacents[4] == 5);
    DeleteData();
    return NULL;
}

char* TestDirectionGraph::TestReverse()
{
    PrepareData();
    vector<int> vAdjacents;
    DirectionGraph graph = m_pDirectionGraph->Reverse();
    vAdjacents = graph.Adjacent(0);
    mu_assert(" ", vAdjacents.size() == 0);
    DeleteData();
    return NULL;
}

//test main
int main()
{
    TestDirectionGraph testDirectionGraph;
    mu_run_test(testDirectionGraph.Tests);
    return 0;
}
