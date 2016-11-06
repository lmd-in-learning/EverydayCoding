//
//  TestSortAlgorithms.hpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef TestSortAlgorithms_h
#define TestSortAlgorithms_h

#include <stdio.h>
class ArrayInt;

class TestSortAlgorithms
{
public:
    TestSortAlgorithms();
    ~TestSortAlgorithms();
    
public:
    void RunTests();
    
    void RunSelectSort();
    
    void RunInsertionSort();
    
    void RunShellSort();
    
    void RunMergeSort();
    
    void RunQuickSort();
    
    void RunQuick3WaySort();
    
private:
    void PrepareData();
    
    void DeleteData();
    
    ArrayInt* m_array;
};
#endif /* TestSortAlgorithms_h */
