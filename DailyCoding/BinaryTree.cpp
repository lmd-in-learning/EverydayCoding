//
//  BinaryTree.cpp
//  HelloWorld
//
//  Created by limingding on 10/20/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "BinaryTree.h"
#include <cstdlib>

BinaryTree::BinaryTree():
m_Root(NULL),
m_nNodeCounts(0)
{
    
}

BinaryTree::~BinaryTree()
{
    DestroyTree();
}

void BinaryTree::Insert(int key)
{
    if (NULL != m_Root)
    {
        Insert(key, m_Root);
    }
    else
    {
        m_Root = new Node;
        m_Root->key_value = key;
        m_Root->left = NULL;
        m_Root->right = NULL;
    }
    
    m_nNodeCounts++;
}

Node* BinaryTree::Search(int key) const
{
    return Search(key, m_Root);
}

void BinaryTree::DestroyTree()
{
    DestroyTree(m_Root);
}

void BinaryTree::Insert(int key, Node* leafNode)
{
    if (key < leafNode->key_value)
    {
        if (NULL == leafNode->left)
        {
            leafNode->left = new Node;
            leafNode->left->key_value = key;
            leafNode->left->left = NULL;
            leafNode->left->right = NULL;
        }
        else
        {
            Insert(key, leafNode->left);
        }
    }
    else
    {
        if (NULL == leafNode->right)
        {
            leafNode->right = new Node;
            leafNode->right->key_value = key;
            leafNode->right->left = NULL;
            leafNode->right->right = NULL;
        }
        else
        {
            Insert(key, leafNode->right);
        }
    }
}

Node* BinaryTree::Search(int key, Node* leafNode) const
{
    if (NULL == leafNode)
    {
        return NULL;
    }
    
    if (key == leafNode->key_value)
    {
        return leafNode;
    }
    else if(key < leafNode->key_value)
    {
        return Search(key, leafNode->left);
    }
    else
    {
        return Search(key, leafNode->right);
    }
    
    return NULL;
}

void BinaryTree::DestroyTree(Node* leafNode)
{
    if (NULL != leafNode)
    {
        DestroyTree(leafNode->left);
        DestroyTree(leafNode->right);
        delete leafNode;
    }
}

Node* BinaryTree::GetMinNode() const
{
    if (NULL != m_Root)
    {
        return Min(m_Root);
    }
    
    return NULL;
}

Node* BinaryTree::Min(Node* leafNode) const
{
    if (NULL != leafNode)
    {
        if (NULL == leafNode->left)
        {
            return leafNode;
        }
        else
        {
            return  Min(leafNode->left);
        }
    }
    return NULL;
}

Node* BinaryTree::GetMaxNode() const
{
    if (NULL != m_Root)
    {
        return Max(m_Root);
    }
    
    return  NULL;
}

Node* BinaryTree::Max(Node *leafNode) const
{
    if (NULL != leafNode)
    {
        if (NULL == leafNode->right)
        {
            return leafNode;
        }
        else
        {
            return Max(leafNode->right);
        }
    }
    return NULL;
}

int BinaryTree::GetSize() const
{
    return m_nNodeCounts;
}















