//
//  DepthFirstOrder.cpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include "DepthFirstOrder.h"
#include "DirectionGraph.h"

DepthFirstOrder::DepthFirstOrder(DirectionGraph& graph)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
    }
    
    for (int v = 0; v < graph.GetVertexesCount(); ++v)
    {
        if (!m_vMarked[v])
        {
            Dfs(graph, v);
        }
    }
}

void DepthFirstOrder::Dfs(DirectionGraph &graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    m_queuePre.push(v);
    
    m_vMarked[v] = true;
    for (int i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            Dfs(graph, w);
        }
    }
    
    m_queuePost.push(v);
    m_stackReversePost.push(v);
}

queue<int> DepthFirstOrder::Pre()
{
    return m_queuePre;
}

queue<int> DepthFirstOrder::Post()
{
    return m_queuePost;
}

stack<int> DepthFirstOrder::ReversePost()
{
    return m_stackReversePost;
}
