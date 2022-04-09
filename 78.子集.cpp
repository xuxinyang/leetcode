/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(nums, 0, tmp, res);
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
// @lc code=end

