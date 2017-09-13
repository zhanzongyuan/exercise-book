//
//  006_ZigZag Conversion.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/13.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    string convert(string s, int numRows) {
        //bug1 zigzag
        //bug2 s="AB" 1
        //应对特殊情况
        if (numRows==1) return s;
        
        int p=(numRows-1)*2;
        string result="";
        for (int i=0; i<numRows; i++){
            int d2=i*2;
            int d1=p-i*2;
            //当numRows为1，p=d1=d2=0，导致bug
            int j=i;
            while(j<s.size()){
                result+=s[j];
                j+=d1;
                if (d1==0) j+=d2;
                if (j<s.size()){
                    result+=s[j];
                    j+=d2;
                    if (d2==0) j+=d1;
                }
                else break;
            }
            
        }
        return result;
    }
};
