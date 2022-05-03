/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 */

// @lc code=start
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int m = (int)mat.size();
        const int n = (int)mat[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int ans = 0;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                for (int k=1; k<=min(i, j); ++k) {
                    if (sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] <= threshold) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

