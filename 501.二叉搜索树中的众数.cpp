/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        unordered_map<int, int> m;
        dfs(root, m);
        int max_cnt = 0;
        for (auto& p : m) {
            if (p.second > max_cnt) {
                max_cnt = p.second;
                ans.clear();
                ans.push_back(p.first);
            } else if (p.second == max_cnt) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
private:
    void dfs(TreeNode* root, unordered_map<int, int>& m) {
        if (!root) {
            return;
        }
        m[root->val]++;
        dfs(root->left, m);
        dfs(root->right, m);
    }

};
// @lc code=end

