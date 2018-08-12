//
//  652_Find Duplicate Subtrees.cpp
//  leetcodeTest
//
//  Created by applecz on 2017/12/18.
//  Copyright © 2017年 applecz. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    vector<TreeNode*> duplicate_list;
    map<string, int> hash_map;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        DFS(root);
        return duplicate_list;
    }
    string DFS(TreeNode* root) {
        if (root == NULL) return "#";
        string str_id = char(root->val) + DFS(root->left) + DFS(root->right);
        if (hash_map.find(str_id) == hash_map.end()) hash_map.insert(pair<string, int>(str_id, 1));
        else {
            hash_map.find(str_id)->second++;
            if (hash_map.find(str_id)->second == 2) duplicate_list.push_back(root);
        }
        return str_id;
    }
};
