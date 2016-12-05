//
//  DirectedDFS.cpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include "DirectedDFS.h"
#include "DirectionGraph.h"

DirectedDFS::DirectedDFS(DirectionGraph& graph, int s)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
    }
    Dfs(graph, s);
}

DirectedDFS::DirectedDFS(DirectionGraph& graph, vector<int> vSources)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
    }
    
    for (size_t i = 0; i < vSources.size(); ++i)
    {
        if (!m_vMarked[vSources[i]])
        {
            Dfs(graph, vSources[i]);
        }
    }
}

void DirectedDFS::Dfs(DirectionGraph &graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    
    m_vMarked[v] = true;
    for (int i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            Dfs(graph, w);
        }
    }
}

bool DirectedDFS::Marked(int v) const
{
    assert(v >= 0 && v < m_vMarked.size());
    return m_vMarked[v];
}
