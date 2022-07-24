/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
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
    int getNum(TreeNode* root)
    {
        if (!root) return 0;
        int l = getNum(root -> left);
        int r = getNum(root -> right);
        return l + r + 1;
    }
    bool helper(TreeNode* root, int n, int x) {
        if (!root) return false;
        if (root -> val == x) 
        {
            int l = getNum(root -> left);
            int r = getNum(root -> right);
            int other = n - l - r - 1;
            if (other > l + r + 1 || l > other + r + 1 || r > other + l + 1)
                return true;
        }
        return helper(root -> left, n, x) || helper(root -> right, n, x); 
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x)
    {
        return helper(root, n, x);
    }
};
// @lc code=end

