class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> mOrder = vector<vector<int>>(N, vector<int>(N, 0));
        int maxOrder = 0;
        map<int, int> hashMap;
        for (int i = 0; i < mines.size(); i++)
            hashMap.insert(pair<int, int>(mines[i][0]*N+mines[i][1], 1));
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (hashMap.find(i*N+j) != hashMap.end()) count = 0;
                else count++;
                mOrder[i][j] = count;
            }
            count = 0;
            for (int j = N-1; j >= 0; j--) {
                if (hashMap.find(i*N+j) != hashMap.end()) count = 0;
                else count++;
                mOrder[i][j] = min(mOrder[i][j], count);
            }
        }
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (hashMap.find(j*N+i) != hashMap.end()) count = 0;
                else count++;
                mOrder[j][i] = min(mOrder[j][i], count);
            }
            count = 0;
            for (int j = N-1; j >= 0; j--) {
                if (hashMap.find(j*N+i) != hashMap.end()) count = 0;
                else count++;
                mOrder[j][i] = min(mOrder[j][i], count);
                maxOrder = max(maxOrder, mOrder[j][i]);
            }
        }
        return maxOrder;
    }
};
