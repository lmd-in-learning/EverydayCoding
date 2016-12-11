//
//  MinPQ.hpp
//  DailyCoding
//
//  Description: just need to reverse the Less to Greater can change the MaxPQ into MinPQ
//  Created by limingding on 12/11/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef MinPQ_h
#define MinPQ_h

#include <stdio.h>

#include <stdio.h>
#include "Uncopyable.h"
#include "ArrayInt.h"

class MinPQ : private Uncopyable
{
    //constructor
public:
    MinPQ();
    //init a max size of priority queue
    MinPQ(int max);
    
    ~MinPQ();
    
    //public functios
public:
    //use int array as example
    //insert a value
    void Insert(int v);
    
    //get the max value
    int Min() const;
    
    //delete the max and return the value
    int DelMin();
    
    //return true if queue is empty
    bool IsEmpty() const;
    
    //return the size of the queue
    int Size() const;
    
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
    //the queue
    ArrayInt m_PQ;
    
    //the size of the queue
    int m_nSize;
    
    // maximum number of elements on PQ
    int m_nMaxN;
};

#endif /* MinPQ_h */
