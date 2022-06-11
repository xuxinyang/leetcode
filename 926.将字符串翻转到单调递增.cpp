/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') dp0New++;
            else dp1New++;
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};
// @lc code=end

