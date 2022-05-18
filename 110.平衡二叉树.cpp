/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (abs(left-right) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left, right) + 1;
    }
};
// @lc code=end

