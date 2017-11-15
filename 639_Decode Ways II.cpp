//
//  639_Decode Way II.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/15.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    long long MY_INT_MAX=pow(10, 9)+7;
    long long numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        vector<long long> decoding(n+1);
        decoding[0]=1;
        if (s[0]=='0') decoding[1]=0;
        else if (s[0]=='*') decoding[1]=9;
        else decoding[1]=1;
        for (int i=2; i<=n; i++){
            decoding[i]=0;
            if (s[i-1]!='*'){
                if (s[i-1]!='0') decoding[i]=decoding[i-1];
                if ((s[i-2]=='1')||(s[i-1]>='0'&&s[i-1]<='6'&&s[i-2]=='2')){
                    decoding[i]=(decoding[i]+decoding[i-2])%MY_INT_MAX;
                }
                else if (s[i-2]=='*'&&s[i-1]<='6'&&s[i-1]>='0'){
                    decoding[i]=(decoding[i]+decoding[i-2]*2)%MY_INT_MAX;
                }
                else if (s[i-2]=='*'){
                    decoding[i]=(decoding[i]+decoding[i-2])%MY_INT_MAX;
                }
            }
            if (s[i-1]=='*'){
                decoding[i]=(9*decoding[i-1])%MY_INT_MAX;
                if (s[i-2]=='1')
                    decoding[i]=(decoding[i]+decoding[i-2]*9)%MY_INT_MAX;
                else if (s[i-2]=='2')
                    decoding[i]=(decoding[i]+decoding[i-2]*6)%MY_INT_MAX;
                else if (s[i-2]=='*')
                    decoding[i]=(decoding[i]+decoding[i-2]*(15))%MY_INT_MAX;
                
            }
        }
        return decoding[n];
    }
};
