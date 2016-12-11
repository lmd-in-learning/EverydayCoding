//
//  IndexMinPQ.cpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include "IndexMinPQ.h"

IndexMinPQ::IndexMinPQ():
m_PQ(),
m_QP(),
m_keys(),
m_nSize(0),
m_nMaxN(0)
{
    
}

IndexMinPQ::IndexMinPQ(int maxN):
m_PQ(maxN + 1),
m_QP(maxN + 1),
m_keys(maxN + 1),
m_nSize(0),
m_nMaxN(maxN)
{
    for (int i = 0; i <= maxN; ++i)
    {
        m_QP[i] = -1;
    }
}

bool IndexMinPQ::IsEmpty() const
{
    return m_nSize == 0;
}

bool IndexMinPQ::Contains(int k) const
{
    assert(k >= 0 && k < m_nMaxN);
    return m_QP[k] != -1;
}

int IndexMinPQ::Size() const
{
    return m_nSize;
}

void IndexMinPQ::Insert(int k, int val)
{
    assert(k >= 0 && k < m_nMaxN);
    
    m_nSize++;
    m_QP[k] = m_nSize;
    m_PQ[m_nSize] = k;
    m_keys[k] = val;
    Swim(m_nSize);
}

void IndexMinPQ::Change(int k, int val)
{
    assert(k >= 0 && k < m_nMaxN);
    
    m_keys[k] = val;
    Swim(m_QP[k]);
    Sink(m_QP[k]);
}

void IndexMinPQ::Delete(int k)
{
    assert(k >= 0 && k < m_nMaxN);
    int index = m_PQ[k];
    Exch(index, m_nSize--);
    Swim(index);
    Sink(index);
    m_keys[k] = NULL;
    m_QP[k] = -1;
}

int IndexMinPQ::Min() const
{
    assert(m_nSize > 0);
    return m_keys[m_PQ[1]];
}

int IndexMinPQ::MinIndex() const
{
    assert(m_nSize > 0);
    return m_PQ[1];
}

int IndexMinPQ::DelMin()
{
    assert(m_nSize > 0);
    int indexOfMin = m_PQ[1];
    Exch(1, m_nSize--);
    Sink(1);
    m_keys[m_PQ[m_nSize + 1]] = NULL;
    m_QP[m_QP[m_nSize + 1]] = -1;
    return indexOfMin;
}

bool IndexMinPQ::Less(int i, int j) const
{
    assert(i >= 0 && i <= m_nMaxN);
    assert(j >= 0 && j <= m_nMaxN);
    return m_PQ[i] < m_PQ[j];
}

bool IndexMinPQ::Greater(int i, int j) const
{
    assert(i >= 0 && i <= m_nMaxN);
    assert(j >= 0 && j <= m_nMaxN);
    return m_PQ[i] > m_PQ[j];
}

void IndexMinPQ::Exch(int i, int j)
{
    assert(i >= 0);
    assert(j >= 0);
    int swap = m_PQ[i];
    m_PQ[i] = m_PQ[j];
    m_PQ[j] = swap;
    m_QP[m_PQ[i]] = i;
    m_QP[m_PQ[j]] = j;
}

void IndexMinPQ::Swim(int k)
{
    assert(k >= 0);
    while (k > 1 && Greater(k/2, k))
    {
        Exch(k, k/2);
        k = k/2;
    }
}

void IndexMinPQ::Sink(int k)
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



