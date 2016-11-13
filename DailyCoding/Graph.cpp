//
//  Graph.cpp
//  DailyCoding
//
//  Created by limingding on 10/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "Graph.h"
#include <stdlib.h>
#include <assert.h>

Graph::Graph(int nVertexes):
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

Graph::~Graph()
{
    
}

int Graph::GetVertexesCount()
{
    return m_nVertexesNum;
}

int Graph::GetEdgesCount()
{
    return m_nEdges;
}

void Graph::AddEdge(int v, int w)
{
    assert(v >= 0 && v < m_VAdjacent.size());
    assert(w >= 0 && w < m_VAdjacent.size());
    m_VAdjacent[v].push_back(w);
    m_VAdjacent[w].push_back(v);
}

vector<int> Graph::Adjacent(int v)
{
    assert(v >=0 && v < m_VAdjacent.size());
    return m_VAdjacent[v];
}
