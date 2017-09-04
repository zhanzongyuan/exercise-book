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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int temp[3];
        for (int i=0; i<nums.size();i++){
            map<int, int> hash_map;
            map<int, int>::iterator iter;
            
            int target=-nums[i];
            for (int j=0; j<i; j++){
                int com=target-nums[j];
                iter=hash_map.find(com);
                if (iter!=hash_map.end() &&iter->second!=j){
                    temp[0]=nums[j];
                    temp[1]=iter->first;
                    temp[2]=nums[i];
                    //sort temp[3]
                    for (int j=0; j<2; j++){
                        for (int k=j+1; k<3; k++)
                            if (temp[k]<temp[j]){
                                int p=temp[k];
                                temp[k]=temp[j];
                                temp[j]=p;
                            }
                    }
                    if (result.size()==0) result.push_back(vector<int>{temp[0], temp[1], temp[2]});
                    else
                        for (vector<vector<int> >::iterator j=result.begin(); j!=result.end(); j++){
                            //apart from the same
                            if (temp[0]==j->at(0)&&temp[1]==j->at(1)&&temp[2]==j->at(2)) break;
                            //insert in the order
                            if ((temp[0]<j->at(0))
                                ||(temp[0]==j->at(0)&&temp[1]<j->at(1))
                                ||(temp[0]==j->at(0)&&temp[1]==j->at(1)&&temp[2]<j->at(2))){
                                result.insert(j, vector<int>{temp[0], temp[1], temp[2]});
                                break;
                            }
                            if (j+1==result.end())
                                j=result.insert(j+1, vector<int>{temp[0], temp[1], temp[2]});
                            
                        }
                }
                hash_map.insert(pair<int, int>(nums[j], j));
            }
        }
        return result;
    }
};
