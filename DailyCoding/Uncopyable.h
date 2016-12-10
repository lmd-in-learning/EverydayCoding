//
//  Uncopyable.hpp
//  DailyCoding
//
//  Description[Mask the class default copy function and assignment function]
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Uncopyable_h
#define Uncopyable_h

#include <stdio.h>

class Uncopyable
{
    //constructor
public:
    Uncopyable();
    ~Uncopyable();
    
    //private functions
public:
    Uncopyable(const Uncopyable& src);
    
    Uncopyable& operator = (const Uncopyable& src);
};

#endif /* Uncopyable_h */
