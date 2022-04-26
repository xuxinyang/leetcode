/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int max_row = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) {
                    ans++;
                }
                max_row = max(max_row, grid[i][j]);
            }
            ans += max_row;
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            int max_col = 0;
            for (int i = 0; i < grid.size(); ++i) {
                max_col = max(max_col, grid[i][j]);
            }
            ans += max_col;
        }
        return ans;
    }
};
// @lc code=end

