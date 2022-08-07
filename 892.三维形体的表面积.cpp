/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // 前面的面积
                res += (i - 1) >= 0 ? max(grid[i][j] - grid[i - 1][j], 0) : grid[i][j];
                // 后面的面积
                res += (i + 1) < n ? max(grid[i][j] - grid[i + 1][j], 0) : grid[i][j];
                // 左侧的面积
                res += (j - 1) >= 0 ? max(grid[i][j] - grid[i][j - 1], 0) : grid[i][j];
                // 右侧的面积
                res += (j + 1) < m ? max(grid[i][j] - grid[i][j + 1], 0) : grid[i][j];
                // 上下的面积
                res += 2 * (grid[i][j] > 0 ? 1 : 0);
            }
        }
        return res;
    }
};
// @lc code=end
