//
//  AbandonBinaryTree.cpp
//  HelloWorld
//
//  Created by limingding on 10/20/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "AbandonBinaryTree.h"
#include <cstdlib>

AbandonBinaryTree::AbandonBinaryTree():
m_Root(NULL),
m_nNodeCounts(0)
{
    
}

AbandonBinaryTree::~AbandonBinaryTree()
{
    DestroyTree();
}

void AbandonBinaryTree::Insert(int key)
{
    if (NULL != m_Root)
    {
        Insert(key, m_Root);
    }
    else
    {
        m_Root = new AbandonNode;
        m_Root->key_value = key;
        m_Root->left = NULL;
        m_Root->right = NULL;
    }
    
    m_nNodeCounts++;
}

AbandonNode* AbandonBinaryTree::Search(int key) const
{
    return Search(key, m_Root);
}

void AbandonBinaryTree::DestroyTree()
{
    DestroyTree(m_Root);
}

void AbandonBinaryTree::Insert(int key, AbandonNode* leafNode)
{
    if (key < leafNode->key_value)
    {
        if (NULL == leafNode->left)
        {
            leafNode->left = new AbandonNode;
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
            leafNode->right = new AbandonNode;
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

AbandonNode* AbandonBinaryTree::Search(int key, AbandonNode* leafNode) const
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

void AbandonBinaryTree::DestroyTree(AbandonNode* leafNode)
{
    if (NULL != leafNode)
    {
        DestroyTree(leafNode->left);
        DestroyTree(leafNode->right);
        delete leafNode;
    }
    //destroy the tree, the size should be return 0
    m_nNodeCounts = 0;
}

AbandonNode* AbandonBinaryTree::GetMinNode() const
{
    if (NULL != m_Root)
    {
        return Min(m_Root);
    }
    
    return NULL;
}

AbandonNode* AbandonBinaryTree::Min(AbandonNode* leafNode) const
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

AbandonNode* AbandonBinaryTree::GetMaxNode() const
{
    if (NULL != m_Root)
    {
        return Max(m_Root);
    }
    
    return  NULL;
}

AbandonNode* AbandonBinaryTree::Max(AbandonNode *leafNode) const
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

int AbandonBinaryTree::GetSize() const
{
    return m_nNodeCounts;
}















