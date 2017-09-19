//
//  009_Palindrome Number.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/19.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
/*
// v2.0
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int sum=0, y = x;
        //回文比较方法，反向后比较
        while(x>0)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return y == sum;
    }
};
*/
class Solution {
public:
    bool isPalindrome(int x) {
        //bug1 忘了考虑负数 x=INT_MIN=-2147483648 无法abs
        
        if (x<0) return false;
        if (x<10) return true;
        int temp=x;
        int k=0;
        while (temp!=0) {
            temp/=10;
            k++;
        }
        k=pow(10,k-1);
        while(x/k==x%10){
            x%=k;
            k/=100;
            x/=10;
            //bug2 100021 验证中间变成只有一位的数字 不可用x<10判定
            //bug3 k==0 不可k==1
            if (k<=1) return true;
        }
        return false;
    }
};
