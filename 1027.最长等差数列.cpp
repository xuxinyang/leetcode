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
        // dp[i][d]表示以数组下标i处的元素结尾,公差为d的等差数列的最大长度
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = dp[j][d] + 1;
                ans = max(ans, dp[i][d]);
            }
        }
        return ans+1;
    }
};
// @lc code=end

