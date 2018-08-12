//
//  004_Median of Two Sorted Arrays.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/6.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0, j=0;
        int min=(n+m)/2+1;
        int iter=0;
        int buff1=0, buff2=0;
        while(iter<min){
            if (i>=nums1.size()||(j<nums2.size()&&nums1[i]>nums2[j])){
                buff1=buff2;
                buff2=nums2[j];
                j++;
                iter++;
                continue;
            }
            if (j>=nums2.size()||(i<nums1.size()&&nums1[i]<=nums2[j])){
                buff1=buff2;
                buff2=nums1[i];
                i++;
                iter++;
                continue;
            }
            
        }
        double medium;
        if ((m+n)%2==0){
            medium=(buff1+buff2)/2.0;
        }
        else medium=buff2;
        return medium;
    }
};
