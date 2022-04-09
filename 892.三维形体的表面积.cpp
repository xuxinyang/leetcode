/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    res += 2;
                    if (i > 0) res -= min(grid[i][j], grid[i - 1][j]);
                    if (j > 0) res -= min(grid[i][j], grid[i][j - 1]);
                    if (i < n - 1) res -= min(grid[i][j], grid[i + 1][j]);
                    if (j < m - 1) res -= min(grid[i][j], grid[i][j + 1]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

