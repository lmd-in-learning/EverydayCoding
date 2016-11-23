//
//  DepthFirstPaths.cpp
//  DailyCoding
//
//  Created by limingding on 11/16/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "DepthFirstPaths.h"
#include "Graph.h"
#include <assert.h>

DepthFirstPaths::DepthFirstPaths(Graph graph, int s):Paths(graph, s)
,m_nS(s)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vEdgeTo.push_back(-1);
    }
    
    Dfs(graph, s);
}

DepthFirstPaths::~DepthFirstPaths()
{
    
}

bool DepthFirstPaths::HasPathTo(int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    return m_vMarked[v];
}

vector<int> DepthFirstPaths::PathTo(int v)
{
    vector<int> path;
    if (!HasPathTo(v))
    {
        return path;
    }
    
    for (int x = v; x != m_nS; x = m_vEdgeTo[x])
    {
        path.push_back(x);
    }
    
    path.push_back(m_nS);
    return path;
}

void DepthFirstPaths::Dfs(Graph graph, int v)
{
    m_vMarked[v] = true;
    
    for (size_t i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            m_vEdgeTo[w] = v;
            Dfs(graph, w);
        }
    }
}
