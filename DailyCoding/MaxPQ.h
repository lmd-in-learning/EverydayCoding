//
//  MaxPQ.hpp
//  DailyCoding
//
//  Created by limingding on 12/10/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef MaxPQ_hpp
#define MaxPQ_hpp

#include <stdio.h>
#include "Uncopyable.h"
#include "ArrayInt.h"

class MaxPQ : private Uncopyable
{
    //constructor
public:
    MaxPQ();
    //init a max size of priority queue
    MaxPQ(int max);
    
    ~MaxPQ();
    
    //public functios
public:
    //use int array as example
    //insert a value
    void Insert(int v);
    
    //get the max value
    int Max() const;
    
    //delete the max and return the value
    int DelMax();
    
    //return true if queue is empty
    bool IsEmpty() const;
    
    //return the size of the queue
    int Size() const;
    
    //private functions
private:
    //return true if key[i] < key[j]
    bool Less(int i, int j) const;
    
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
#endif /* MaxPQ_hpp */
