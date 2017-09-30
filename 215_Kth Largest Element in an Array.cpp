//
//  215_Kth Largest Element in an Array.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/30.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int begin=0, end=nums.size();
        while(begin<end){
            int pivot=partition(nums, begin, end);
            if (k-1==pivot){
                return nums[pivot];
            }
            else if (k-1<pivot){
                end=pivot;
            }
            else {
                begin=pivot+1;
            }
        }
        return nums[begin];
    }
    int partition(vector<int> &nums, int begin, int end){
        int pivot=nums[begin];
        while(begin<end){
            while(begin<end&&nums[--end]<=pivot);
            nums[begin]=nums[end];
            while(begin<end&&nums[++begin]>=pivot);
            nums[end]=nums[begin];
        }
        nums[begin]=pivot;
        return begin;
    }
};
