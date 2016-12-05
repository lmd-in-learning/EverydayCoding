//
//  DirectedCycle.cpp
//  DailyCoding
//
//  Created by limingding on 12/5/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include "DirectedCycle.h"
#include "DirectionGraph.h"

DirectedCycle::DirectedCycle(DirectionGraph& graph)
{
    stack<int>().swap(m_stackCycle);
    
    for (int i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vOnStack.push_back(false);
        m_vEdgeTo.push_back(-1);
    }
    
    for (int i = 0; i < graph.GetVertexesCount(); ++i)
    {
        if (!m_vMarked[i])
        {
            Dfs(graph, i);
        }
    }
}

void DirectedCycle::Dfs(DirectionGraph &graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size());
    m_vOnStack[v] = true;
    m_vMarked[v] = true;
    for (int i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (HasCycle())
        {
            return;
        }
        else if (!m_vMarked[w])
        {
            m_vEdgeTo[w] = v;
            Dfs(graph, w);
        }
        else if (m_vOnStack[v])
        {
            stack<int>().swap(m_stackCycle);
            for (int x = v; x != w; x = m_vEdgeTo[x])
            {
                m_stackCycle.push(x);
            }
            
            m_stackCycle.push(w);
            m_stackCycle.push(v);
        }
    }
    
    m_vOnStack[v] = false;
}

DirectedCycle::~DirectedCycle()
{
    
}

bool DirectedCycle::HasCycle() const
{
    return !m_stackCycle.empty();
}

stack<int> DirectedCycle::Cycle()
{
    return m_stackCycle;
}
