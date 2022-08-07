/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
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
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        int tarN = (n + 1) / 2;
        vector<vector<TreeNode *>> dp(tarN + 1, vector<TreeNode *>());
        dp[1].emplace_back(new TreeNode());
        for (int i = 2; i <= tarN; ++i)
        {
            for (int j = 1; j < i; ++j)
            {

                for (auto leftSub : dp[j])
                {
                    for (auto rightSub : dp[i - j])
                    {
                        TreeNode *root = new TreeNode();
                        root->left = leftSub;
                        root->right = rightSub;
                        dp[i].emplace_back(root);
                    }
                }
            }
        }
        return dp[tarN];
    }
};
// @lc code=end
