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
    //select sort algorithms
    void SelectSort(ArrayInt& array);
    
    //insertion sort algorithms
    void InsertionSort(ArrayInt& array);
    
};

#endif /* InsertionSort_h */
