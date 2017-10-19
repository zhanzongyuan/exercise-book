//
//  133_Clone_Graph.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/10/19.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    map<int, UndirectedGraphNode*> graphNode;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==NULL) return NULL;
        graphNode[node->label]=new UndirectedGraphNode(node->label);
        DFS(node);
        return graphNode[node->label];
    }
    void DFS(UndirectedGraphNode* node){
        int preLable=node->label;
        for (int i=0; i<node->neighbors.size(); i++){
            int tempLabel=node->neighbors[i]->label;
            if (graphNode.find(tempLabel)==graphNode.end()) {
                graphNode[tempLabel]=new UndirectedGraphNode(tempLabel);
                DFS(node->neighbors[i]);
            }
            graphNode[preLable]->neighbors.push_back(graphNode[tempLabel]);
        }
    }
};
