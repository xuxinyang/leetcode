/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (!root) {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre != -1) {
            ans = min(ans, root->val - pre);
        }
        pre = root->val;
        dfs(root->right, pre, ans);
    }

};
// @lc code=end

