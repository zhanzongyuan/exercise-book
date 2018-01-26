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
    int findSecondMinimumValue(TreeNode* root) {
        if (root->left != NULL) {
            int left = root->left->val;
            int right = root->right->val;
            if (left == root->val) {
                left = findSecondMinimumValue(root->left);
                if (left == root->val) left = -1;
            }
            if (right == root->val) {
                right = findSecondMinimumValue(root->right);
                if (right == root->val) right = -1;
            }
            if (left == -1) return right;
            if (right == -1) return left;
            return left < right ? left : right;
        }
        else {
            return -1;
        }
    }
};
