//
//  303_Range Sum Query-Immutable.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/10.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class NumArray {
public:
    vector<int> nums_sum;
    NumArray(vector<int> nums) {
        int n = nums.size();
        nums_sum = vector<int>(n+1, 0);
        nums_sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            nums_sum[i] = nums[i-1]+nums_sum[i-1];
        }
        
    }
    
    int sumRange(int i, int j) {
        return nums_sum[j+1]-nums_sum[i];
    }
};
