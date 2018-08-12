//
//  174_Dungeon Game.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/3.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N=dungeon.size();
        int M=0;
        if (N!=0) M=dungeon[0].size();
        else return 1;
        vector<vector<int>> minHP(N+1, vector<int>(M+1, INT_MAX));
        minHP[N][M-1]=minHP[N-1][M]=1;
        for (int i=N-1; i>=0; i--){
            for (int j=M-1; j>=0; j--){
                int nextMin=min(minHP[i+1][j], minHP[i][j+1])-dungeon[i][j];
                if (nextMin<1) minHP[i][j]=1;
                else minHP[i][j]=nextMin;
            }
        }
        return minHP[0][0];
    }
};
