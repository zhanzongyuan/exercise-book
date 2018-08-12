//
//  091_Decode Ways.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/15.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<int> decoding(n+1);
        decoding[0]=1;
        if (s[0]=='0') decoding[1]=0;
        else decoding[1]=1;
        for (int i=2; i<=n; i++){
            decoding[i]=0;
            if (s[i-1]!='0')
                decoding[i]+=decoding[i-1];
            if ((s[i-2]=='1')||(s[i-1]>='0'&&s[i-1]<='6'&&s[i-2]=='2')){
                decoding[i]+=decoding[i-2];
            }
        }
        return decoding[n];
    }
};
