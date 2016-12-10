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
    TestOperatorConst();
    TestClear();
    TestCopyConstructor();
    TestAssignment();
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
    
    int& num = test[0];
    num = 5;
    
    assert(test[0] == 5);
    assert(test[1] == 2);
    assert(test[2] == 3);
}

void TestArrayInt::TestOperatorConst()
{
    ArrayInt test(3);
    
    test.Push(1);
    test.Push(2);
    test.Push(3);
    
    int num = test[0];
    num = 5;
    assert(test[0] == 1);
    assert(test[1] == 2);
    assert(test[2] == 3);
}

void TestArrayInt::TestClear()
{
    ArrayInt test(3);
    
    test.Push(1);
    test.Push(2);
    test.Push(3);

    test.Clear();
    assert(test.GetSize() == 0);
    
    test.Push(1);
    assert(test.GetSize() == 1);
}

void TestArrayInt::TestCopyConstructor()
{
    ArrayInt test(3);
    test.Push(1);
    test.Push(2);
    test.Push(3);
    
    ArrayInt copyTest(test);
    assert(copyTest.GetSize() == test.GetSize());
    assert(copyTest[0] = test[0]);
    assert(copyTest[1] = test[1]);
    assert(copyTest[2] = test[2]);
}

void TestArrayInt::TestAssignment()
{
    ArrayInt test(3);
    test.Push(1);
    test.Push(2);
    test.Push(3);
    
    ArrayInt assignTest;
    assignTest = test;
    assert(assignTest.GetSize() == test.GetSize());
    assert(assignTest[0] = test[0]);
    assert(assignTest[1] = test[1]);
    assert(assignTest[2] = test[2]);
}
//test main
//int main()
//{
//    TestArrayInt runTest;
//    runTest.RunTests();
//    
//    return 0;
//}
























