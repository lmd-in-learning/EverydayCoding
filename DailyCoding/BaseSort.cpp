//
//  BaseSort.cpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "BaseSort.h"
#include "stdlib.h"
#include <assert.h>


BaseSort::BaseSort()
{
    
}

BaseSort::~BaseSort()
{
    
}

bool BaseSort::Less(int a, int b) const
{
    return a < b;
}

void BaseSort::ExchangePos(ArrayInt &array, int nPosi, int nPosj)
{
    assert(nPosi > 0 && nPosi < array.GetSize());
    assert(nPosj > 0 && nPosj < array.GetSize());
    
    int tmp = array[nPosi];
    array[nPosi] = array[nPosj];
    array[nPosj] = tmp;
}

void BaseSort::Show(ArrayInt &array) const
{
    for (int i = 0; i < array.GetSize(); ++i)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

bool BaseSort::IsSorted(ArrayInt &array) const
{
    for (int i = 1; i < array.GetSize(); ++i)
    {
        if (Less(array[i], array[i - 1]))
        {
            return false;
        }
    }
    return true;
}
