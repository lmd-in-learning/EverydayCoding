//
//  TestMaxPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include "TestMaxPQ.h"
#include "MaxPQ.h"
#include "UnitTest.h"

TestMaxPQ::TestMaxPQ()
{
    
}

TestMaxPQ::~TestMaxPQ()
{
    if (NULL != m_pMaxPQ)
    {
        delete m_pMaxPQ;
        m_pMaxPQ = NULL;
    }
}

void TestMaxPQ::PrepareData()
{
    m_pMaxPQ = new MaxPQ(10);
    m_pMaxPQ->Insert(1);
    m_pMaxPQ->Insert(2);
    m_pMaxPQ->Insert(3);
    m_pMaxPQ->Insert(4);
    m_pMaxPQ->Insert(5);
}

void TestMaxPQ::DeleteData()
{
    if (NULL != m_pMaxPQ)
    {
        delete m_pMaxPQ;
        m_pMaxPQ = NULL;
    }
}

char* TestMaxPQ::Tests()
{
    mu_run_test(TestMax);
    mu_run_test(TestInsert);
    mu_run_test(TestDelMax);
    mu_run_test(TestIsEmpty);
    mu_run_test(TestSize);
    
    return NULL;
}

char* TestMaxPQ::TestMax()
{
    PrepareData();
    mu_assert(" ", m_pMaxPQ->Max() == 5);
    DeleteData();
    
    return NULL;
}

char* TestMaxPQ::TestInsert()
{
    PrepareData();
    mu_assert(" ",m_pMaxPQ->Size() == 5);
    m_pMaxPQ->Insert(5);
    mu_assert(" ",m_pMaxPQ->Size() == 6);
    DeleteData();
    
    return NULL;
}

char* TestMaxPQ::TestDelMax()
{
    PrepareData();
    mu_assert(" ", m_pMaxPQ->DelMax() == 5);
    mu_assert(" ", m_pMaxPQ->Size() == 4);
    mu_assert(" ", m_pMaxPQ->DelMax() == 4);
    mu_assert(" ", m_pMaxPQ->Size() == 3);
    m_pMaxPQ->Insert(6);
    mu_assert(" ", m_pMaxPQ->DelMax() == 6);
    mu_assert(" ", m_pMaxPQ->Size() == 3);
    DeleteData();
    return NULL;
}

char* TestMaxPQ::TestIsEmpty()
{
    m_pMaxPQ = new MaxPQ(10);
    mu_assert(" ", m_pMaxPQ->IsEmpty());
    if (NULL != m_pMaxPQ)
    {
        delete m_pMaxPQ;
        m_pMaxPQ = NULL;
    }
    return NULL;
}

char* TestMaxPQ::TestSize()
{
    PrepareData();
    mu_assert(" ",m_pMaxPQ->Size() == 5);
    DeleteData();
    return NULL;
}

//test main
//int main()
//{
//    TestMaxPQ MaxPQTest;
//    mu_run_test(MaxPQTest.Tests);
//    return 0;
//}
















