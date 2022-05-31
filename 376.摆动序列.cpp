/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
        vector<int> up(n + 1, 0);
        vector<int> down(n + 1, 0);
        up[1] = dp[1];
        down[1] = dp[1];
        for (int i = 2; i <= n; ++i) {
            up[i] = max(up[i - 1], dp[i] - down[i - 1]);
            down[i] = max(down[i - 1], dp[i] - up[i - 1]);
        }
        return max(up[n], down[n]);
    }
};
// @lc code=end

