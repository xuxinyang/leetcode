/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }
        vector<int> cur;
        dfs(nums, cur, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end()) {
                continue;
            }
            cur.push_back(nums[i]);
            dfs(nums, cur, res);
            cur.pop_back();
        }
    }
};
// @lc code=end

