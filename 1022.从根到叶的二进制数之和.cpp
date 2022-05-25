/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int cur, int& res) {
        if (!root) return;
        cur = cur * 2 + root->val;
        if (!root->left && !root->right) {
            res += cur;
            return;
        }
        dfs(root->left, cur, res);
        dfs(root->right, cur, res);
    }
};
// @lc code=end

