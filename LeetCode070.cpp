//
//  70_Climbing Stairs.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/11.
//  Copyright © 2017年 applecz. All rights reserved.
//
// log(n) method
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a[2][2];
        matpow(a, n);
        return a[0][0];
    }
    void matpow(int (&a)[2][2], int n) {
        a[0][0] = 1;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        if (n == 0) return;
        int E[2][2] = {{1, 1}, {1, 0}};
        if (n&1) matmul(a, E);
        while((n = n>>1) > 0) {
            matmul(E, E);
            if (n&1) {
                matmul(a, E);
            }
        }
    }
    void matmul(int (&a)[2][2], int b[2][2]) {
        int temp[2][2];
        
        temp[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0];
        temp[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1];
        temp[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0];
        temp[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1];
        
        a[0][0] = temp[0][0];
        a[0][1] = temp[0][1];
        a[1][0] = temp[1][0];
        a[1][1] = temp[1][1];
    }
};
/*
// DP method
#include <stdio.h>
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> ways(n+1, 0);
        ways[0] = ways[1] = 1;
        for (int i = 2; i <= n; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n];
    }
};
 */
