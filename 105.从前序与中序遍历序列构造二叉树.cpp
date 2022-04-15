/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int root_index = in_start;
        while (root_index <= in_end && inorder[root_index] != root->val) ++root_index;
        int left_size = root_index - in_start;
        root->left = buildTree(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, root_index - 1);
        root->right = buildTree(preorder, pre_start + left_size + 1, pre_end, inorder, root_index + 1, in_end);
        return root;
    }
};
// @lc code=end

