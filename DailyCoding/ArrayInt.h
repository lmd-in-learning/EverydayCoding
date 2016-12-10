//
//  ArrayInt.h
//  HelloWorld
//
//  Created by limingding on 10/22/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef ArrayInt_h
#define ArrayInt_h

class ArrayInt
{
    //constructor
public:
    ArrayInt(int nCapacity);
    ArrayInt();
    ~ArrayInt();
    ArrayInt(const ArrayInt& array);
    ArrayInt& operator = (const ArrayInt& array);
    
    //public functions
public:
    //return the num of stored size
    int GetSize() const;
    
    //push the item in back
    void Push(int nItem);
    
    //add item on pos
    void Insert(int nIndex, int nItem);
    
    //remove the index item
    void Remove(int nIndex);
    
    //true is empty
    bool IsEmpty();
    
    //reference operator [] for fetch index
    int& operator[](int nIndex);
    
    //return value operator [] for fetch index
    int operator[](int nIndex) const;
    
    //clear all the items
    void Clear();
    
    //private functions
private:
    //check if has space for stored, if not, Inflate stored size
    void CheckIsFull();
    
    //increase stroed space when is full
    void Inflate(int nIncrease);
    
    //private members
private:
    //stored num
    int* m_pArray;
    
    //capacity num
    int m_nCapacity;
    
    //stored num
    int m_nSize;
    
};

#endif /* ArrayInt_h */
