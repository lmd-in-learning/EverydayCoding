//
//  BinaryTree.h
//  HelloWorld
//
//  Created by limingding on 10/20/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include "Node.h"


class BinaryTree {
    
public:
    //<#member functions#>
    BinaryTree();
    ~BinaryTree();
    
    void Insert(int key);
    
    Node* Search(int key) const;
    
    void DestroyTree();
    
    Node* GetMinNode() const;
    
    Node* GetMaxNode() const;
    
    int GetSize() const;
    
private:
    Node* m_Root;
    
    int m_nNodeCounts;
    
    void Insert(int key, Node* leafNode);
    
    Node* Search(int key, Node* leafNode) const;
    
    void DestroyTree(Node* leafNode);
    
    Node* Min(Node* leafNode) const;
    
    Node* Max(Node* leafNode) const;
};

#endif /* BinaryTree_h */
