/**
 * 152. Maximum Product Subarray
 * https://leetcode.com/problems/maximum-product-subarray/description/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prod_mat(nums.size(), 0); 
        prod_mat[0] = nums[0];
        int max_prod = prod_mat[0];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (j == i) prod_mat[j] = nums[j];
                else prod_mat[j] = prod_mat[j-1]*nums[j];
                if (max_prod < prod_mat[j]) max_prod = prod_mat[j];
            }
        }
        return max_prod;
    }
};

int main() {
    Solution s;
    vector<int> input = {2,3,-2,4};
    cout<<s.maxProduct(input)<<endl;

    input = {-2,0,-1};
    cout<<s.maxProduct(input)<<endl;

    input = {-1};
    cout<<s.maxProduct(input)<<endl;
    return 0;
}
