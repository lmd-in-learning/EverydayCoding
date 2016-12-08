//
//  DepthFirstOrder.hpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef DepthFirstOrder_h
#define DepthFirstOrder_h

#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>

using std::stack;
using std::queue;
using std::vector;

class DirectionGraph;

class DepthFirstOrder
{
    //constructor
public:
    DepthFirstOrder(DirectionGraph& graph);
    ~DepthFirstOrder();
    
    //public functions
public:
    //拓扑有序的前序顶点，在递归调用之前将顶点加入队列
    queue<int> Pre();
    
    //拓扑有序的后序顶点，在递归调用之后将顶点加入队列
    queue<int> Post();
    
    //拓扑有序的逆后序顶点，在递归调用之后将顶点压入栈
    stack<int> ReversePost();
    
    //private functions
private:
    void Dfs(DirectionGraph& graph, int v);
    
    //private members
private:
    vector<bool> m_vMarked;
    
    queue<int> m_queuePre;
    
    queue<int> m_queuePost;
    
    stack<int> m_stackReversePost;
};

#endif /* DepthFirstOrder_h */
