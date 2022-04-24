/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        vector<vector<int>> f(n, vector<int>(n, 0));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
            {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};
// @lc code=end

