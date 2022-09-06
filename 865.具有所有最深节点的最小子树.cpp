/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = getMaxDepth(root);
        return dfs(root, 1, maxDepth);
    }
    int getMaxDepth(TreeNode *root) {
        if (!root) return 0;
        int left = getMaxDepth(root -> left);
        int right = getMaxDepth(root -> right);
        return max(left, right) + 1;
    }
    TreeNode *dfs(TreeNode *root, int curDepth, int maxDepth) {
        if (!root) return nullptr;
        if (curDepth == maxDepth) {
            return root;
        }
        TreeNode *left = dfs(root -> left, curDepth + 1, maxDepth);
        TreeNode *right = dfs(root -> right, curDepth + 1, maxDepth);
        if (left == nullptr && right == nullptr) return nullptr;
        else if (left == nullptr && right) return right;
        else if (left && right == nullptr) return left;
        return root;
    }
};
// @lc code=end

