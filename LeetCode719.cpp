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

        int begin = 0;
        int end = nums.back()-nums[0];
        int count = 0;
        while (begin < end) {
            int min = (begin+end)/2;
            count = 0;
            // count[min] mean counting the pair that (nums[j] - nums[i] < min)
            for (int i = 0, j = 0; i < nums.size(); i++) {
                while(j < nums.size() && nums[j] - nums[i] <= min) j++;
                count += j-i-1;
            }
            if (count >= k) {
                end = min;
            }
            else {
                begin = min+1;
            }
        }

        return end;
    }
};


