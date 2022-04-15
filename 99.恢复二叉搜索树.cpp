/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* next = cur->left;
                while (next->right && next->right != cur) {
                    next = next->right;
                }
                if (!next->right) {
                    next->right = cur;
                    cur = cur->left;
                } else {
                    if (prev && prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                        }
                        second = cur;
                    }
                    prev = cur;
                    next->right = nullptr;
                    cur = cur->right;
                }
            } else {
                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                    }
                    second = cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
// @lc code=end

