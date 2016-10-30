//
//  TestBinaryTree.cpp
//  DailyCoding
//
//  Created by limingding on 10/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "TestBinaryTree.h"
#include <stdlib.h>
#include <assert.h>
#include "BinaryTree.h"

void TestBinaryTree::RunTests()
{
    TestInsert();
    TestGetSize();
    TestSearch();
    TestGetMinNode();
    TestGetMaxNode();
    TestDestroy();
}

void TestBinaryTree::TestInsert()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    pTree->Insert(0);
    assert(pTree->GetSize() == 1);
    pTree->Insert(1);
    assert(pTree->GetSize() == 2);
    pTree->Insert(2);
    assert(pTree->GetSize() == 3);
}

void TestBinaryTree::TestSearch()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    pTree->Insert(0);
    Node* pNode = pTree->Search(0);
    assert(pNode != NULL);
    assert(pNode->key_value == 0);
    
    pTree->Insert(1);
    pNode = pTree->Search(1);
    assert(pNode != NULL);
    assert(pNode->key_value == 1);
    
    pNode = pTree->Search(2);
    assert(pNode == NULL);
}

void TestBinaryTree::TestGetSize()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    assert(pTree->GetSize() == 0);
    pTree->Insert(0);
    assert(pTree->GetSize() == 1);
    pTree->Insert(1);
    assert(pTree->GetSize() == 2);
    pTree->Insert(2);
    assert(pTree->GetSize() == 3);
}

void TestBinaryTree::TestGetMinNode()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    pTree->Insert(0);
    pTree->Insert(1);
    pTree->Insert(2);
    
    Node* minNode = pTree->GetMinNode();
    assert(minNode != NULL);
    assert(minNode->key_value == 0);
}

void TestBinaryTree::TestGetMaxNode()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    pTree->Insert(0);
    pTree->Insert(1);
    pTree->Insert(2);
    
    Node* maxNode = pTree->GetMaxNode();
    assert(maxNode != NULL);
    assert(maxNode->key_value == 2);
}

void TestBinaryTree::TestDestroy()
{
    BinaryTree* pTree = new BinaryTree();
    assert(pTree);
    
    pTree->Insert(0);
    pTree->Insert(1);
    pTree->Insert(2);

    assert(pTree->GetSize() == 3);
    
    pTree->DestroyTree();
    assert(pTree->GetSize() == 0);
}

//test
int main()
{
    TestBinaryTree test;
    test.RunTests();
    return 0;
}







