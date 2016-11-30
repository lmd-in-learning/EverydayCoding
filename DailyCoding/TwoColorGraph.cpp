//
//  TwoColorGraph.cpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include "TwoColorGraph.h"
#include "Graph.h"

TwoColorGraph::TwoColorGraph(Graph& graph)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vColor.push_back(false);
    }
}

TwoColorGraph::~TwoColorGraph()
{
    
}

void TwoColorGraph::Dfs(Graph& graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    m_vMarked[v] = true;
    
    for (size_t i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            m_vColor[w] = !m_vColor[v];
            Dfs(graph, w);
        }
        else if (m_vColor[w] == m_vColor[v])
        {
            m_bIsTwoColorable = false;
        }
    }
}

bool TwoColorGraph::IsBinaryPartities() const
{
    return m_bIsTwoColorable;
}
