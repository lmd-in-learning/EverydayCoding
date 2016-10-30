//
//  SelectSort.cpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "SelectSort.h"
#include "ArrayInt.h"
#include <assert.h>
#include <stdlib.h>

SelectSort::SelectSort()
{
    
}

SelectSort::~SelectSort()
{
    
}

void SelectSort::Sort(ArrayInt &array)
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

//test
//int main()
//{
//    ArrayInt array(10);
//    for (int i = 0; i < 10; ++i)
//    {
//        array.Push((int)random());
//    }
//    
//    SelectSort sort;
//    sort.Sort(array);
//    
//    sort.Show(array);
//    assert(sort.IsSorted(array));
//    
//}
