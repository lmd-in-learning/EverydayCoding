//
//  Connect.hpp
//  DailyCoding
//
//  Created by limingding on 11/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Connect_h
#define Connect_h

#include <stdio.h>
#include <vector>

using std::vector;

class Graph;

class Connect
{
    //constructor
public:
    Connect(Graph& graph);
    virtual ~Connect();
    
    //public functions
public:
    //return true if v and w were connected
    bool Connected(int v, int w);
    
    //the connected nums
    int Count() const;
    
    //the v's connected mark (0 ~ Count() - 1)
    int Id(int v);
    
    //private functions
private:
    void Dfs(Graph& graph, int v);
    
    //private members
private:
    vector<bool> m_vMarked;
    
    vector<int> m_vIds;
    
    int m_nCount;
};

#endif /* Connect_h */
