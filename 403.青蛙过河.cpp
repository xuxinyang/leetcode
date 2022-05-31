/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 0) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) {
                    if (dp[i][k - 1] && dp[k][j - 1]) {
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k][j - 1] + stones[k] - stones[i]);
                    }
                }
            }
        }
        return dp[0][n - 1] > 0;
    }
};
// @lc code=end

