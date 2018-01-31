class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        sort(nums.begin(), nums.end());
        int max_ = nums[nums.size()-1];
        int min_ = nums[0];
        vector<vector<int>> scores = vector<vector<int>>(max_-min_+1, vector<int>(2, 0));
        for (int i = 0; i < nums.size(); i++) {
            scores[nums[i]-min_][1] += nums[i];
        }
        int sum = 0;
        for (int i = 1; i <= max_-min_; i++) {
            scores[i][0] += max(scores[i-1][0], scores[i-1][1]);
            scores[i][1] += scores[i-1][0];
        }
        return max(scores[max_-min_][0], scores[max_-min_][1]);
    }
};
