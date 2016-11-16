//
//  Paths.hpp
//  DailyCoding
//
//  Created by limingding on 11/16/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Paths_h
#define Paths_h

#include <stdio.h>
#include <vector>

using std::vector;
class Graph;

class Paths
{
    
public:
    Paths(Graph graph, int s);
    
    virtual ~Paths();
    
    //return true if s and v are connected
    virtual bool HasPathTo(int v) = 0;
    
    //return the edges between s and v
    virtual vector<int> PathTo(int v) = 0;
};
#endif /* Paths_h */
