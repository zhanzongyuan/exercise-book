/**
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 */
 

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int unsort_min = INT_MAX;
        int unsort_max = INT_MIN;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                if (unsort_min > nums[i+1]) unsort_min = nums[i+1];
                if (unsort_max < nums[i]) unsort_max = nums[i];
            }
        }
        if (unsort_min == INT_MAX && unsort_max == INT_MIN) return 0;
        
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > unsort_min) {
                l = i;
                break;
            }
        }
        int r = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < unsort_max) {
                r = i;
                break;
            }
        }
        return r-l+1;
    }
};
