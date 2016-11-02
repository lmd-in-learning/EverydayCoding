//
//  InsertionSort.hpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef SortAlgorithms_h
#define SortAlgorithms_h

#include <stdio.h>
#include "BaseSort.h"

class ArrayInt;

class SortAlgorithms:public BaseSort
{
    
public:
    SortAlgorithms();
    ~SortAlgorithms();
    
public:
    //select sort algorithm
    void SelectSort(ArrayInt& array);
    
    //insertion sort algorithm
    void InsertionSort(ArrayInt& array);
    
    //shell sort algorithm
    void ShellSort(ArrayInt& array);
    
};

#endif /* InsertionSort_h */
