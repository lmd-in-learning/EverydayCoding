//
//  MinPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include "MinPQ.h"

MinPQ::MinPQ():
m_nSize(0),
m_PQ(ArrayInt())
{
    
}

MinPQ::MinPQ(int max):
m_nSize(0),
m_PQ(ArrayInt(max))
{
    
}

MinPQ::~MinPQ()
{
    
}

void MinPQ::Insert(int v)
{
    m_PQ.Insert(++m_nSize, v);
    Swim(m_nSize);
}

int MinPQ::Min() const
{
    return m_PQ[1];
}

int MinPQ::DelMin()
{
    int max = m_PQ[1];
    Exch(1, m_nSize--);
    m_PQ[m_nSize + 1] = NULL;
    Sink(1);
    return max;
}

bool MinPQ::IsEmpty() const
{
    return m_nSize == 0;
}

int MinPQ::Size() const
{
    return m_nSize;
}

bool MinPQ::Less(int i, int j) const
{
    assert(i >= 0 && i <= m_nSize);
    assert(j >= 0 && j <= m_nSize);
    return m_PQ[i] < m_PQ[j];
}

bool MinPQ::Greater(int i, int j) const
{
    assert(i >= 0 && i <= m_nSize);
    assert(j >= 0 && j <= m_nSize);
    return m_PQ[i] > m_PQ[j];
}

void MinPQ::Exch(int i, int j)
{
    assert(i >= 0);
    assert(j >= 0);
    int tmp = m_PQ[i];
    m_PQ[i] = m_PQ[j];
    m_PQ[j] = tmp;
}

void MinPQ::Swim(int k)
{
    assert(k >= 0);
    while (k > 1 && Greater(k/2, k))
    {
        Exch(k, k/2);
        k = k/2;
    }
}

void MinPQ::Sink(int k)
{
    assert(k >= 0);
    while (2 * k <= m_nSize)
    {
        int j = 2 * k;
        if (j < m_nSize && Greater(j, j + 1))
        {
            j++;
        }
        if (!Greater(k, j))
        {
            break;
        }
        Exch(k, j);
        k = j;
    }
}
