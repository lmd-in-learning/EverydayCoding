//
//  Graph.h
//  DailyCoding
//
//  Created by limingding on 10/29/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

class Graph {
    
public:
    //<#member functions#>
    Graph(int nPointNum);
    
    ~Graph();
    
    int GetPointNum();
    
    int GetEdgesNum();
    
    void AddEdge(int nPointNum, int nEdgeNum);
    
private:
    //<#instance variables#>
};

#endif /* Graph_h */
