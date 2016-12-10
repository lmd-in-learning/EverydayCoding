//
//  Uncopyable.cpp
//  DailyCoding
//
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "Uncopyable.h"

Uncopyable::Uncopyable()
{
    
}

Uncopyable::~Uncopyable()
{
    
}

Uncopyable::Uncopyable(const Uncopyable& src)
{
    
}

Uncopyable& Uncopyable::operator=(const Uncopyable &src)
{
    if (this == &src)
    {
        return *this;
    }
    return *this;
}
