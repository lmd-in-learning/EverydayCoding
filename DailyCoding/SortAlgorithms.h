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
    
    //merge sort algotithm
    void MergeSort(ArrayInt& array);
    
private:
    void Merge(ArrayInt& array, int nLow, int nMid, int nHigh);
    
    void MergeRecursion(ArrayInt& array, int nLow, int nHigh);
    
};

#endif /* InsertionSort_h */
