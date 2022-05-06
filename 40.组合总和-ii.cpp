/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void combinationSum2(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i], i + 1, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

