//
//  TestArrayInt.cpp
//  HelloWorld
//
//  Created by limingding on 10/24/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "TestArrayInt.h"
#include <assert.h>
#include <stdlib.h>
#include "ArrayInt.h"


void TestArrayInt::RunTests()
{
    TestGetSize();
    TestPush();
    TestInsert();
    TestRemove();
    TestIsEmpty();
    TestOperator();
}

void TestArrayInt::TestGetSize()
{
    ArrayInt test(3);
    
    for (int i = 0; i < 5; ++i)
    {
        test.Push(i);
    }
    
    assert(test.GetSize() == 5);
}

void TestArrayInt::TestPush()
{
    ArrayInt test(3);
    
    for (int i = 0; i < 5; ++i)
    {
        test.Push(i);
        assert(test.GetSize() == i + 1);
    }
}

void TestArrayInt::TestInsert()
{
    ArrayInt test(3);
    test.Push(0);
    test.Push(1);
    test.Push(2);
    
    test.Insert(0, 3);
    
    assert(test[0] == 3);
    assert(test[1] == 0);
    assert(test[2] == 1);
    assert(test[3] == 2);
}

void TestArrayInt::TestRemove()
{
    ArrayInt test(3);
    
    test.Push(1);
    test.Push(2);
    test.Push(3);
    
    test.Remove(1);
    
    assert(test.GetSize() == 2);
    assert(test[0] == 1);
    assert(test[1] == 3);
}

void TestArrayInt::TestIsEmpty()
{
    ArrayInt test(3);
    
    assert(test.IsEmpty());
}

void TestArrayInt::TestOperator()
{
    ArrayInt test(3);
    
    test.Push(1);
    test.Push(2);
    test.Push(3);
    
    test[0] = 5;
    
    assert(test[0] == 5);
    assert(test[1] == 2);
    assert(test[2] == 3);
}


//test main
int main()
{
    TestArrayInt runTest;
    runTest.RunTests();
    
    return 0;
}
























