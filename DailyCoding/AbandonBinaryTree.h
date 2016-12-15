//
//  AbandonBinaryTree.h
//  HelloWorld
//
//  Created by limingding on 10/20/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef AbandonBinaryTree_h
#define AbandonBinaryTree_h
#include "AbandonNode.h"

class AbandonBinaryTree
{
    //constructor
public:
    AbandonBinaryTree();
    ~AbandonBinaryTree();
    
    //public functions
public:
    void Insert(int key);
    
    AbandonNode* Search(int key) const;
    
    void DestroyTree();
    
    AbandonNode* GetMinNode() const;
    
    AbandonNode* GetMaxNode() const;
    
    int GetSize() const;
    
    //private functions
private:
    void Insert(int key, AbandonNode* leafNode);
    
    AbandonNode* Search(int key, AbandonNode* leafNode) const;
    
    void DestroyTree(AbandonNode* leafNode);
    
    AbandonNode* Min(AbandonNode* leafNode) const;
    
    AbandonNode* Max(AbandonNode* leafNode) const;
    
    //private members
private:
    AbandonNode* m_Root;
    
    int m_nNodeCounts;
};

#endif /* BinaryTree_h */
