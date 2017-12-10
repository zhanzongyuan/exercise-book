//
//  494_Target Sum.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/10.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) maxLen += nums[i];
        if (maxLen < S) return 0;
        int m = maxLen*2+1;
        vector<vector<int>> method2tar(2, vector<int>(m, 0));
        int pre_arr = 1, now_arr = 0;
        method2tar[pre_arr][maxLen] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int n_index = j-nums[i];
                int p_index = j+nums[i];
                int n_method = 0, p_method = 0;
                if (n_index >= 0 && n_index < m) n_method = method2tar[pre_arr][n_index];
                if (p_index >= 0 && p_index < m) p_method = method2tar[pre_arr][p_index];
                method2tar[now_arr][j] = p_method + n_method;
            }
            int temp = pre_arr;
            pre_arr = now_arr;
            now_arr = temp;
        }
        return method2tar[pre_arr][maxLen+S];
    }
};
