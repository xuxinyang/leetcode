/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void combinationSum(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }
            path.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

