/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
// @lc code=end

