//
//  TestMinPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include "TestMinPQ.h"
#include "MinPQ.h"
#include "UnitTest.h"

TestMinPQ::TestMinPQ()
{
    
}

TestMinPQ::~TestMinPQ()
{
    if (NULL != m_pMinPQ)
    {
        delete m_pMinPQ;
        m_pMinPQ = NULL;
    }
}

void TestMinPQ::PrepareData()
{
    m_pMinPQ = new MinPQ(10);
    m_pMinPQ->Insert(1);
    m_pMinPQ->Insert(2);
    m_pMinPQ->Insert(3);
    m_pMinPQ->Insert(4);
    m_pMinPQ->Insert(5);
}

void TestMinPQ::DeleteData()
{
    if (NULL != m_pMinPQ)
    {
        delete m_pMinPQ;
        m_pMinPQ = NULL;
    }
}

char* TestMinPQ::Tests()
{
    mu_run_test(TestMin);
    mu_run_test(TestInsert);
    mu_run_test(TestDelMin);
    mu_run_test(TestIsEmpty);
    mu_run_test(TestSize);
    
    return NULL;
}

char* TestMinPQ::TestMin()
{
    PrepareData();
    mu_assert(" ", m_pMinPQ->Min() == 1);
    DeleteData();
    
    return NULL;
}

char* TestMinPQ::TestInsert()
{
    PrepareData();
    mu_assert(" ",m_pMinPQ->Size() == 5);
    m_pMinPQ->Insert(5);
    mu_assert(" ",m_pMinPQ->Size() == 6);
    DeleteData();
    
    return NULL;
}

char* TestMinPQ::TestDelMin()
{
    PrepareData();
    mu_assert(" ", m_pMinPQ->DelMin() == 1);
    mu_assert(" ", m_pMinPQ->Size() == 4);
    mu_assert(" ", m_pMinPQ->DelMin() == 2);
    mu_assert(" ", m_pMinPQ->Size() == 3);
    m_pMinPQ->Insert(1);
    mu_assert(" ", m_pMinPQ->DelMin() == 1);
    mu_assert(" ", m_pMinPQ->Size() == 3);
    DeleteData();
    return NULL;
}

char* TestMinPQ::TestIsEmpty()
{
    m_pMinPQ = new MinPQ(10);
    mu_assert(" ", m_pMinPQ->IsEmpty());
    if (NULL != m_pMinPQ)
    {
        delete m_pMinPQ;
        m_pMinPQ = NULL;
    }
    return NULL;
}

char* TestMinPQ::TestSize()
{
    PrepareData();
    mu_assert(" ",m_pMinPQ->Size() == 5);
    DeleteData();
    return NULL;
}

//test main
int main()
{
    TestMinPQ MinPQTest;
    mu_run_test(MinPQTest.Tests);
    return 0;
}
