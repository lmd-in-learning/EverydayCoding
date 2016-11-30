//
//  DirectionGraph.cpp
//  DailyCoding
//
//  Created by limingding on 11/30/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "DirectionGraph.h"

DirectionGraph::DirectionGraph(int nVertexes):
m_nVertexesNum(nVertexes),
m_nEdges(0)
{
    //used for init the adjacent table
    for (int i = 0; i < nVertexes; ++i)
    {
        vector<int> initV;
        m_VAdjacent.push_back(initV);
    }
}

DirectionGraph::~DirectionGraph()
{
    
}

DirectionGraph::DirectionGraph(const DirectionGraph& graph)
{
    m_nEdges = graph.m_nEdges;
    m_nVertexesNum = graph.m_nVertexesNum;
    m_VAdjacent.assign(graph.m_VAdjacent.begin(), graph.m_VAdjacent.end());
}

DirectionGraph& DirectionGraph::operator=(const DirectionGraph &graph)
{
    m_nEdges = graph.m_nEdges;
    m_nVertexesNum = graph.m_nVertexesNum;
    m_VAdjacent.assign(graph.m_VAdjacent.begin(), graph.m_VAdjacent.end());
    return *this;
}

int DirectionGraph::GetVertexesCount()
{
    return m_nVertexesNum;
}

int DirectionGraph::GetEdgesCount()
{
    return m_nEdges;
}

void DirectionGraph::AddEdge(int v, int w)
{
    assert(v >= 0 && v < m_VAdjacent.size());
    assert(w >= 0 && w < m_VAdjacent.size());
    m_VAdjacent[v].push_back(w);
    m_nEdges++;
}

vector<int> DirectionGraph::Adjacent(int v)
{
    assert(v >=0 && v < m_VAdjacent.size());
    return m_VAdjacent[v];
}

DirectionGraph DirectionGraph::Reverse()
{
    DirectionGraph reverseGraph(m_nVertexesNum);
    for (int v = 0; v < m_nVertexesNum; ++v)
    {
        for (int i = 0; i < m_VAdjacent[v].size(); ++i)
        {
            int w = m_VAdjacent[v][i];
            reverseGraph.AddEdge(w, v);
        }
    }
    return reverseGraph;
}







