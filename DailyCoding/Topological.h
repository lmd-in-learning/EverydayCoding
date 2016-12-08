//
//  Topological.hpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Topological_h
#define Topological_h

#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>

using std::stack;
using std::queue;
using std::vector;

class DirectionGraph;

class Topological
{
    //constructor
public:
    Topological(DirectionGraph& graph);
    ~Topological();
    
    //public functions
public:
    //return true if group is directed graph without loop
    bool IsDAG() const;
    
    //java 有Iterable<Integer>，此处不太适用，故分别写出来
    //拓扑有序的前序顶点，在递归调用之前将顶点加入队列
    queue<int> Pre();
    
    //拓扑有序的后序顶点，在递归调用之后将顶点加入队列
    queue<int> Post();
    
    //拓扑有序的逆后序顶点，在递归调用之后将顶点压入栈
    stack<int> ReversePost();
    
    //private members
private:
    queue<int> m_queuePre;
    
    queue<int> m_queuePost;
    
    stack<int> m_stackReversePost;
    
};

#endif /* Topological_h */
