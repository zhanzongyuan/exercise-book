//
//  741_Cherry Pickup.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/11.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = 0;
        int maxLen = 2*(n-1);
        for (int k = 0; k <= maxLen; k++) {
            int maxt = min(k, n-1);
            for (int x1 = maxt; x1 >= 0; x1--)
                for (int x2 = maxt; x2 >= 0; x2--) {
                    int y1 = k - x1;
                    int y2 = k - x2;
                    if (y1 > n || y2 > n) continue;
                    if (grid[x1][y1] < 0 || grid[x2][y2] < 0) {
                        dp[x1][x2] = -1;
                        continue;
                    }
                    int cherry = grid[x1][y1] + grid[x2][y2];
                    if (x1-1 >= 0) dp[x1][x2] = max(dp[x1][x2], dp[x1-1][x2]);
                    if (x2-1 >= 0) dp[x1][x2] = max(dp[x1][x2], dp[x1][x2-1]);
                    if (x1-1 >= 0 && x2-1 >= 0) dp[x1][x2] = max(dp[x1][x2], dp[x1-1][x2-1]);
                    
                    if (dp[x1][x2] == -1) continue;
                    if (x1 != x2) dp[x1][x2] += cherry;
                    else dp[x1][x2] += grid[x1][y1];
                    
                }
        }
        return dp[n-1][n-1] > 0 ?  dp[n-1][n-1] : 0;
    }
};
