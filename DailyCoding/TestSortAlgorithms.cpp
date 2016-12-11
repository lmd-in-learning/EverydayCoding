//
//  TestSortAlgorithms.cpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "TestSortAlgorithms.h"
#include "SortAlgorithms.h"

#include <stdlib.h>
#include <assert.h>

TestSortAlgorithms::TestSortAlgorithms()
{
    
}

TestSortAlgorithms::~TestSortAlgorithms()
{
    
}

void TestSortAlgorithms::PrepareData()
{
    m_array = new ArrayInt(10);
    m_array->Push(1);
    m_array->Push(5);
    m_array->Push(3);
    m_array->Push(4);
    m_array->Push(2);
}

void TestSortAlgorithms::DeleteData()
{
    m_array->Clear();
}

void TestSortAlgorithms::RunTests()
{
    RunSelectSort();
    RunInsertionSort();
    RunShellSort();
    RunQuickSort();
    RunQuick3WaySort();
    RunHeapSort();
}

void TestSortAlgorithms::RunSelectSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.SelectSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunInsertionSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.InsertionSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunShellSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.ShellSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunMergeSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.MergeSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunQuickSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.QuickSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunQuick3WaySort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.Quick3Way(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

void TestSortAlgorithms::RunHeapSort()
{
    PrepareData();
    SortAlgorithms sort;
    sort.HeapSort(*m_array);
    assert(sort.IsSorted(*m_array));
    DeleteData();
}

//UNIT TEST CASE
int main()
{
    TestSortAlgorithms test;
    test.RunTests();
    return 0;
}





