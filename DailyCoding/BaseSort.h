//
//  BaseSort.hpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef BaseSort_h
#define BaseSort_h

#include <stdio.h>
#include "ArrayInt.h"

class BaseSort {
    
public:
    BaseSort();
    ~BaseSort();
    
    //sort the array int
    virtual void Sort(ArrayInt& array) = 0;
    
    //true if a < b
    bool Less(int a, int b) const;
    
    //exchange index i value with index j value
    void ExchangePos(ArrayInt& array, int nPosi, int nPosj);
    
    //show the result
    void Show(ArrayInt& array) const;
    
    //false if array is not sorted
    bool IsSorted(ArrayInt& array) const;
    
public:
    
};
#endif /* BaseSort_h */
