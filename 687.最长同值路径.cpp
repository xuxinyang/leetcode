/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
private:
	int dfs(TreeNode* root, int& result) {
		if (!root->left && !root->right) {
			return 0;
		}
		int left = 0;
		if (root->left) {
			if (root->val == root->left->val) {
				left = dfs(root->left, result) + 1;
			}
			else {
				dfs(root->left, result);
			}
		}
		int right = 0;
		if (root->right) {
			if (root->val == root->right->val) {
				right = dfs(root->right, result) + 1;
			}
			else {
				dfs(root->right, result);
			}
		}
		if (result < left + right) {
			result = left + right;
		}
		if (left >= right) {
			return left;
		}
		return right;
	}
public:
	int longestUnivaluePath(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int result = 0;
		dfs(root, result);
		return result;
	}
};
// @lc code=end

