//
//  662_Maximum Width of Binary Tree.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/21.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    int max;
    int level[10000];
    int widthOfBinaryTree(TreeNode* root) {
        memset(level, 0, sizeof(level));
        level[0] = 1;
        DFS(root, 1, 0);
        return max;
    }
    void DFS(TreeNode* root, int count, int h) {
        if (root == NULL) return;
        if (level[h] == 0) level[h] = count;
        else {
            int width = count - level[h]+1;
            if (max < width) max = width;
        }
        DFS(root->left, count*2, h+1);
        DFS(root->right, count*2+1, h+1);
    }
    
};
