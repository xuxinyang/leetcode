/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int max_index = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = construct(nums, left, max_index - 1);
        root->right = construct(nums, max_index + 1, right);
        return root;
    }
};
// @lc code=end

