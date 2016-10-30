//
//  SelectSort.hpp
//  DailyCoding
//
//  Created by limingding on 10/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef SelectSort_h
#define SelectSort_h

#include <stdio.h>
#include "BaseSort.h"

class ArrayInt;
class SelectSort:public BaseSort
{

public:
    SelectSort();
    ~SelectSort();
    
public:
    virtual void Sort(ArrayInt& array);
    
    
};
#endif /* SelectSort_h */
