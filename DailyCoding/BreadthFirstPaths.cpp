//
//  BreadthFirstPaths.cpp
//  DailyCoding
//
//  Created by limingding on 11/23/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "BreadthFirstPaths.h"
#include "Graph.h"
#include <assert.h>
#include <queue>
using std::queue;

BreadthFirstPaths::BreadthFirstPaths(Graph& graph, int s):Paths(graph, s)
,m_nS(s)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vEdgeTo.push_back(-1);
    }
    
    Bfs(graph, s);
}

BreadthFirstPaths::~BreadthFirstPaths()
{
    
}

bool BreadthFirstPaths::HasPathTo(int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    return m_vMarked[v];
}

vector<int> BreadthFirstPaths::PathTo(int v)
{
    assert(v >= 0 && v < m_vEdgeTo.size());
    vector<int> paths;
    for (int x = v; x != m_nS; x = m_vEdgeTo[x])
    {
        paths.push_back(x);
    }
    paths.push_back(m_nS);
    
    return paths;
}

void BreadthFirstPaths::Bfs(Graph& graph, int s)
{
    assert(s >= 0 && s < m_vMarked.size());
    queue<int> edgeQueue;
    m_vMarked[s] = true;
    edgeQueue.push(s);
    
    while (!edgeQueue.empty())
    {
        int v = edgeQueue.front();
        edgeQueue.pop();
        for (size_t i = 0; i < graph.Adjacent(v).size(); ++i)
        {
            int w = graph.Adjacent(v)[i];
            if (!m_vMarked[w])
            {
                m_vEdgeTo[w] = v;
                m_vMarked[w] = true;
                edgeQueue.push(w);
            }
        }
    }
}















