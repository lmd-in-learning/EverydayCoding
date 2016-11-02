//
//  InsertionSort.cpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "SortAlgorithms.h"
#include "ArrayInt.h"
#include <stdlib.h>
#include <assert.h>

SortAlgorithms::SortAlgorithms()
{
    
}

SortAlgorithms::~SortAlgorithms()
{
    
}

void SortAlgorithms::SelectSort(ArrayInt &array)
{
    assert(!array.IsEmpty());
    
    for (int i = 0; i < array.GetSize() - 1; ++i)
    {
        int nMinPos = i;
        for(int j = i + 1; j < array.GetSize(); ++j)
        {
            if (Less(array[j], array[nMinPos]))
            {
                nMinPos = j;
            }
        }
        ExchangePos(array, i, nMinPos);
    }
}

void SortAlgorithms::InsertionSort(ArrayInt &array)
{
    assert(!array.IsEmpty());
    
    for (int i = 1; i < array.GetSize(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (Less(array[j], array[j - 1]))
            {
                ExchangePos(array, j, j - 1);
            }
            else
            {
                break;
            }
        }
    }
}

void SortAlgorithms::ShellSort(ArrayInt &array)
{
    assert(!array.IsEmpty());
    
    int h = 1;
    while (h < array.GetSize() / 3)
    {
        h = h * 3 + 1;
    }
    
    while (h >= 1)
    {
        for (int i = h; i < array.GetSize(); ++i)
        {
            for (int j = i; j >= h; j -= h)
            {
                if (Less(array[j], array[j - h]))
                {
                    ExchangePos(array, j, j - h);
                }
            }
            
        }
        h = h / 3;
    }
}

void SortAlgorithms::MergeSort(ArrayInt &array)
{
    MergeRecursion(array, 0, array.GetSize());
}

void SortAlgorithms::MergeRecursion(ArrayInt &array, int nLow, int nHigh)
{
    if (nLow <= nHigh)
    {
        return;
    }
    
    int nMid = nLow + (nHigh - nLow)/2;
    MergeRecursion(array, nLow, nMid);
    MergeRecursion(array, nMid + 1, nHigh);
    Merge(array, nLow, nMid, nHigh);
}

void SortAlgorithms::Merge(ArrayInt &array, int nLow, int nMid, int nHigh)
{
    //左边用尽（取右边）右边用尽（取左边）
    //右半边当前元素小于左半边（取右半边），右半边当前元素大于等于左半边（取左半边）
    int i = nLow;
    int j = nMid + 1;
    
    ArrayInt tmpArray(array);
    for (int k = nLow; k <= nHigh; ++k)
    {
        if (i > nMid)
        {
            array[k] = tmpArray[j++];
        }
        else if (j > nHigh)
        {
            array[k] = tmpArray[i++];
        }
        else if(Less(tmpArray[j], tmpArray[i]))
        {
            array[k] = tmpArray[j++];
        }
        else
        {
            array[k] = tmpArray[i++];
        }
    }
}

//UNIT TEST CASE
//int main()
//{
//    return 0;
//}



























