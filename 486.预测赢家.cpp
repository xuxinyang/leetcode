/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[k] + (k == i ? 0 : dp[i][k - 1]) + (k == j ? 0 : dp[k + 1][j]));
                }
            }
        }
        return dp[0][n - 1] >= dp[1][n - 1] * 2;
    }
};
// @lc code=end

