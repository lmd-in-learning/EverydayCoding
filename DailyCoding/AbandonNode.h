//
//  Node.h
//  HelloWorld
//
//  Created by limingding on 10/20/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef AbandonNode_h
#define AbandonNode_h

typedef struct AbandonNode
{
    int key_value;
    AbandonNode* left;
    AbandonNode* right;
    int leafnum;//以该点为根的子树种的节点总数
}AbandonNode;
#endif /* Node_h */
