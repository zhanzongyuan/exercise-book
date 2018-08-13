/**
 *
 * 45. Jump Game II
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int pace = 0;
        int begin = 0;
        int end = nums[begin];
        if (end >= nums.size()-1) return 1;
        while (begin < nums.size()-1) {
            int max_ind = end+nums[end];
            for (int j = begin+1; j <= end && j < nums.size()-1; j++) {
                if (max_ind < nums[j] + j) {
                    max_ind = nums[j] + j;
                }
            }
            pace++;
            begin = end;
            end = max_ind;
        }
        return pace;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1};
    cout<<s.jump(nums)<<endl;
    return 0;
}
