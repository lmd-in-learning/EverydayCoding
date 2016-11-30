//
//  CycleGraph.cpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include "CycleGraph.h"
#include "Graph.h"

CycleGraph::CycleGraph(Graph& graph)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
    }
    for (int s = 0; s < graph.GetVertexesCount(); ++s)
    {
        if (!m_vMarked[s])
        {
            Dfs(graph, s, s);
        }
    }
}

CycleGraph::~CycleGraph()
{
    
}

void CycleGraph::Dfs(Graph &graph, int v, int u)
{
    m_vMarked[v] = true;
    for (size_t i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            Dfs(graph, w, v);
        }
        else if(w != u)
        {
            m_bHasCycle = true;
        }
    }
}

bool CycleGraph::HasCycle() const
{
    return m_bHasCycle;
}
