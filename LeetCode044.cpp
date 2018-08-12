//
//  44_Wildcard Matching.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/10.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> boolMap(n+1, vector<bool>(m+1, false));
        boolMap[0][0]=true;
        for (int i=1; i<=m; i++){
            if (p[i-1]=='*'){
                boolMap[0][i]=boolMap[0][i-1];
            }
        }
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (p[j-1]=='*'){
                    boolMap[i][j]=boolMap[i-1][j]||boolMap[i][j-1];
                }
                else if (p[j-1]=='?'){
                    boolMap[i][j]=boolMap[i-1][j-1];
                }
                else if (p[j-1]==s[i-1]){
                    boolMap[i][j]=boolMap[i-1][j-1];
                }
            }
        }
        return boolMap[n][m];
    }
};
