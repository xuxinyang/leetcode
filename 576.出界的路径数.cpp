/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        dp[startRow][startColumn][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= maxMove; ++k) {
                    if (i > 0) {
                        dp[i][j][k] += dp[i - 1][j][k];
                    }
                    if (j > 0) {
                        dp[i][j][k] += dp[i][j - 1][k];
                    }
                    if (i < m - 1) {
                        dp[i][j][k] += dp[i + 1][j][k];
                    }
                    if (j < n - 1) {
                        dp[i][j][k] += dp[i][j + 1][k];
                    }
                    dp[i][j][k] %= mod;
                }
            }
        }
        return dp[m - 1][n - 1][maxMove];
    }
};
// @lc code=end

