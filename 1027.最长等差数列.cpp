/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(1001, 0));
        int ans = 0;
        for (int k = 1; k < n; k++)
        {
            for (int j = 0; j < k; j++)
            {
                int d = nums[k] - nums[j] + 500;
                dp[k][d] = dp[j][d] + 1;
                ans = max(ans, dp[k][d]);
            }
        }
        return ans+1;
    }
};
// @lc code=end

