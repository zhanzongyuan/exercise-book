/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    map<int, int> nodeMap;
    int k;
    bool findTarget(TreeNode* root, int k) {
        nodeMap.clear();
        this->k = k;
        return DFS(root);
    }
    bool DFS(TreeNode* root) {
        if (root == NULL) return false;
        if (nodeMap.find(root->val) == nodeMap.end()) {
            nodeMap.insert(pair<int, int>(root->val, 1));
        }
        else nodeMap[root->val]++;
        int compliment = k - root->val;
        
        if (compliment == root->val
            && nodeMap.find(compliment) != nodeMap.end()
            && nodeMap[compliment] > 1)
            return true;
        else if (compliment != root->val
                 && nodeMap.find(compliment) != nodeMap.end())
            return true;
        
        return DFS(root->left) || DFS(root->right);
    }
};
