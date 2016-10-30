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

//UNIT TEST CASE
//int main()
//{
//    return 0;
//}