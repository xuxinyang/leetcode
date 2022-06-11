/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        // 去重
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
    void dfs(vector<int>& nums, int pos, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() >= 2) ans.push_back(cur);
        for (int i = pos; i < nums.size(); ++i) {
            if (cur.empty() || nums[i] >= cur.back()) {
                cur.push_back(nums[i]);
                dfs(nums, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end

