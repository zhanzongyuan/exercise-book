//
//  669_Trim a Binary Search Tree.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/15.
//  Copyright © 2017年 applecz. All rights reserved.
//
//这道题不能释放内存，否则会报错
#include <stdio.h>
class Solution {
public:
    int minV, maxV;
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        minV = L;
        maxV = R;
        return DFS(root);
    }
    TreeNode* DFS(TreeNode* root) {
        if (root==NULL) return NULL;
        cout<<root->val<<endl;
        if (root->val < minV) {
            //deleteTree(root->left);
            TreeNode* right = root->right;
            //delete root;
            return DFS(right);
        }
        if (root->val > maxV) {
            //deleteTree(root->right);
            TreeNode* left = root->left;
            //delete root;
            return DFS(left);
        }
        root->left = DFS(root->left);
        root->right = DFS(root->right);
        return root;
    }
    void deleteTree(TreeNode* root) {
        if (root == NULL) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
