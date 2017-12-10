//
//  198_House Robber.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/10.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        vector<vector<int>> max_rob(n, vector<int>(2, 0));
        max_rob[0][0] = 0;
        max_rob[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            max_rob[i][0] = max(max_rob[i-1][0], max_rob[i-1][1]);
            max_rob[i][1] = max_rob[i-1][0]+nums[i];
        }
        return max(max_rob[n-1][0], max_rob[n-1][1]);
    }
};

