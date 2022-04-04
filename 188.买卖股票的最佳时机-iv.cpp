/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        if (k >= n / 2)
        {
            int res = 0;
            for (int i = 1; i < n; ++i)
            {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        vector<int> dp(k + 1, 0);
        for (int i = 1; i <= k; ++i)
        {
            int tmp = dp[i - 1] - prices[0];
            for (int j = 1; j < n; ++j)
            {
                tmp = max(tmp, dp[i - 1] - prices[j]);
                dp[i] = max(dp[i], prices[j] + tmp);
            }
        }
        return dp[k];
    }
};
// @lc code=end

