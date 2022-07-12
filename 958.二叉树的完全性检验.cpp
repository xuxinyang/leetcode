/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (flag) return false;
                q.push(node->left);
            } else {
                flag = true;
            }
            if (node->right) {
                if (flag) return false;
                q.push(node->right);
            } else {
                flag = true;
            }
        }
        return true;
    }
};
// @lc code=end

