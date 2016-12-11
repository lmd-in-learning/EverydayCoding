//
//  IndexMinPQ.hpp
//  DailyCoding
//
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef IndexMinPQ_h
#define IndexMinPQ_h

#include <stdio.h>
#include "ArrayInt.h"

class IndexMinPQ
{
    //constructor
public:
    IndexMinPQ();
    
    //init a max size PQ,index from 0 to maxN - 1
    IndexMinPQ(int maxN);
    
    ~IndexMinPQ();
    
    //public functions
public:
    //return true if pq is empty
    bool IsEmpty() const;
    
    //return the size of pq
    int Size() const;
    
    //return true if pq[k] exists
    bool Contains(int k) const;
    
    //insert a element pq[k] = val
    void Insert(int k, int val);
    
    //change the val pq[k] = val
    void Change(int k, int val);
    
    //delete the pq[k]
    void Delete(int k);
    
    //return the min element
    int Min() const;
    
    //return the min element index
    int MinIndex() const;
    
    //retrun and delete the min element
    int DelMin();
    
    //private functions
private:
    //return true if key[i] < key[j]
    bool Less(int i, int j) const;
    
    //return true if key[i] > key[j]
    bool Greater(int i, int j) const;
    
    //exchange the value of key[i] and the value of key[j]
    void Exch(int i, int j);
    
    //swim for orderlize the queue
    void Swim(int k);
    
    //sink for orderlize the queue
    void Sink(int k);
    
    //private members
private:
    // maximum number of elements on PQ
    int m_nMaxN;
    
    // number of elements on PQ
    int m_nSize;
    
    ArrayInt m_PQ;
    
    //the val of qp[i] is the index j of pq, pq[j] = i ,qp[i] = j
    //reverse of m_PQ qp[pq[i]] = pq[qp[i]] = i
    ArrayInt m_QP;
    
    //the keys , but in this version the key is int type
    ArrayInt m_keys;
};

#endif /* IndexMinPQ_h */



