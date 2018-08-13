/**
 *
 * 55. Jump Game
 * https://leetcode.com/problems/jump-game/description/
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size(), false);
        reachable[reachable.size()-1] = true;
        int min_reach = reachable.size()-1;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (i+nums[i] >= min_reach) {
                min_reach = i;
                reachable[i] = true;
            }
        }

        return reachable[0];
    }
};

int main() {
    Solution s;
    vector<int> inp = {2,3,1,1,4};
    cout<<s.canJump(inp)<<endl;
    inp = {3,2,1,0,4};
    cout<<s.canJump(inp)<<endl;
    return 0;
}
