/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        int minn = prices[0];
        for (int i = 1; i < n; ++i) {
            minn = min(minn, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minn);
        }
        return dp[n - 1];
    }
};
// @lc code=end

