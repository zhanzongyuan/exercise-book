class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        bitset<200*100+1> bSet(1);
        int sum = 0;
        for (auto n:nums) {
            bSet |= bSet << n;
            sum += n;
        }
        return sum%2 == 0 && bSet[sum/2];
    }
   
};
/*
// 66ms
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int target = 0;
        for (int i = 0; i < N; i++) target += nums[i];
        if (target % 2 != 0) return false;
        else target /= 2;
        vector<vector<bool>> dp = vector<vector<bool>>(N, vector<bool>(target+1, false));
        for (int i = 0; i < N; i++) dp[i][0] = true;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= target; j++) {
                if (j - nums[i] == 0) dp[i][j] = true;
                else if (j - nums[i] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i]]);
            }
            if (dp[i][target]) return true;
        }
        return false;
    }
};
*/
