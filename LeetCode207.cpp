//
//  207_Course Schedule.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/10/27.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> nodeGraph[numCourses];
        int *nodeLevel=new int[numCourses];
        memset(nodeLevel, 0, sizeof(int)*numCourses);
        for (int i=0; i<prerequisites.size(); i++){
            nodeGraph[prerequisites[i].first].push_back(prerequisites[i].second);
            nodeLevel[prerequisites[i].second]++;
        }
        bool update=false;
        int nLeft=numCourses;
        do{
            //find nodeLevel[i]==0; update;
            update=false;
            for (int i=0; i<numCourses; i++){
                if (nodeLevel[i]==0){
                    update=true;
                    nodeLevel[i]--;
                    nLeft--;
                    for (int j=0; j<nodeGraph[i].size(); j++){
                        if (nodeLevel[nodeGraph[i][j]]!=-1){
                            nodeLevel[nodeGraph[i][j]]--;
                        }
                    }
                }
            }
        }while(update);
        delete []nodeLevel;
        return nLeft==0;
    }
};
