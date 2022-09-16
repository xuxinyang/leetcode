/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(preorder, 0, preorder.size()-1);
    }
    TreeNode* fun(vector<int> &preorder, int left, int right) {
        if (left > right) return nullptr;
        int root = preorder[left];
        int mid = left;
        for (; mid <= right; mid++) {
            if (preorder[mid] > root) break;
        }
        TreeNode* node = new TreeNode(root);
        node -> left = fun(preorder, left + 1, mid - 1);
        node -> right = fun(preorder, mid, right);
        return node;
    }
};
// @lc code=end

