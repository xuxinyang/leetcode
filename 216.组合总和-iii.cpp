/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(k, n, 1, path, ret);
        return ret;
    }
    void dfs(int k, int n, int start, vector<int>& path, vector<vector<int>>& ret) {
        if (k == 0 && n == 0) {
            ret.push_back(path);
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            dfs(k - 1, n - i, i + 1, path, ret);
            path.pop_back();
        }
    }
};
// @lc code=end

