//
//  Connect.cpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//
#include <assert.h>
#include "Connect.h"
#include "Graph.h"

Connect::Connect(Graph& graph):
m_nCount(0)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vIds.push_back(-1);
    }
    
    for (int s = 0; s < graph.GetVertexesCount(); ++s)
    {
        if (!m_vMarked[s])
        {
            Dfs(graph, s);
        }
    }
}

Connect::~Connect()
{
    
}

void Connect::Dfs(Graph &graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    assert(v >= 0 && v < m_vIds.size());
    
    m_vMarked[v] = true;
    m_vIds[v] = m_nCount;
    for (size_t i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            Dfs(graph, w);
        }
    }
}

bool Connect::Connected(int v, int w)
{
    assert(v >= 0 && v < m_vIds.size());
    assert(w >= 0 && w < m_vIds.size());
    return m_vIds[v] == m_vIds[w];
}

int Connect::Id(int v)
{
    assert(v >= 0 && v < m_vIds.size());
    return m_vIds[v];
}

int Connect::Count() const
{
    return m_nCount;
}














