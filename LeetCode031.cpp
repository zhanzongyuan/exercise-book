/**
 * https://leetcode.com/problems/next-permutation/description/
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int begin_ind = 0;
        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                begin_ind = i;
                int min_greater_ind = nums.size()-1;
                for (int j = i; j < nums.size(); j++) {
                    if (nums[j] <= nums[i-1]) {
                        min_greater_ind = j-1;
                        break;
                    }
                }
                swap(nums[min_greater_ind], nums[i-1]);
                break;
            }
        }
        reverse(nums.begin()+begin_ind, nums.end());

    }
};


