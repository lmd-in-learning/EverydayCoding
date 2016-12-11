//
//  TestIndexMinPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include "TestIndexMinPQ.h"
#include "IndexMinPQ.h"
#include "UnitTest.h"
#include "OutputString.h"

TestIndexMinPQ::TestIndexMinPQ()
{
    
}

TestIndexMinPQ::~TestIndexMinPQ()
{
    if (NULL != m_pIndexMinPQ)
    {
        delete m_pIndexMinPQ;
        m_pIndexMinPQ = NULL;
    }
}

void TestIndexMinPQ::PrepareData()
{
    //size = 15, min = 1, minIndex = 4;
    m_pIndexMinPQ = new IndexMinPQ(20);
    m_pIndexMinPQ->Insert(0, 11);
    m_pIndexMinPQ->Insert(1, 2);
    m_pIndexMinPQ->Insert(2, 3);
    m_pIndexMinPQ->Insert(3, 1);
    m_pIndexMinPQ->Insert(4, 5);
    m_pIndexMinPQ->Insert(5, 5);
    m_pIndexMinPQ->Insert(6, 6);
    m_pIndexMinPQ->Insert(7, 4);
    m_pIndexMinPQ->Insert(8, 11);
    m_pIndexMinPQ->Insert(9, 7);
    m_pIndexMinPQ->Insert(10, 15);
    m_pIndexMinPQ->Insert(11, 12);
    m_pIndexMinPQ->Insert(12, 14);
    m_pIndexMinPQ->Insert(13, 20);
    m_pIndexMinPQ->Insert(14, 18);
}

void TestIndexMinPQ::DeleteData()
{
    if (NULL != m_pIndexMinPQ)
    {
        delete m_pIndexMinPQ;
        m_pIndexMinPQ = NULL;
    }
}

char* TestIndexMinPQ::Tests()
{
    mu_run_test(TestIsEmpty);
    mu_run_test(TestSize);
    mu_run_test(TestContains);
    mu_run_test(TestInsert);
    mu_run_test(TestChange);
    mu_run_test(TestDeltete);
    mu_run_test(TestMin);
    mu_run_test(TestMinIndex);
    mu_run_test(TestDelMin);
    
    return NULL;
}

char* TestIndexMinPQ::TestIsEmpty()
{
    m_pIndexMinPQ = new IndexMinPQ(10);
    mu_assert(" ", m_pIndexMinPQ->IsEmpty());
    if (NULL != m_pIndexMinPQ)
    {
        delete m_pIndexMinPQ;
        m_pIndexMinPQ = NULL;
    }
    return NULL;
}

char* TestIndexMinPQ::TestSize()
{
    PrepareData();
    mu_assert(" ", m_pIndexMinPQ->Size() == 15);
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestContains()
{
    PrepareData();
    mu_assert("", m_pIndexMinPQ->Contains(1));
    mu_assert("", m_pIndexMinPQ->Contains(2));
    mu_assert("", m_pIndexMinPQ->Contains(3));
    mu_assert("", m_pIndexMinPQ->Contains(4));
    mu_assert("", m_pIndexMinPQ->Contains(5));
    
    mu_assert("", !m_pIndexMinPQ->Contains(19));
    mu_assert("", !m_pIndexMinPQ->Contains(18));
    mu_assert("", !m_pIndexMinPQ->Contains(16));
    mu_assert("", !m_pIndexMinPQ->Contains(17));
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestInsert()
{
    PrepareData();
    mu_assert("", !m_pIndexMinPQ->Contains(15));
    mu_assert("", m_pIndexMinPQ->Size() == 15);
    m_pIndexMinPQ->Insert(15, 16);
    mu_assert("", m_pIndexMinPQ->Size() == 16);
    mu_assert("", m_pIndexMinPQ->Contains(15));
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestChange()
{
    PrepareData();
    m_pIndexMinPQ->Change(3, 16);
    return NULL;
}

char* TestIndexMinPQ::TestDeltete()
{
    PrepareData();
    mu_assert("", m_pIndexMinPQ->Contains(3));
    mu_assert("", m_pIndexMinPQ->Size() == 15);
    
    m_pIndexMinPQ->Delete(3);
    mu_assert("", !m_pIndexMinPQ->Contains(3));
    mu_assert("", m_pIndexMinPQ->Size() == 14);
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestMin()
{
    PrepareData();
    mu_assert("", m_pIndexMinPQ->Min() == 1);
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestMinIndex()
{
    PrepareData();
    mu_assert("", m_pIndexMinPQ->MinIndex() == 3);
    DeleteData();
    return NULL;
}

char* TestIndexMinPQ::TestDelMin()
{
    PrepareData();
    mu_assert("", m_pIndexMinPQ->Min() == 1);
    mu_assert("", m_pIndexMinPQ->MinIndex() == 3);
    
    mu_assert("", m_pIndexMinPQ->DelMin() == 3);
    
    mu_assert("", m_pIndexMinPQ->Min() == 2);
    mu_assert("", m_pIndexMinPQ->MinIndex() == 1);
    DeleteData();
    return NULL;
}


//test main
int main()
{
    TestIndexMinPQ IndexMinPQTest;
    mu_run_test(IndexMinPQTest.Tests);
    return 0;
}



