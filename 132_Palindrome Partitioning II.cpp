//
//  132_Palindrome Partitioning II.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/28.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n<2) return 0;
        vector<vector<bool>> isP(n, vector<bool>(n, false));
        vector<int> minCut(n, INT_MAX-1);
        minCut[0] = 0;
        for (int i = 0; i < n; i++) isP[i][i] = true;
        
        for (int j = 0; j < n; j++) {
            if (j != 0) minCut[j] = min(minCut[j], minCut[j-1]+1);
            for (int i = j-1; i >= 0; i--) {
                if (s[i] == s[j] && (j-i == 1 || isP[i+1][j-1])) {
                    isP[i][j] = true;
                    int pre = i-1 >= 0 ? minCut[i-1] : -1;
                    minCut[j] = min(minCut[j], pre+1);
                }
            }
        }
        
        return minCut[n-1];
    }
};
