//
//  015_3Sum.cpp
//  
//
//  Created by applecz on 2017/9/4.
//
//
//
//  main.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/4.
//  Copyright © 2017年 applecz. All rights reserved.
//

// v2.0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        //排序
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int i=0;
        while(i<n){
            //网上学来的优化小技巧 可以减少一半的无用搜索
            //if (nums[i]>0) break;
            //但是实际测试却比原来版本的要慢
            
            int target=-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right];
                //从两端向中心搜索的思想，同时向中心移动下标
                if (sum<target){
                    left++;
                }
                else if (sum>target){
                    right--;
                }
                else{
                    vector<int> temp={nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    //消重
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    right--;
                }
            }
            do
                i++;
            while(i<n&&nums[i]==nums[i-1]);
        }
        
        
        return result;
    }
};

/*
// v1.0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        //排序
        int n=nums.size();
        priority_queue<int> q;
        int *sortedNums=new int[nums.size()];
        for(int i=0; i<n; i++){
            q.push(nums[i]);
        }
        for (int i=n-1; i>=0; i--){
            sortedNums[i]=q.top();
            q.pop();
        }
        int i=0;
        while(i<n){
            int target=-sortedNums[i];
            map<int, int> indexMap;
            int j;
            for (j=i+1; j<n; j++) indexMap[sortedNums[j]]=j;
            j=i+1;
            while(j<n){
                int com=target-sortedNums[j];
                map<int, int>::iterator iter=indexMap.find(com);
                if (iter!=indexMap.end()){
                    if (iter->second<=j) break;
                    else{
                        result.push_back(vector<int>{sortedNums[i], sortedNums[j], com});
                        indexMap.erase(com);
                    }
                }
                j++;
                while(j<n&&j+1<n&&sortedNums[j-1]==sortedNums[j]&&sortedNums[j+1]==sortedNums[j]) j++;
            }
            
            while(i+1<n&&sortedNums[i]==sortedNums[i+1]) i++;
            i++;
        }
        
        delete []sortedNums;
        int temp[3];
        //排序
        
        return result;
    }
};
 */
