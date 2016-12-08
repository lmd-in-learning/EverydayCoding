//
//  Topological.cpp
//  DailyCoding
//
//  Created by limingding on 12/8/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#include "Topological.h"
#include "DirectionGraph.h"
#include "DepthFirstOrder.h"
#include "DirectedCycle.h"

Topological::Topological(DirectionGraph& graph)
{
    DirectedCycle* pCyclefinder = new DirectedCycle(graph);
    if (!pCyclefinder->HasCycle())
    {
        DepthFirstOrder* pDfs = new DepthFirstOrder(graph);
        
        m_queuePre         = pDfs->Pre();
        m_queuePost        = pDfs->Post();
        m_stackReversePost = pDfs->ReversePost();
    }
}

Topological::~Topological()
{
    
}

bool Topological::IsDAG() const
{
    //数据不为空
    return (!m_queuePre.empty() &&
            !m_queuePost.empty() &&
            !m_stackReversePost.empty());
}
