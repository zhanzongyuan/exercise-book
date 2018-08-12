//
//  007_Reverse Integer.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/13.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

//v2.0
class Solution {
public:
    int reverse(int x) {
        long long result=0;
        while(x){
            result=result*10+x%10;
            x=x/10;
        }
        if (result>INT_MAX || result<INT_MIN) return 0;
        return result;
    }
};
/*
 //v1.0
class Solution {
public:
    int reverse(int x) {
        int sign=(x<0)?-1:1;
        x=abs(x);
        int digit[20];
        int len=0;
        int result=0;
        while(x>0){
            digit[len]=x%10;
            x=x/10;
            len++;
        }
        for (int i=len-1; i>=0; i--){
            result+=digit[i]*pow(10, len-i-1);
            //bug1 判断相加超过范围
            if (result<0) {
                result=0;
                break;
            }
        }
        return result*sign;
    }
};
*/
