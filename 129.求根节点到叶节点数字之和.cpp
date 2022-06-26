/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode* root, int cur, int& sum) {
        if (!root) {
            return;
        }
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            sum += cur;
            return;
        }
        dfs(root->left, cur, sum);
        dfs(root->right, cur, sum);
    }
};
// @lc code=end

