
//
//  SolidConnectionDirectionGraph.cpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <assert.h>
#include <stack>
#include "SolidConnectionDirectionGraph.h"
#include "DirectionGraph.h"
#include "DepthFirstOrder.h"

using std::stack;

SolidConnectionDirectionGraph::SolidConnectionDirectionGraph(DirectionGraph& graph):
m_nCount(0)
{
    for (size_t i = 0; i < graph.GetVertexesCount(); ++i)
    {
        m_vMarked.push_back(false);
        m_vIds.push_back(-1);
    }
    
    DepthFirstOrder* pOrder = new DepthFirstOrder(graph);
    
    stack<int> stackReversePost = pOrder->ReversePost();
    while(!stackReversePost.empty())
    {
        int s = stackReversePost.top();
        if (!m_vMarked[s])
        {
            Dfs(graph, s);
        }
        stackReversePost.pop();
    }
    
}

void SolidConnectionDirectionGraph::Dfs(DirectionGraph &graph, int v)
{
    assert(v >= 0 && v < m_vMarked.size() && v < m_vIds.size());
    m_vMarked[v] = true;
    m_vIds[v] = m_nCount;
    for (int i = 0; i < graph.Adjacent(v).size(); ++i)
    {
        int w = graph.Adjacent(v)[i];
        if (!m_vMarked[w])
        {
            Dfs(graph, w);
        }
    }

}

bool SolidConnectionDirectionGraph::StronglyConnected(int v, int w) const
{
    assert(v >= 0 && v < m_vIds.size());
    return m_vIds[v] == m_vIds[w];
}

int SolidConnectionDirectionGraph::Id(int v) const
{
    assert(v >= 0 && v < m_vIds.size());
    return m_vIds[v];
}

int SolidConnectionDirectionGraph::Count() const
{
    return m_nCount;
}







