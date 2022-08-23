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
    int i = 0; //记录当前访问的结点的索引
    vector<int> res;
    bool DFS(TreeNode* root, vector<int>& voyage) {
        //如果树为空，肯定匹配
        if (!root) {
            return true;
        } 
        if (root->val!=voyage[i]) { //如果访问的结点和数组中对应值不相等，肯定不匹配
            return false;
        }
        i++; //索引++

        //如果当前结点匹配，那就要去判断左右子树是否匹配(先左后右)
        if (DFS(root->left, voyage) && DFS(root->right, voyage)) {
            return true;
        }
        if (DFS(root->right, voyage) && DFS(root->left, voyage)) {
            res.push_back(root->val);
            return true;
        }
        return false;
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        //匹配成功，返回res
        if(DFS(root, voyage)) {
            return res;
        }
        //匹配失败，返回-1
        res.erase(res.begin(),res.end());
        res.push_back(-1);
        return res;
    }
};
// @lc code=end

