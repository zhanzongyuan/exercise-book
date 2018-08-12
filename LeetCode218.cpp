//
//  218_The Skyline Problem.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/10/1.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        queue<vector<pair<int, int>>> myq;
        for (int i=0; i<buildings.size(); i++){
            vector<pair<int, int>> temp;
            temp.push_back(pair<int, int>(buildings[i][0], buildings[i][2]));
            temp.push_back(pair<int, int>(buildings[i][1], 0));
            myq.push(temp);
        }
        while(myq.size()>1){
            vector<pair<int, int>> skyline1, skyline2;
            skyline1=myq.front();
            myq.pop();
            skyline2=myq.front();
            myq.pop();
            int h1=0, h2=0;
            vector<pair<int, int>> newskyline;
            int iter1=0, iter2=0;
            int len1=skyline1.size(), len2=skyline2.size();
            while(iter1<len1 && iter2<len2){
                if (skyline1[iter1].first<skyline2[iter2].first){
                    h1=skyline1[iter1].second;
                    int maxh=max(h1, h2);
                    if (newskyline.empty()||maxh!=newskyline.back().second)
                        newskyline.push_back(pair<int, int>(skyline1[iter1].first, maxh));
                    iter1++;
                }
                else if (skyline1[iter1].first>skyline2[iter2].first){
                    h2=skyline2[iter2].second;
                    int maxh=max(h1, h2);
                    if (newskyline.empty()||maxh!=newskyline.back().second)
                        newskyline.push_back(pair<int, int>(skyline2[iter2].first, maxh));
                    iter2++;
                }
                else {
                    h1=skyline1[iter1].second;
                    h2=skyline2[iter2].second;
                    int maxh=max(h1, h2);
                    if (newskyline.empty()||maxh!=newskyline.back().second)
                        newskyline.push_back(pair<int, int>(skyline2[iter2].first, maxh));
                    iter2++;
                    iter1++;
                }
            }
            while(iter1<len1) {
                if (newskyline.empty()||skyline1[iter1].second!=newskyline.back().second)
                    newskyline.push_back(skyline1[iter1++]);
                else iter1++;
            }
            while(iter2<len2){
                if (newskyline.empty()||skyline2[iter2].second!=newskyline.back().second)
                    newskyline.push_back(skyline2[iter2++]);
                else iter2++;
            }
            myq.push(newskyline);
        }
        return myq.front();
    }
};
