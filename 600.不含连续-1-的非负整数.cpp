/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        int m = __lg(n), dp[m + 1][2];
        memset(dp, -1, sizeof(dp));
        function<int(int, bool, bool)> f = [&](int i, bool pre1, bool is_limit) -> int {
            if (i < 0) return 1;
            if (!is_limit && dp[i][pre1] >= 0) return dp[i][pre1];
            int up = is_limit ? n >> i & 1 : 1;
            int res = f(i - 1, false, is_limit && up == 0); // 填 0
            if (!pre1 && up == 1) res += f(i - 1, true, is_limit); // 填 1
            if (!is_limit) dp[i][pre1] = res;
            return res;
        };
        return f(m, false, true); // i 从 m 往小枚举，方便位运算
    }
};

// @lc code=end

