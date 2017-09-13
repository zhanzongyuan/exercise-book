//
//  main.cpp
//  two_sum
//
//  Created by applecz on 2017/9/3.
//  Copyright © 2017年 applecz. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

//v4.0

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash_map;
        map<int, int>::iterator iter;
        
        for (int i=0; i<nums.size(); i++){
            int com=target-nums[i];
            iter=hash_map.find(com);
            if (iter!=hash_map.end()){
                return vector<int>{iter->second, i};
            }
            hash_map.insert(pair<int, int>(nums[i], i));
        }
        throw new invalid_argument("No two sum sol.");
        
    }
};



/*
 //v3.0
 class Solution {
 public:
 vector<int> twoSum(vector<int>& nums, int target) {
 map<int, int> hash_map;
 map<int, int>::iterator iter;
 
 for (int i=0; i<nums.size(); i++){
 hash_map.insert(pair<int, int>(nums[i], i));
 }
 for (int i=0; i<nums.size(); i++){
 int com=target-nums[i];
 iter=hash_map.find(com);
 if (iter!=hash_map.end() && iter->second!=i){
 vector<int> temp;
 temp.push_back(i);
 temp.push_back(iter->second);
 return temp;
 }
 }
 throw new invalid_argument("No two sum sol.");
 
 }
 };
 */


/*
 //v2.0
 class Solution {
 public:
 vector<int> twoSum(vector<int>& nums, int target) {
 for (int i=0; i<nums.size()-1; i++){
 for (int j=i+1; j<nums.size(); j++){
 if (nums[i]+nums[j]==target){
 vector<int> result;
 result.push_back(i);
 result.push_back(j);
 return result;
 }
 }
 }
 throw new invalid_argument("No two sum sol.");
 }
 };
 */


/*
 //v1.0
 class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i=0; i<nums.size()-1; i++){
            for (int j=i+1; j<nums.size(); j++){
                if (nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
 }
 };*/





