//
//  169_Majority Element.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/27.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

//v 2.0
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int m=nums[0];
        for (int i=0; i<nums.size(); i++){
            if (count==0){
                m=nums[i];
                count++;
            }
            else if (nums[i]==m){
                count++;
            }
            else {
                count--;
            }
        }
        return m;
    }
};

/*
//v 1.0
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hashmap;
        for (int i=0; i<nums.size(); i++){
            map<int, int>::iterator iter=hashmap.find(nums[i]);
            if (iter==hashmap.end()){
                hashmap[nums[i]]=0;
            }
            hashmap[nums[i]]++;
            if (hashmap[nums[i]]>(nums.size()/2)) return nums[i];
        }
        return nums[0];
    }
};
 */
