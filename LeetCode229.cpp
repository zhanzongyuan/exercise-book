/**
 * https://leetcode.com/problems/majority-element-ii/description/
 * https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        int can1 = 0;
        int can2 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (can1 == nums[i]) count1++;
            else if (can2 == nums[i]) count2++;
            else if (count1 == 0) {
                can1 = nums[i];
                count1++;
            }
            else if (count2 == 0) {
                can2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] == can1) count1++;
            else if (nums[i] == can2) count2++;
        }
        vector<int> result;
        if (count1 > nums.size()/3) result.push_back(can1);
        if (count2 > nums.size()/3) result.push_back(can2);
        return result;
    }
};
