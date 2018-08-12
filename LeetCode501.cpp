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
    int maxFq;
    vector<int> result;
    map<int, int> hashMap;
    vector<int> findMode(TreeNode* root) {
        result = vector<int>();
        hashMap = map<int, int>();
        maxFq = 0;
        countNum(root);
        return result;
    }
    void countNum(TreeNode* root) {
        if (root == NULL) return;
        if (hashMap.find(root->val) == hashMap.end()) {
            hashMap.insert(pair<int, int>(root->val, 1));
        }
        else {
            hashMap[root->val]++;
        }
        int num = hashMap[root->val];
        if (num == maxFq) {
            result.push_back(root->val);
        }
        else if (num > maxFq) {
            maxFq = num;
            result.clear();
            result.push_back(root->val);
        }
        countNum(root->right);
        countNum(root->left);
    }
        
};
