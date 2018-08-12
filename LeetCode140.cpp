//
//  140_Word Break II.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/11/30.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    vector<vector<int>> isBreak;
    vector<string> result;
    string myS;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        isBreak = vector<vector<int>>(n+1, vector<int>());
        isBreak[n].push_back(n);
        
        sort(wordDict.begin(), wordDict.end());
        
        int minLen = INT_MAX, maxLen = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            if (wordDict[i].size() > maxLen) maxLen = wordDict[i].size();
            if (wordDict[i].size() < minLen) minLen = wordDict[i].size();
        }
        
        for (int i = n-1; i>=0; i--) {
            int minP = i+minLen;
            int maxP = i+maxLen;
            if (minP <= n) {
                for (int j = minP-1; j<n && j<maxP; j++) {
                    if (isBreak[j+1].size() != 0 && isInDict(s.substr(i, j-i+1), wordDict)) {
                        isBreak[i].push_back(j+1);
                    }
                }
            }
        }
        
        myS = s;
        dfsAddResult(0, "");
        return result;
    }
    void dfsAddResult(int pos, string tempS) {
        if (pos == isBreak.size()-1) {
            result.push_back(tempS);
            return;
        }
        string splitS = " ";
        if (pos == 0) splitS = "";
        for (int i = isBreak[pos].size()-1; i >= 0; i--) {
            dfsAddResult(isBreak[pos][i], tempS+splitS+myS.substr(pos, isBreak[pos][i]-pos));
        }
    }
    bool isInDict(string word, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            if (word == wordDict[i]) return true;
            else if (word < wordDict[i]) return false;
        }
        return false;
    }
};
