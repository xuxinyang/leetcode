/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<long long, int> prefix;
    int dfs(TreeNode *root, long long curr, int targetSum)
    {
        if (!root) return 0;
        int ret = 0;
        curr += root -> val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr-targetSum];
        }
        prefix[curr]++;
        ret += dfs(root -> left, curr, targetSum);
        ret += dfs(root -> right, curr, targetSum);
        prefix[curr]--;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
// @lc code=end

