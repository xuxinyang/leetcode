/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int dp[n];
        dp[0] = 0;
        int minn = prices[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], prices[i] - minn);
            minn = min(minn, prices[i]);
        }
        int maxn = prices[n - 1];
        int res = 0;
        for (int i = n - 2; i >= 0; i--) {
            res = max(res, maxn - prices[i]);
            maxn = max(maxn, prices[i]);
        }
        return max(res, dp[n - 1]);
    }
};
// @lc code=end

