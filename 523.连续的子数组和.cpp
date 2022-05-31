/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return false;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (k == 0) {
                    if (dp[j] - dp[i] == 0) return true;
                } else {
                    if ((dp[j] - dp[i]) % k == 0) return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

