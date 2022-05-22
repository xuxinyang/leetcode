/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int left = findSecondMinimumValue(root->left);
        int right = findSecondMinimumValue(root->right);
        if (left == -1) {
            return right == -1 ? root->val : min(root->val, right);
        }
        if (right == -1) {
            return min(root->val, left);
        }
        return min(min(root->val, left), right);
    }
};
// @lc code=end

