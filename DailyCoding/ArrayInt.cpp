//
//  ArrayInt.cpp
//  HelloWorld
//
//  Created by limingding on 10/22/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "ArrayInt.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ArrayInt::ArrayInt(int nCapacity):
m_nSize(0)
{
    m_nCapacity = nCapacity;
    m_pArray = new int[nCapacity];
}

ArrayInt::~ArrayInt()
{
    delete []m_pArray;
}

int ArrayInt::GetSize() const
{
    return m_nSize;
}

void ArrayInt::Push(int nItem)
{
    CheckIsFull();
    m_pArray[m_nSize++] = nItem;
}

void ArrayInt::Insert(int nIndex, int nItem)
{
    assert(nIndex >= 0);
    assert(nIndex < m_nSize);

    CheckIsFull();
    
    for (int i = m_nSize - 1; i >= nIndex; --i)
    {
        m_pArray[i + 1] = m_pArray[i];
    }
    
    m_pArray[nIndex] = nItem;
    m_nSize++;
}

void ArrayInt::Remove(int nIndex)
{
    assert(nIndex >= 0);
    assert(nIndex < m_nSize);
    for (int i = nIndex; i < m_nSize - 1; ++i)
    {
        m_pArray[i] = m_pArray[i + 1];
    }
    
    m_nSize--;
}

bool ArrayInt::IsEmpty()
{
    if (0 == m_nSize)
    {
        return  true;
    }
    return false;
}

int& ArrayInt::operator[](int nIndex)
{
    assert(nIndex >= 0);
    assert(nIndex < m_nSize);
    
    return m_pArray[nIndex];
}

void ArrayInt::Inflate(int nIncrease)
{
    assert(nIncrease > 0);
    int *pTmp = new int[m_nCapacity + nIncrease];
    memset(pTmp, 0, m_nCapacity + nIncrease*sizeof(int));
    memcpy(pTmp, m_pArray, m_nCapacity*sizeof(int));
    
    delete []m_pArray;
    m_pArray = pTmp;
}

void ArrayInt::CheckIsFull()
{
    int nIcrease = GetSize();
    if (m_nSize >= m_nCapacity)
    {
        Inflate(nIcrease);
    }
}



















