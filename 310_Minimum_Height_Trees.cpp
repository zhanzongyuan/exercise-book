//
//  310_Minimum_Height_Trees.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/10/16.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
private:
    vector<int> *node;
    vector<int> result;
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        node=new vector<int>[n];
        int *nodeEdges=new int[n];
        bool *nodeMarkNoLeaf=new bool[n];
        bool *nodeDeleted=new bool[n];
        memset(nodeDeleted, 0, sizeof(bool)*n);
        memset(nodeEdges, 0, sizeof(int)*n);
        for(int i=0; i<edges.size(); i++){
            node[edges[i].first].push_back(edges[i].second);
            node[edges[i].second].push_back(edges[i].first);
            nodeEdges[edges[i].first]++;
            nodeEdges[edges[i].second]++;
        }
        int nodeLeft=n;
        while(1){
            if (nodeLeft<3){
                for (int i=0; i<n; i++)
                    if (nodeDeleted[i]==0) result.push_back(i);
                break;
            }
            memset(nodeMarkNoLeaf, 0, sizeof(bool)*n);
            for (int i=0; i<n; i++){
                if (nodeEdges[i]==1&&nodeMarkNoLeaf[i]==0){
                    nodeEdges[i]=0;
                    for (int j=0;j<node[i].size();j++){
                        nodeEdges[node[i][j]]--;
                        nodeMarkNoLeaf[node[i][j]]=1;
                    }
                    nodeLeft--;
                    nodeDeleted[i]=1;
                }
            }
        }
        delete []node;
        delete []nodeEdges;
        delete []nodeDeleted;
        return result;
    }
};
