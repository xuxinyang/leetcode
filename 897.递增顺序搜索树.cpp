/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* head = nullptr;
        while (cur) {
            if (!cur->left) {
                if (!head) {
                    head = cur;
                }
                if (prev) {
                    prev->right = cur->right;
                    cur->left = nullptr;
                    cur->right = nullptr;
                    prev = cur;
                } else {
                    prev = cur;
                }
                cur = cur->right;
            } else {
                TreeNode* tmp = cur->left;
                while (tmp->right && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    tmp->right = nullptr;
                    if (!head) {
                        head = cur;
                    }
                    if (prev) {
                        prev->right = cur->right;
                        cur->left = nullptr;
                        cur->right = nullptr;
                        prev = cur;
                    } else {
                        prev = cur;
                    }
                    cur = cur->right;
                }
            }
        }
        return head;
    }
};
// @lc code=end

