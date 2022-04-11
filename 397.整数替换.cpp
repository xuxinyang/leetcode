/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == INT_MAX) return 32;
        if (n == INT_MIN) return 32;
        if (n % 2 == 0) return 1 + integerReplacement(n / 2);
        return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
    }
};
// @lc code=end

