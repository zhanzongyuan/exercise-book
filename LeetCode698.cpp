
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = int(nums.size());
        if (k > N) return false;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }
        if (sum % k != 0) return false;
        int sP = sum/k;
        for (int i = N-1; i >= 0; i--)
            if (nums[i] > sP) return false;
            else break;
        
        vector<bool> boolArr = vector<bool>((1 << N), false);
        vector<int> sumArr = vector<int>((1 << N), 0);
        
        boolArr[0] = true;
        for (int state = 0; state < (1 << N); state++) {
            if (!boolArr[state]) continue;
            for (int i = 0; i < N; i++) {
                int nextState = state | (1 << i);
                if (nextState != state && !boolArr[nextState]) {
                    if (nums[i] <= (sP - (sumArr[state] % sP))) {
                        boolArr[nextState] = true;
                        sumArr[nextState] = sumArr[state]+nums[i];
                    }
                    else break;  // 'break' because the array is in order.
                }
                
            }
        }
        
        return boolArr[(1<<N)-1];
    }
};
