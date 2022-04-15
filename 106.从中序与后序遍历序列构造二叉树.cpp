/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int root_index = in_start;
        while (root_index <= in_end && inorder[root_index] != root->val) ++root_index;
        int left_size = root_index - in_start;
        root->left = buildTree(inorder, in_start, root_index - 1, postorder, post_start, post_start + left_size - 1);
        root->right = buildTree(inorder, root_index + 1, in_end, postorder, post_start + left_size, post_end - 1);
        return root;
    }
};
// @lc code=end

