/**
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < nums.size()-1; i++) {
            int j = i+1;    
            q.push(abs(nums[i]-nums[j]));
        }
        int result;
        return q.top();
    }
};


