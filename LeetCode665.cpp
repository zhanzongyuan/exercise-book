
/**
 * 665. Non-decreasing Array
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 * 
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int dec_num = 0;
	    for (int i = 1; i < nums.size(); i++) {
	        if (nums[i] < nums[i-1]) {
    	        dec_num++;
		        if (dec_num > 1) return false;
		        int forward = i-2 >= 0 ? nums[i-2] : 0;
		        int back = i+1 < nums.size() ? nums[i+1] : 10001;
		        if (!(forward <= nums[i] || nums[i-1] <= back)) return false;
	        }
	    }
	    return true;
    }
};

int main() {
    vector<int> test = {4,2,1};
    Solution s;
    cout<<s.checkPossibility(test)<<endl;
    return 0;
}
