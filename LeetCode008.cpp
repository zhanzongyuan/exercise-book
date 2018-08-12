//
//  008_string to integer.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/9/18.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int myAtoi(string str) {
        int n=str.size();
        int j=0;
        int sign=1;
        long long sum=0;
        //跳过空格
        while (str[j]==' '&&j<n) j++;
        //排除特殊符号
        if (j==n||(str[j]!='+'&&str[j]!='-'&&(str[j]<'0'||str[j]>'9'))){
            return 0;
        }
        //转换sign
        if (str[j]=='-') {
            sign=-1;
            j++;
        }
        else if (str[j]=='+') j++;
        //再次判别符号后的非数字符号
        if (j==n||(str[j]<'0'||str[j]>'9')){
            return 0;
        }
        while(j<n){
            if (str[j]<'0'||str[j]>'9') return sum;
            sum=sum*10+(str[j]-'0')*sign;
            if (sum<INT_MIN) return INT_MIN;
            if (sum>INT_MAX) return INT_MAX;
            j++;
        }
        return sum;
        
    }
};
