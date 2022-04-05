/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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

