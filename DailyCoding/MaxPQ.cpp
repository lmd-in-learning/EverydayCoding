//
//  MaxPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "MaxPQ.h"


MaxPQ::MaxPQ():
m_nSize(0),
m_PQ(ArrayInt())
{
    
}

MaxPQ::MaxPQ(int max):
m_nSize(0),
m_PQ(ArrayInt(max))
{
    
}

MaxPQ::~MaxPQ()
{
    
}

void MaxPQ::Insert(int v)
{
    m_PQ[++m_nSize] = v;
    Swim(m_nSize);
}

int MaxPQ::Max() const
{
    return m_PQ[1];
}

int MaxPQ::DelMax()
{
    int max = m_PQ[1];
    Exch(1, m_nSize--);
    m_PQ[m_nSize + 1] = NULL;
    Sink(1);
    return max;
}

bool MaxPQ::IsEmpty() const
{
    return m_nSize == 0;
}

int MaxPQ::Size() const
{
    return m_nSize;
}

bool MaxPQ::Less(int i, int j) const
{
    assert(i >= 0 && i <= m_nSize);
    assert(j >= 0 && j <= m_nSize);
    return m_PQ[i] < m_PQ[j];
}

void MaxPQ::Exch(int i, int j)
{
    assert(i >= 0 && i <= m_nSize);
    assert(j >= 0 && j <= m_nSize);
    int tmp = m_PQ[i];
    m_PQ[i] = m_PQ[j];
    m_PQ[j] = tmp;
}

void MaxPQ::Swim(int k)
{
    assert(k >= 0 && k <= m_nSize);
    while (k > 1 && Less(k/2, k))
    {
        Exch(k, k/2);
        k = k/2;
    }
}

void MaxPQ::Sink(int k)
{
    assert(k >= 0 && k <= m_nSize);
    while (2 * k <= m_nSize)
    {
        int j = 2 * k;
        if (j < m_nSize && Less(j, j + 1))
        {
            j++;
        }
        if (!Less(k, j))
        {
            break;
        }
        Exch(k, j);
        k = j;
    }
}
















