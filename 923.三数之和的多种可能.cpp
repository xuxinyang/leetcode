/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int> &arr, int target)
    {
        // dp[i][j][k]表示考虑前i个数时候,从中选出j个数,组成k大小的方案数
        int len = arr.size();
        int dp[len + 5][4][target + 5];
        memset(dp, 0, sizeof(dp));
        // 初始化,从前i个数中选0个数,和为0的方案数都是1
        for (int i = 0; i < len; i++)
            dp[i][0][0] = 1;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 0; k <= target; k++)
                {
                    if (k >= arr[i - 1])
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - arr[i - 1]]) % mod;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k]) % mod;
                }
            }
        }
        return dp[len][3][target];
    }
};
// @lc code=end
