//
//  32_Longest Valid Parentheses.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/10/28.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    //stack
    int longestValidParentheses1(string s) {
        stack<int> invalidPos;
        invalidPos.push(-1);
        int maxLen=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='(') {
                int len=i-invalidPos.top()-1;
                maxLen=maxLen<len?len:maxLen;
                invalidPos.push(i);
            }
            else if (s[i]==')'){
                if (!invalidPos.empty()&&s[invalidPos.top()]=='(') invalidPos.pop();
                else {
                    int len=i-invalidPos.top()-1;
                    maxLen=maxLen<len?len:maxLen;
                    invalidPos.push(i);
                }
            }
        }
        
        int len=s.size()-invalidPos.top()-1;
        maxLen=maxLen<len?len:maxLen;
        return maxLen;
    }
    //DP
    int longestValidParentheses2(string s) {
        int maxLen=0;
        int n=s.size();
        vector<int> longestLen(n, 0);
        for (int i=0; i<n; i++){
            if (s[i]==')'){
                //take it as (...)((..))
                if (i-1>=0&&i-1-longestLen[i-1]>=0&&s[i-1-longestLen[i-1]]=='('){
                    longestLen[i]+=2+longestLen[i-1];
                    if (i-longestLen[i]>=0) longestLen[i]+=longestLen[i-longestLen[i]];
                }
            }
            if (maxLen<longestLen[i]) maxLen=longestLen[i];
        }
        return maxLen;
    }
};
