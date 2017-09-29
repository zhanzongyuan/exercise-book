//
//  53_Maximum Subarray.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/27.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN;
        int front=0;
        for (int i=0; i<nums.size(); i++){
            if (front+nums[i]>=nums[i]){
                front=nums[i]+front;
            }
            else {
                front=nums[i];
            }
            
            if (max<front){
                max=front;
            }
        }
        return max;
    }
};
