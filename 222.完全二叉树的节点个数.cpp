/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int l = 0, r = 0;
        TreeNode *l_node = root, *r_node = root;
        while (l_node) {
            l++;
            l_node = l_node->left;
        }
        while (r_node) {
            r++;
            r_node = r_node->right;
        }
        if (l == r) return pow(2, l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

