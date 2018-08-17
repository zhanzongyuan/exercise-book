/**
 * https://leetcode.com/problems/4sum/description/
 */


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int> >();
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > result;
        for (int i = 0; i < nums.size()-3; i++) {
            for (int j = nums.size()-1; j >= i + 3; j--) {                
                int two_target = target - nums[i] - nums[j];
                int l = i + 1, r = j - 1;
                while (l < r) {
                    int sum_t = nums[l] + nums[r];
                    if (two_target > sum_t) l++;
                    else if (two_target < sum_t) r--;
                    else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        temp.push_back(nums[j]);
                        while(l < nums.size() && nums[l] == temp[1]) l++;
                        while(r >= 0 && nums[r] == temp[2]) r--;
                        result.push_back(temp);
                    }
                }
                
                while(j-1 >= i + 3 && nums[j] == nums[j-1]) j--;
            }
            while(i+1 < nums.size()-3 && nums[i] == nums[i+1]) i++;
        }

        return result;
    }
};


