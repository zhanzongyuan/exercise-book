//
//  010_Regular Expression Matching.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/25.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

//v 2.0 DP 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * dp[i+1,j+1]: s[0:i] matchs p[0:j]
         * dp[i+1,j+1]== (p[j]!='*'&&((p[j]=='.'||p[j]==s[i])&&dp[i,j]))
         *           && (p[j]=='*' &&(
         *           dp[i+1, j-1]                                      //x* repeat 0 times
         *           || ((p[j-1]=='.'||p[j-1]==s[i])&&dp[i, j+1]))   //x* repeat >=1 times
         *
         * !!!对i=0 or j=0 的dp[i][j]特殊处理
         * i==0 && j==0: true
         * i==0 && j+1<>0: dp[0][j+1]=p[j]=='*'&&dp[0][j-1]
         */
        
        int n=s.length(), m=p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0]=true;
        for(int j=1; j<m; j++){
            dp[0][j+1]=p[j]=='*'&&dp[0][j-1];
        }
        for(int i=1; i<n; i++){
            dp[i][0]=false;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (p[j]!='*'){
                    dp[i+1][j+1]=(p[j]=='.'||p[j]==s[i])&&dp[i][j];
                }
                else{
                    dp[i+1][j+1]=dp[i+1][j-1]||((p[j-1]=='.'||p[j-1]==s[i])&&dp[i][j+1]);
                }
            }
        }
        return dp[n][m];
    }
};
/*
//v 1.0 Recursion
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size()==0) {
            return s.size()==0;
        }
        bool first_match=s.size()!=0&&(s[0]==p[0]||p[0]=='.');
        if (p.size()>=2&&p[1]=='*'){
            return isMatch(s, p.substr(2)) || (first_match&&isMatch(s.substr(1), p));
        }
        else {
            return first_match&&isMatch(s.substr(1), p.substr(1));
        }
    }
};
*/
/*
// wrong version
class Solution {
public:
    //bug: aaa ab*a*c*a
    //bug: 指向结尾时出错
    //bug: a .*..a*
    bool isMatch(string s, string p) {
        int sStack=s.length()-1;
        int pStack=p.length()-1;
        int star=-1;
        while(sStack>=0||pStack>=0){
            if (pStack<0) return false;
            char pTop=p[pStack];
            pStack--;
            if (pTop=='*'){
                int mark=0;
                while(sStack>=0&&(p[pStack]==s[sStack]||p[pStack]=='.')){
                    sStack--;
                    mark=1;
                }
                //要当前有匹配才能更新star
                if (mark==1) star=sStack+1;
                pStack--;
            }
            else{
                //对'.'特殊情况处理
                if (pTop=='.'){
                    if (sStack>=0){
                        pTop=s[sStack];
                    }
                    else if (star!=-1){
                        pTop=s[star];
                    }
                }
                if (sStack<0||s[sStack]!=pTop) {
                    //判断前面相邻处是否出现过a*类的
                    if (star!=-1){
                        if (s[star]==pTop){
                            star++;
                            //离开前面连续相同的子串
                            if (star>=s.length()||s[star]!=s[star-1]) star=-1;
                        }
                        else return false;
                    }
                    else return false;
                }
                //当成功匹配是star为-1，消除前面‘*’的记录
                else star=-1;
                sStack--;
            }
            
        }
        return true;
    }
};
*/
