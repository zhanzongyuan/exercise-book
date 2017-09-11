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

// 1.0 v
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
