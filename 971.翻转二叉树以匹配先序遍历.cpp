/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        if (!root) return ans;
        if (root->val != voyage[0]) return ans;
        if (root->left && root->left->val != voyage[1]) {
            ans.push_back(root->val);
            ans.push_back(root->left->val);
            root->left = nullptr;
        }
        if (root->right && root->right->val != voyage[2]) {
            ans.push_back(root->val);
            ans.push_back(root->right->val);
            root->right = nullptr;
        }
        if (root->left) {
            vector<int> left = flipMatchVoyage(root->left, vector<int>(voyage.begin()+1, voyage.begin()+3));
            if (left.empty()) return ans;
            ans.insert(ans.end(), left.begin(), left.end());
        }
        if (root->right) {
            vector<int> right = flipMatchVoyage(root->right, vector<int>(voyage.begin()+3, voyage.end()));
            if (right.empty()) return ans;
            ans.insert(ans.end(), right.begin(), right.end());
        }
        return ans;
    }
};
// @lc code=end

