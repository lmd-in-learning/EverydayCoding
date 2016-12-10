//
//  TestDirectedCycle.cpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include <stack>
#include "UnitTest.h"
#include "TestDirectedCycle.h"
#include "DirectionGraph.h"
#include "DirectedCycle.h"

TestDirectedCycle::TestDirectedCycle()
{
    
}

TestDirectedCycle::~TestDirectedCycle()
{
    if (NULL != m_pDirectionGraph)
    {
        delete m_pDirectionGraph;
        m_pDirectionGraph = NULL;
    }
    
    if (NULL != m_pDirectedCycle)
    {
        delete m_pDirectedCycle;
        m_pDirectedCycle = NULL;
    }
}

void TestDirectedCycle::PrepareData()
{
    m_pDirectionGraph = new DirectionGraph(6);
    m_pDirectionGraph->AddEdge(0, 5);
    m_pDirectionGraph->AddEdge(5, 4);
    m_pDirectionGraph->AddEdge(4, 3);
    m_pDirectionGraph->AddEdge(3, 5);
    
    m_pDirectedCycle = new DirectedCycle(*m_pDirectionGraph);
}

void TestDirectedCycle::DeleteData()
{
    if (NULL != m_pDirectionGraph)
    {
        delete m_pDirectionGraph;
        m_pDirectionGraph = NULL;
    }
    
    if (NULL != m_pDirectedCycle)
    {
        delete m_pDirectedCycle;
        m_pDirectedCycle = NULL;
    }
}

char* TestDirectedCycle::Tests()
{
    mu_run_test(TestHasCycle);
    mu_run_test(TestCycle);
    return NULL;
}

char* TestDirectedCycle::TestHasCycle()
{
    PrepareData();
    mu_assert(" ", m_pDirectedCycle->HasCycle() == true);
    DeleteData();
    return NULL;
}

char* TestDirectedCycle::TestCycle()
{
    PrepareData();
    std::stack<int> stackCycle = m_pDirectedCycle->Cycle();
    mu_assert(" ", stackCycle.size() == 4);
    mu_assert(" ", stackCycle.top() == 3);
    stackCycle.pop();
    mu_assert(" ", stackCycle.top() == 5);
    stackCycle.pop();
    mu_assert(" ", stackCycle.top() == 4);
    stackCycle.pop();
    mu_assert(" ", stackCycle.top() == 3);
    DeleteData();
    return NULL;
}

//test main
//int main()
//{
//    TestDirectedCycle testDirectedCycle;
//    mu_run_test(testDirectedCycle.Tests);
//    return 0;
//}









