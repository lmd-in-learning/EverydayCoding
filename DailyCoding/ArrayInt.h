//
//  ArrayInt.h
//  HelloWorld
//
//  Created by limingding on 10/22/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef ArrayInt_h
#define ArrayInt_h

class ArrayInt {
    
public:
    //<#member functions#>
    //set initiliaze capacity
    ArrayInt(int nCapacity);
    ~ArrayInt();
    
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
    
    //operator [] for fetch index
    int& operator[](int nIndex);
    
private:
    //<#instance variables#>
    //stored num
    int* m_pArray;
    
    //capacity num
    int m_nCapacity;
    
    //stored num
    int m_nSize;
    
    //check if has space for stored, if not, Inflate stored size
    void CheckIsFull();
    
    //increase stroed space when is full
    void Inflate(int nIncrease);

};

#endif /* ArrayInt_h */
